#include <stdint.h>
#include <stdio.h>
#include "../mapy.h"
#include "test_structs.h"
//#include "export_test.h"

//int 				test_test4(uint8_t *buf, void *st, void *nd, void *rd);

int					test_exey_print(test_root *root, t_exe *exe , t_blk *blk)
{
	int i = 0;

	blk->id = 0xFFFFFFFF;
	fprintf(stderr, "%s: blk=%p exe=%p\n\n", __func__, (void*)blk, (void*)exe);
	while (i < EXEC_LST_SIZE)
	{
		if (i % 32 == 0)
		{
			fprintf(stderr, "\n");
		}
		fprintf(stderr, "%08x:", exe->tasks[i]);
		i++;
	}
	fprintf(stderr, "\n\n");
}
int					test_exey(test_root *root, t_exe *exe , t_blk *blk)
{
	int i = 0;

	blk->id = 0xFFFFFFFF;
	while (i < EXEC_LST_SIZE)
	{
		exe->tasks[i] = i;
		i++;
	}
	exe->tasks[0] |= EXEC_TODO_MSK;
	exe->tasks[1] |= EXEC_TODO_MSK;
}

int					test_mapy_print(uint8_t *buf, test_st *st, test_nd *nd, test_rd *rd)
{
	int i;

	fprintf(stderr, "%s:%d buf=%p\n\n", __func__, __LINE__, buf);
	
	i = 0;
	while (i < MAP_BLCK_SIZE)
	{
		if (i % 32 == 0)
		{
			fprintf(stderr, "\n");
		}
		fprintf(stderr, "%02x.",buf[i++]);
	}
	fprintf(stderr, "\n\n");
}

int 				test_mapy(uint8_t *buf, test_st *st, test_nd *nd, test_rd *rd)
{
	size_t		i;

//	fprintf(stderr, "%s:%d buf=%p\n", __func__, __LINE__, buf);
	i = 0;
	while (i < MAP_BLCK_SIZE)
	{
		buf[i] = i;//rd->buf[i];
		i++;
	}
	return (0);
}

int 				test_sety_rd(test_root *root, test_st *st, test_nd *nd, test_rd *rd)
{

	//fprintf(stderr, "%s:%d buf=%p\n", __func__, __LINE__, rd->buf);
	int i = 0;
	while (i < 32)
	{
		rd->buf[i] = nd->buf[i] + i + nd->buf[i];
		i++;
	}
	rd->flag = nd->flag;
	return	(0);
}

int 				test_sety_nd(test_root *root, test_st *st, test_nd *nd)
{

	//fprintf(stderr, "%s:%d buf=%p\n", __func__, __LINE__, nd->buf);
	int i = 0;
	while (i < 128)
	{
		nd->buf[i] = st->buf[i] + i + st->buf[i];
		i++;
	}
	nd->flag = st->flag;
	return	(0);
}
int 				test_sety_st(test_root *root, test_st *st)
{
	int i = 0;

	//fprintf(stderr, "%s:%d buf=%p\n", __func__, __LINE__, st->buf);
	while (i < 128)
	{
		root->buf[i] = i++;
	}
	i = 0;
	while (i < 128)
	{
		st->buf[i] = root->buf[i] + i;
		i++;
	}
	st->flag = root->flag;
	st->flag = st->flag;

	//fprintf(stderr, "%s:%d %s\n", __func__, __LINE__, __FILE__);
	return	(0);
}
