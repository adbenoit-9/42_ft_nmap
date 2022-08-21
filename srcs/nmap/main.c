
#include "mapy.h"
//#include <pthread.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "hooks.h"
#include "ft_nmap_parsing.h"

#define MAPY_DEBUG


int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	int32_t 		r		= 0;
	uint8_t			*buf;
	t_root			*root;
	//test_root		*conf;
	
	buf = (uint8_t*)malloc(SIZE);
	parser(ac, av);
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
		if (set_st(root, set_sockaddr))
			return (-1);
		if (set_nd(root, set_port))
			return (-1);
		if (set_nd(root, set_socket))
			return (-1);
		if (set_rd(root, set_tcpflag))
			return (-1);

		if (set_st(root, print_st))
			return (-1);
		if (set_nd(root, print_nd))
			return (-1);
		if (set_rd(root, print_rd))
			return (-1);


	//	if (mapy_f(root, build_ipv4_tcp))
	//		return (-1);


		exey_ctrl(root, nmap_init_exey);
		r = mapy(root);
		fprintf(stderr, "%s: r = %d\n", __func__, r);

		if (mapy_f(root, print_all))
			return (-1);
//		fprintf(stderr, "%s:%d r = %d", __func__, __LINE__, r);
//		if (mapy_f(root, send_ipv4_tcp))
//			return (-1);
//		fprintf(stderr, "%s:%d r = %d", __func__, __LINE__, r);
//		if (set_nd(root, clean_net))
//			return (-1);
//		fprintf(stderr, "%s:%d r = %d", __func__, __LINE__, r);
		// mapy_f(root, test_mapy);
//		exey_ctrl(root, test_exey);

//		r = mapy(root);
//		fprintf(stderr, "%s:%d r = %d", __func__, __LINE__, r);
//		r = mapy(root);
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

