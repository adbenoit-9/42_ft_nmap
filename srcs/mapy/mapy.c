/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:57:21 by adbenoit          #+#    #+#             */
/*   Updated: 2022/08/25 18:48:07 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapy.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <signal.h>
#include "nmap_mapy_data.h"
#include <pthread.h>

#define DEBUG
#define DEBUG

#define EXEY_ERR	-1
#define EXEY_OK		0
#define EXEY_IDLE	1
#define EXEY_BUSY	2
#define EXEY_RUN	3

int				exey_check_blkhdr(t_exe *exe, t_blk *blk)
{
	int			r = EXEY_OK;

	if (!exe || !blk) {
		r = EXEY_ERR;
	}
	else if (blk->id == exe->id) {
		r = EXEY_OK;
	}
	else if (blk->id == 0x00000000) {
		r = EXEY_OK;
		blk->id = exe->id;
	}
	else {
		r = EXEY_BUSY;
	}
	return (r);
}

int				exey_wrapper(t_root *root, t_st *st, t_nd *nd, t_rd *rd, int index)
{
	int			r			= EXEY_OK;
	int			i			= 0;

	i = 0;
	/* Find the 1st task to do */
	while (i < EXEC_LST_SIZE && ((rd->exe.tasks[i] & EXEC_TODO_MSK) == 0)) {
		++i;
	}
	if (i == EXEC_LST_SIZE)
	{
		/* Nothing to do, exit */
		r = EXEY_IDLE;
		if (((t_blk*)&root->map[index])->id == rd->exe.id)
		{ /* Release the blk */
			//((t_blk*)&root->map[index])->id = 0x00000000;
			memset(&root->map[index + sizeof(pthread_mutex_t)], 0, MAP_BLCK_SIZE - sizeof(pthread_mutex_t));
//			fprintf(stdout, "%s:%d block release \n", __func__, __LINE__); // id
		}
#ifdef DEBUG
//		fprintf(stderr, "%s:%d IDLE \n", __func__, __LINE__); // id
#endif /* DEBUG */
	}
	if (r == EXEY_OK)
	{

		r = exey_check_blkhdr(&rd->exe, (t_blk*)&root->map[index]);
		/* Check value */
		if (rd->exe.tasks[i] > EXEC_MAX_CMD - 1 ||
				rd->exe.hook[i] > EXEC_MAX_HOOK - 1) {
			r = EXEY_ERR;
		}
	}
	if (r == EXEY_OK) {
		/* Clear exec flag */
		rd->exe.tasks[i] &= ~EXEC_TODO_MSK;
		r = (*_exec[rd->exe.tasks[i]]
				[(st->client.sock.ss_family == AF_INET6 ? 2 : 0) + (rd->client.tcpflag == 0)])
				(&root->map[index + sizeof(t_blk)], &st->client,
				&nd->client, &rd->client);
		r = EXEY_RUN;
	}
	return (r);
}

int			mapy(t_root *root)
{
	int			r = EXEY_RUN;
	bool		b = 0;
	uint64_t	count;
	uint64_t	index;
	
	if (!root) {
		r = MAPY_ERR;
	}
	while (r == EXEY_RUN || r == EXEY_BUSY)
	{
		b = 0;
		count = 0;
		for (int i = 0; (r == EXEY_RUN  || r == EXEY_BUSY) && i < root->st_nb; i++) {
			for (int j = 0; (r == EXEY_RUN  || r == EXEY_BUSY) && j < root->nd_nb; j++) {
				for (int k = 0; (r == EXEY_RUN  || r == EXEY_BUSY) && k < root->rd_nb; k++, count++) {
//		fprintf(stderr, "%s:%d i=%d j=%d k=%d st_nb=%d nd_nb=%d rd_nb=%d\n", __func__, __LINE__, i, j, k, root->st_nb, root->nd_nb, root->rd_nb);
					index = (count % BLCK_NB) * MAP_BLCK_SIZE;
					pthread_mutex_lock(&((T_BLK *)&root->map[index])->mutex);
					pthread_mutex_lock(&root->st[i].nd[j].rd[k].exe.mutex);
					if (root->st[i].nd[j].rd[k].exe.init == 0) {
						root->st[i].nd[j].rd[k].exe.init = 1;
						root->st[i].nd[j].rd[k].exe.id = count + 1;
					}
//						fprintf(stderr, "%s:%d i=%d j=%d k=%d\n", __func__, __LINE__, i, j, k);
//						r = exey_check();
					r = exey_wrapper(root,
									&root->st[i],
									&root->st[i].nd[j],
									&root->st[i].nd[j].rd[k], index);
					pthread_mutex_unlock(&root->st[i].nd[j].rd[k].exe.mutex);
					pthread_mutex_unlock(&((T_BLK *)&root->map[index])->mutex);
					//fprintf(stderr, "%s:%d i=%d j=%d k=%d r= %d\n", __func__, __LINE__, i, j, k, r);
					if (r != EXEY_IDLE) {
						b = 1;
					}
					else {
						r = EXEY_RUN;
					}
				}
			}
		}
		if (b == 0) {
			r = EXEY_IDLE;
		}
	}
	return (r);
}

int			mapy_f(t_root *root, t_func_mapy f)
{
	int		r = MAPY_OK;
	int		i = 0;
	int		j = 0;
	int		k = 0;
	uint64_t		index;
	
	fprintf(stderr, "%s:%d:%s\n", __func__, __LINE__, __FILE__);
	if (!root)
	{
		r = MAPY_ERR;
	}
	else
	{
		while (i < root->st_nb)
		{
			j = 0;
			while (j < root->nd_nb)
			{
				k = 0;
				while (k < root->rd_nb)
				{
					index = (((i * root->st_nb)  +
												(j * root->nd_nb) +
												k) % BLCK_NB) * MAP_BLCK_SIZE;
#ifdef DEBUG
					// fprintf(stderr, "%s:%d i=%d j=%d k=%d
//  index=%08lx\n", __func__, __LINE__, i, j, k, index);
					fprintf(stderr, "%s:%d st->[i].client=%p nd->[i].client=%p \
rd->exe.[i].client=%p\n", __func__, __LINE__, 
								&root->st[i].client,
								&root->st[i].nd[j].client, 
								&root->st[i].nd[j].rd[k].client);
//			fprintf(stderr, "%s:%d r=%d i=%d index=%08x task=%d hook=%d \n", __func__, __LINE__,
//						r, i, index, rd->exe.tasks[i], rd->exe.hook[i]);
#endif /* DEBUG */
					r = (*f)
								(&(root->map)[index + sizeof(t_blk)],
								(T_CLIENT_ST*)&root->st[i].client,
								(T_CLIENT_ND*)&root->st[i].nd[j].client, 
								(T_CLIENT_RD*)&root->st[i].nd[j].rd[k].client);
					k++;
				}
				j++;
			}
			i++;
		}
	}
	return (r);
}
