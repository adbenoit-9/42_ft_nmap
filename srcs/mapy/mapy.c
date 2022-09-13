/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:57:21 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/13 17:38:15 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapy.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <signal.h>
#include <pthread.h>

#define DEBUG
#define DEBUG

#define EXEY_ERR	-1
#define EXEY_OK		0
#define EXEY_IDLE	1
#define EXEY_BUSY	2
#define EXEY_RUN	3

int			mapy(t_root *root)
{
	int			r = EXEY_RUN;
	uint64_t		count;
	uint64_t		index;
	t_blk			*blk;
	
	memset(root->blk_flag, 0, sizeof(root->blk_flag));
	if (!root) {
		r = MAPY_ERR;
	}
	count = 0;
	while (r == EXEY_RUN  || r == EXEY_BUSY)
	{
		r = EXEY_RUN;
		for (int i = 0; (r == EXEY_RUN  || r == EXEY_BUSY) && i < root->st_nb; i++) {
			for (int j = 0; (r == EXEY_RUN  || r == EXEY_BUSY || r == EXEY_IDLE) && j < root->nd_nb; j++) {
				for (int k = 0; (r == EXEY_RUN  || r == EXEY_BUSY || r == EXEY_IDLE)
											&& k < root->rd_nb; k++, count++) {
					index = (count % BLCK_NB) * sizeof(t_blk);
					blk = (t_blk*)&root->map[index];
					printf("count = %ld\n", count);
					if (root->blk_flag[count % BLCK_NB] == BLK_TODO) {
						if (blk->flag == BLK_BUSY) {
							r = EXEY_BUSY;
						}
						else {
							blk->flag = BLK_BUSY;
							blk->root = &root->client;
							blk->st = &root->st[i].client;
							blk->nd = &root->nd[j].client;
							blk->rd = &root->rd[k].client;
							blky_branch_task_hooks(blk);
							r = blky(blk);
							printf("ret = %d\n", r);
							if (r == BLKY_OK) {
								root->blk_flag[count % BLCK_NB] = BLK_DONE;
							}
							else {
								root->blk_flag[count % BLCK_NB] = BLK_ERROR;
							}
							blk->flag = BLK_IDLE;
							r = EXEY_RUN;
						}
					}
					else {
						r = EXEY_IDLE;
					}
				}
			}
		}
	}
	return (r);
}
//		fprintf(stderr, "%s:%d i=%d j=%d k=%d st_nb=%d nd_nb=%d rd_nb=%d\n", __func__, __LINE__, i, j, k, root->st_nb, root->nd_nb, root->rd_nb);

/*
**
**int			mapy_f(t_root *root, t_func_mapy f)
**{
**	int		r = MAPY_OK;
**	int		i = 0;
**	int		j = 0;
**	int		k = 0;
**	uint64_t		index;
**	
**	fprintf(stderr, "%s:%d:%s\n", __func__, __LINE__, __FILE__);
**	if (!root)
**	{
**		r = MAPY_ERR;
**	}
**	else
**	{
**		while (i < root->st_nb)
**		{
**			j = 0;
**			while (j < root->nd_nb)
**			{
**				k = 0;
**				while (k < root->rd_nb)
**				{
**					index = (((i * root->st_nb)  +
**												(j * root->nd_nb) +
**												k) % BLCK_NB) * MAP_BLCK_SIZE;
**#ifdef DEBUG
**					// fprintf(stderr, "%s:%d i=%d j=%d k=%d
**  index=%08lx\n", __func__, __LINE__, i, j, k, index);
**					fprintf(stderr, "%s:%d st->[i].client=%p nd->[i].client=%p \
**rd->exe.[i].client=%p\n", __func__, __LINE__, 
**								&root->st[i].client,
**								&root->st[i].nd[j].client, 
**								&root->st[i].nd[j].rd[k].client);
**			fprintf(stderr, "%s:%d r=%d i=%d index=%08x task=%d hook=%d \n", __func__, __LINE__,
**						r, i, index, rd->exe.tasks[i], rd->exe.hook[i]);
**#endif 
**					r = (*f)
**								(&(root->map)[index + sizeof(t_blk)],
**								(T_CLIENT_ST*)&root->st[i].client,
**								(T_CLIENT_ND*)&root->st[i].nd[j].client, 
**								(T_CLIENT_RD*)&root->st[i].nd[j].rd[k].client);
**					k++;
**				}
**				j++;
**			}
**			i++;
**		}
**	}
**	return (r);
**}
*/
