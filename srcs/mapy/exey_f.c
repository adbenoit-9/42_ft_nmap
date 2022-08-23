#include "mapy.h"
#include <stdio.h>

#define EXEY_OK 0
#define EXEY_ERR -1
#define MAPY_DEBUG

int				exey_ctrl(t_root *root, t_func_exey f)
{
	int		r = EXEY_OK;
	int		i = 0;
	int		j = 0;
	int		k = 0;
	uint64_t		index;
	
	fprintf(stderr, "%s:%d:%s\n", __func__, __LINE__, __FILE__);
	if (!root)
	{
		r = EXEY_ERR;
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
					//if (root->st[i].nd[j].rd[k].exe.init == 0)
					//{
					//	root->st[i].nd[j].rd[k].exe.init = 1;
					//	root->st[i].nd[j].rd[k].blk.id = i + j + k;
					//}
					index = (((i * root->st_nb) * (j * root->nd_nb) * (k * root->rd_nb) +
												(j * root->nd_nb) * (k * root->rd_nb) +
												k) % BLCK_NB) * MAP_BLCK_SIZE;
#ifdef MAPY_DEBUG
					fprintf(stderr, "%s:%d i=%d j=%d k=%d \n", __func__, __LINE__, i, j, k);
					fprintf(stderr, "%s:%d st->[i].client=%p nd->[i].client=%p \
rd->exe.[i].client=%p\n", __func__, __LINE__, 
							&root->st[i].client,
							&root->st[i].nd[j].client, 
							&root->st[i].nd[j].rd[k].client);
//			fprintf(stderr, "%s:%d r=%d i=%d index=%08x 
// task=%d hook=%d \n", __func__, __LINE__,
//						r, i, index, rd->exe.tasks[i], rd->exe.hook[i]);
#endif /* MAPY_DEBUG */
					r = (*f)
							((T_CLIENT_ROOT*)&root->st[i].client,
							(T_EXE*)&root->st[i].nd[j].rd[k].exe,
							(T_BLK*)&root->map[index]);
					k++;
				}
				j++;
			}
			i++;
		}
	}
	return (r);
}

//int				exey_check_blkhdr(test_root *root, t_exe *exe , t_blk *blk)
//{
//	uint32_t	map_id		= 0;
//
//	if (map_id == exe->id)
//	{
//		/* If this processTODO IDLE own the block, release it */
//		memset(&blk->id, 0, sizeof(map_id));
//	}
//	if (r == MAPY_OK)
//	{
//		/* Check if the map is in use */
//		if (map_id != 0)
//		{
//			/* This process is not the owner of the block ? */
//			if (map_id != exe->id)
//			{
//				r = MAPY_BUSY;
//			}
//		}
//		else
//		{
//			/* This block is free, reserve it */
//			memcpy(&exe->id, &(root->map)[index], sizeof(t_blk));
//		}
//	}
//		/* If the block is free take it */
//		if (map_id == 0x00000000)
//		{
//			memcpy(&(root->map)[index], &rd->id, sizeof(map_id));
//		}
//}

/* Exey return the index of task list
 */

#include "mapy.h"

#define EXEY_OK			0
#define EXEY_ERR		-1

//int				exey_check(test_root *root, t_exe *exe , t_blk *blk)
//{
//	int			r			= MAPY_OK;
//	int			i			= 0;
//	bool		b			= 1;
//
//	i = 0;
//	memcpy(&map_id, &blk->id, sizeof(t_blk));
//	/* Find the 1st task to do */
//	while (i < EXEC_LST_SIZE && ((exe->tasks[i] & EXEC_TODO_MSK) == 0))
//	{
//		++i;
//	}
//	if (i == EXEC_LST_SIZE)
//	{
//		/* Nothing to do, exit */
//		r = EXEY_IDLE;
//	}
////	r = exey_check_blkhdr(root, exe, blk);
//	if (r == EXEY_OK)
//	{
//		/* Check value */
//		if (exe->tasks[i] > EXEC_MAX_CMD - 1 ||
//				exe->hook[i] > EXEC_MAX_HOOK - 1)
//		{
//			r = EXEY_ERR;
//		}
//	}
//	if (r == EXEY_OK)
//	{
//		/* Clear exec flag */
//		exe->tasks[i] &= ~EXEC_TODO_MSK;
//		r = EXEY_RUN;
//#ifdef EXEY_DEBUG
//		fprintf(stderr, " task=%d hook=%d \n", __func__, __LINE__,
//						exe->tasks[i], exe->hook[i]);
//#endif /* EXEY_DEBUG */
//		r = (*_exec[exe->tasks[i]]
//								[exe->hook[i]])
//								(&(root->map)[index + sizeof(t_blk)],
//								(T_CLIENT_ST*)&st->client,
//								(T_CLIENT_ND*)&nd->client, 
//								(T_CLIENT_RD*)&nd->client);
//	}
//	return (r);
//}
