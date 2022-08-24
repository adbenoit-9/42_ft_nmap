
#include "mapy.h"
//#include <pthread.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <pcap/pcap.h>
#include <pthread.h>

#include "hooks.h"
#include "ft_nmap_parsing.h"

#define MAPY_DEBUG


void	dump_config(uint8_t *buf, t_nmap_setting *settings)
{
	fprintf(stderr, "pcap_version=%s\n", pcap_lib_version());
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
	int32_t 		r		= 0;
	uint8_t			*buf;
	t_root			*root;
	t_nmap_setting	*settings;
	int				thread_r;
	
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
		/* Parsing */
		parser(ac, av, settings);
		dump_config(buf, settings);
		/* Update size of tree params */
		((t_root*)buf)->st_nb = settings->ip_nb;
		((t_root*)buf)->nd_nb = settings->port_nb;
		((t_root*)buf)->rd_nb = settings->scan_nb;
		/* Pcap handler init */
		if (set_pcap_init(&root->client) != 0)
			return (-1);
		pthread_create(&root->client.thread, NULL, run_pcap, (void*)root);
		/* Fill parameters in tree */
		if (set_iter_st(root, set_sockaddr))
			return (-1);
		if (set_iter_nd(root, iter_set_port))
			return (-1);
		if (set_iter_rd(root, iter_set_tcpflag))
			return (-1);
		if (set_st(root, set_socket))
			return (-1);
		/* Set tasks list */
		exey_ctrl(root, nmap_init_exey);
		/* Mappy execute task list */
		r = mapy(root);

		pthread_join(root->client.thread, (void**)&thread_r);
		fprintf(stderr, "%s:%d thread_r = %d\n", __func__, __LINE__, thread_r);
		/* TODO: Analyse and print report */

		//if (mapy_f(root, send_udp))
		//	return (-1);
		//if (mapy_f(root, print_all))
		//	return (-1);
	}
	return (r);
}

