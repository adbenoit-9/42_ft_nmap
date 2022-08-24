#include "mapy.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "nmap_mapy_data.h"

//#define EXEY_DEBUG

#define EXEY_ERR	-1
#define EXEY_OK		0
#define EXEY_IDLE	1
#define EXEY_BUSY	2
#define EXEY_RUN	3

int				exey_wrapper(t_root *root, t_st *st, t_nd *nd, t_rd *rd, int index)
{
	int			r			= EXEY_OK;
	int			i			= 0;

	i = 0;
	/* Find the 1st task to do */
	while (i < EXEC_LST_SIZE && ((rd->exe.tasks[i] & EXEC_TODO_MSK) == 0))
	{
		++i;
	}
	if (i == EXEC_LST_SIZE)
	{
		/* Nothing to do, exit */
		r = EXEY_IDLE;
#ifdef EXEY_DEBUG
		fprintf(stderr, "%s:%d IDLE \n", __func__, __LINE__); // id
#endif /* EXEY_DEBUG */
	}
//	r = exey_check_blkhdr(root, exe, blk);
	if (r == EXEY_OK)
	{
		/* Check value */
		if (rd->exe.tasks[i] > EXEC_MAX_CMD - 1 ||
				rd->exe.hook[i] > EXEC_MAX_HOOK - 1)
		{
			r = EXEY_ERR;
		}
	}
	if (r == EXEY_OK)
	{
		/* Clear exec flag */
		rd->exe.tasks[i] &= ~EXEC_TODO_MSK;
#ifdef EXEY_DEBUG
		fprintf(stderr, "%s:%d RUN i=%d task=%d hook=%d \n", __func__, __LINE__, i,
						rd->exe.tasks[i], rd->exe.hook[i]);
#endif /* EXEY_DEBUG */
		r = (*_exec[rd->exe.tasks[i]]
								[rd->exe.hook[i]])
								(&root->map[index], &st->client, &nd->client, &rd->client);
		r = EXEY_RUN;
	}
	return (r);
}

int			mapy(t_root *root)
{
	int		r = EXEY_RUN;
	int		i = 0;
	int		j = 0;
	int		k = 0;
	int		index;
	
	if (!root)
	{
		r = MAPY_ERR;
	}
	else
	{
		while (r == EXEY_RUN)
		{
			i = 0;
			while (r == EXEY_RUN && i < root->st_nb)
			{
				j = 0;
				while (r == EXEY_RUN && j < root->nd_nb)
				{
					k = 0;
					while (r == EXEY_RUN && k < root->rd_nb)
					{
//		fprintf(stderr, "%s:%d i=%d j=%d k=%d st_nb=%d nd_nb=%d rd_nb=%d\n", __func__, __LINE__, i, j, k, root->st_nb, root->nd_nb, root->rd_nb);
//						if (root->st[i].nd[j].rd[k].exe.init == 0)
//						{
//							fprintf(stderr, "%s:%d\n", __func__, __LINE__);
//							root->st[i].nd[j].rd[k].exe.init = 1;
//							root->st[i].nd[j].rd[k].exe.id = i + j + k;
//						}
						fprintf(stderr, "%s:%d i=%d j=%d k=%d\n", __func__, __LINE__, i, j, k);
//						r = exey_check();
						index = ((i * root->nd_nb * root->rd_nb + j * root->rd_nb + k) % BLCK_NB) * MAP_BLCK_SIZE;
						printf(">>index  : %d\n", index / MAP_BLCK_SIZE);
						r = exey_wrapper(root,
										&root->st[i],
										&root->st[i].nd[j],
										&root->st[i].nd[j].rd[k], index);
//						fprintf(stderr, "%s:%d i=%d j=%d k=%d r= %d\n", __func__, __LINE__, i, j, k, r);
						if (r == EXEY_IDLE)
						{
							
						}
//								&root->st[i].nd[j].rd[k].exe,
//								&root->buf[index]);
						k++;
					}
					j++;
				}
				i++;
			}
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
					index = (((i * root->st_nb) * (j * root->nd_nb) * (k * root->rd_nb) +
												(j * root->nd_nb) * (k * root->rd_nb) +
												k) % BLCK_NB) * MAP_BLCK_SIZE;
#ifdef MAPY_DEBUG
					fprintf(stderr, "%s:%d i=%d j=%d k=%d\
 index=%08lx\n", __func__, __LINE__, i, j, k, index);
					fprintf(stderr, "%s:%d st->[i].client=%p nd->[i].client=%p \
rd->exe.[i].client=%p\n", __func__, __LINE__, 
								&root->st[i].client,
								&root->st[i].nd[j].client, 
								&root->st[i].nd[j].rd[k].client);
//			fprintf(stderr, "%s:%d r=%d i=%d index=%08x task=%d hook=%d \n", __func__, __LINE__,
//						r, i, index, rd->exe.tasks[i], rd->exe.hook[i]);
#endif /* MAPY_DEBUG */
					r = (*f)
								(&(root->map)[index],
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
