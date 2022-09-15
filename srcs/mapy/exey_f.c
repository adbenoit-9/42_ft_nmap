#include "mapy.h"
#include <stdio.h>

#define EXEY_OK 0
#define EXEY_ERR -1
//#define DEBUG

/*
**int				exey_ctrl(t_root *root, t_func_exey f)
**{
**	int			r = EXEY_OK;
**	uint64_t	index = 0;
**	
**	fprintf(stderr, "%s:%d:%s\n", __func__, __LINE__, __FILE__);
**	if (!root) {
**		r = EXEY_ERR;
**	}
**	for (int i = 0; r == EXEY_OK && i < root->st_nb; i++) {
**		for (int j = 0; r == EXEY_OK && j < root->nd_nb; j++) {
**			for (int k = 0; r == EXEY_OK && k < root->rd_nb; k++, index++) {
**#ifdef DEBUG
**				fprintf(stderr, "%s:%d i=%d j=%d k=%d \n", __func__, __LINE__, i, j, k);
**				fprintf(stderr, "%s:%d st->[i].client=%p nd->[i].client=%p \
**rd->exe.[i].client=%p\n", __func__, __LINE__, 
**						&root->st[i].client,
**						&root->st[i].nd[j].client, 
**						&root->st[i].nd[j].rd[k].client);
**
**
**
**#endif 
**				r = (*f)
**						((T_CLIENT_ROOT*)&root->st[i].client,
**						(T_EXE*)&root->rd[k].exe,
**						index >= BLCK_NB ? NULL : (*)&root->map[index * sizeof(t_blk)]);
**			}
**		}
**	}
**	return (r);
**}
*/

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
//#ifdef DEBUG
//		fprintf(stderr, " task=%d hook=%d \n", __func__, __LINE__,
//						exe->tasks[i], exe->hook[i]);
//#endif /* DEBUG */
//		r = (*_exec[exe->tasks[i]]
//								[exe->hook[i]])
//								(&(root->map)[index + sizeof(t_blk)],
//								(T_CLIENT_ST*)&st->client,
//								(T_CLIENT_ND*)&nd->client, 
//								(T_CLIENT_RD*)&nd->client);
//	}
//	return (r);
//}
