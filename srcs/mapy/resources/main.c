
#include "../mapy.h"
//#include <pthread.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


//uint8_t				buf[SIZE] = {0};
//uint8_t				buf[SIZE];

#define DEBUG

//int 				test_test1(uint8_t *, T_CLIENT_ST *, T_CLIENT_ND *, T_CLIENT_RD *);
int 				test_mapy(uint8_t *buf, test_st *st, test_nd *nd, test_rd *rd);
int 				test_sety_rd(test_root *root, test_st *st, test_nd *nd, test_rd *rd);
int 				test_sety_nd(test_root *root, test_st *st, test_nd *nd);
int 				test_sety_st(test_root *root, test_st *st);
int					test_mapy_print(uint8_t *buf, test_st *st, test_nd *nd, test_rd *rd);

int					test_exey(test_root *root, t_exe *exe , t_blk *blk);
int					test_exey_print(test_root *root, t_exe *exe , t_blk *blk);

int main(int ac, char **av)
{
	int32_t 		r		= 0;
	uint8_t			*buf;
	t_root			*root;
	test_root		*conf;
	
	buf = (uint8_t*)malloc(SIZE);

	fprintf(stderr, "Hello\na=%s b=%s c=%s  d=%s e=%d f=%d g=%d h=%d \
 i=%d j=%d k=%d l=%d m=%d n=%d o=%d p=%d q=%d r=%d \n",
						T_CLIENT_RD_PRINT,
						T_CLIENT_ND_PRINT,
						T_CLIENT_ST_PRINT,
						T_CLIENT_ROOT_PRINT,
						THREAD_NB,
						BLCK_NB	,
						MAP_BLCK_SIZE,
						SIZE,
						ST_MAX,
						ND_MAX,
						RD_MAX,
						EXEC_LST_SIZE,
						EXEC_TODO_MSK,
						EXEC_MAX_LIST,
						EXEC_MAX_CMD,
						EXEC_MAX_HOOK,
						SETY_EXEC_MAX_CMD,
						SETY_EXEC_MAX_HOOK);
	if (buf == NULL)
	{
		r = -1;
	}
	if (r == 0)
	{
		//fprintf(stderr, "%s:%d buffer=%lu\n", __func__, __LINE__, sizeof(buf));
		fprintf(stderr, "%s:%d configsize=%lx\n", __func__, __LINE__, sizeof(t_root));
		fprintf(stderr, "%s:%d bufferptr=%p\n", __func__, __LINE__, buf);
		fprintf(stderr, "%s:%d mapptr=%p\n", __func__, __LINE__, &buf[sizeof(t_root)]);
		fprintf(stderr, "%s:%d limit_buffer=%p\n", __func__, __LINE__, &buf[SIZE]);
		root = (t_root*)buf;
		root->map = &buf[sizeof(t_root)];
		//conf = (test_root*)root->client;

		((t_root*)buf)->st_nb = 5;
		((t_root*)buf)->nd_nb = 5;
		((t_root*)buf)->rd_nb = 5;
		set_rd(root, test_sety_rd);
		set_nd(root, test_sety_nd);
		set_st(root, test_sety_st);
		// mapy_f(root, test_mapy);
		// mapy_f(root, test_mapy_print);
		exey_ctrl(root, test_exey);
		//exey_rd(root, test_exey_print);

		r = mapy(root);
		fprintf(stderr, "%s:%d r = %d", __func__, __LINE__, r);
		r = mapy(root);
		fprintf(stderr, "%s:%d r = %d", __func__, __LINE__, r);
		
		//mapy_f(root, test_mapy_print);


		fprintf(stderr, "%s:%d\n", __func__, __LINE__);

		//scan_start(&opt);
//		for (uint8_t i = 0; i < 250; i++) {
//			if (pthread_create(&threads[i], NULL, (void *)routine, opt) != 0)
//				fatal_error(-1, "thread_create: failed", opt);
//		}
//		r = mappy(buf, opt.ip_lst);
//		for (uint8_t i = 0; i < 250; i++) {
//			pthread_join(threads[i], NULL);
//		}
	}
//	if (r == RUNNY_OK)
//	{
//		ft_lstclear(&opt.ip_lst, clear_ip);
//	}
	return (r);
}

