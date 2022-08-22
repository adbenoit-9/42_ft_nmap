
#include "mapy.h"
//#include <pthread.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <pcap/pcap.h>

#include "hooks.h"
#include "ft_nmap_parsing.h"

#define MAPY_DEBUG

void	dump_config(uint8_t *buf, t_nmap_setting *settings)
{
	pcap_lib_version();
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
		//fprintf(stderr, "%s:%d buffer=%lu\n", __func__, __LINE__, sizeof(buf));
		fprintf(stderr, "%s:%d configsize=%lx\n", __func__, __LINE__, sizeof(t_root));
		fprintf(stderr, "%s:%d bufferptr=%p\n", __func__, __LINE__, buf);
		fprintf(stderr, "%s:%d mapptr=%p\n", __func__, __LINE__, &buf[sizeof(t_root)]);
		fprintf(stderr, "%s:%d limit_buffer=%p\n", __func__, __LINE__, &buf[SIZE]);
		fprintf(stderr, "ft_nmapconfig:speedup = %d\n", settings->speedup);
		int i = 0;
		fprintf(stderr, "ft_nmapconfig:port = %x", settings->ports[i++]);
		while (i < PORT_LIMIT)
		{
			fprintf(stderr, ":%x", settings->ports[i++]);
		}
		fprintf(stderr, "\n");
		i = 0;
		fprintf(stderr, "ft_nmapconfig:scans = %x", settings->scans[i++]);
		while (i < SCAN_LIMIT)
		{
			fprintf(stderr, ":%x", settings->scans[i++]);
		}
		fprintf(stderr, "\n");
		fprintf(stderr, "ip_nb = %d\n", settings->ip_nb);
		fprintf(stderr, "port_nb = %d\n", settings->port_nb);
		fprintf(stderr, "scan_nb = %d\n", settings->scan_nb);
}

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	int32_t 		r		= 0;
	uint8_t			*buf;
	t_root			*root;
	t_nmap_setting	*settings;
	//test_root		*conf;
	
	buf = (uint8_t*)malloc(SIZE);
	if (buf == NULL)
	{
		r = -1;
	}
	if (r == 0)
	{
		root = (t_root*)buf;
		root->map = &buf[sizeof(t_root)];
		settings = &root->client;
		parser(ac, av, settings);
		dump_config(buf, settings);
		//conf = (test_root*)root->client;

		((t_root*)buf)->st_nb = settings->ip_nb;
		((t_root*)buf)->nd_nb = settings->port_nb;
		((t_root*)buf)->rd_nb = settings->scan_nb;
//		if (set_st(root, set_sockaddr))
//			return (-1);
//		if (set_nd(root, set_port))
//			return (-1);
//		if (set_rd(root, set_tcpflag))
//			return (-1);
//
//		if (set_st(root, print_st))
//			return (-1);
		if (set_iter_nd(root, iter_set_port))
			return (-1);
		if (set_iter_rd(root, iter_set_tcpflag))
			return (-1);
		if (set_st(root, set_socket))
			return (-1);
		if (set_st(root, set_sockaddr))
			return (-1);
//		if (set_nd(root, print_nd))
//			return (-1);
//		if (set_rd(root, print_rd))
//			return (-1);

//		exey_ctrl(root, nmap_init_exey);
//		r = mapy(root);

		if (mapy_f(root, build_ipv4_udp))
			return (-1);
		if (mapy_f(root, send_ipv4_udp))
			return (-1);
		if (mapy_f(root, print_all))
			return (-1);
//		if (mapy_f(root, print_report))
//			return (-1);

//		fprintf(stderr, "%s: r = %d\n", __func__, r);
//

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

