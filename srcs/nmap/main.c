
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
static char pre_built_filter_icmp[] = "icmp[icmptype] == icmp-unreach";
static char pre_built_filter_rst[] = "(tcp[tcpflags] & tcp-rst) == tcp-rst";
static char pre_built_filter_synack[] = "(tcp[tcpflags] & (tcp-syn | tcp-ack)) == (tcp-syn | tcp-ack)";


void				ft_pcap_handler(u_char *user, const struct pcap_pkthdr *h, const u_char *bytes)
{
	( void)user;
	uint32_t		i;
	i = 0;
	fprintf(stderr, "%s:%d h->len= %d\n", __func__, __LINE__, h->len);
	while (i < h->len)
	{
		fprintf(stderr, "%02x:", bytes[i]);
		i++;
	}
	fprintf(stderr, "\n");
}

void		*run_pcap(void *root)
{
	int r = pcap_dispatch(((t_root*)root)->client.pcap_handler, -1, ft_pcap_handler, (void*)root);
	fprintf(stderr, "%s:%d r=%d", __func__, __LINE__, r);
	return (NULL);
}

int			set_pcap_init(t_nmap_setting *nmap)
{
	int					r 						= MAPY_OK;
	pcap_if_t			*alldevs				= NULL;
	char				err[PCAP_ERRBUF_SIZE]	= {0};
	pcap_addr_t			*addrs					= NULL;
	char					filter[256]			= {0};
	struct	bpf_program		bpf 			= {0};
//	pcap_t 				*pcap					= NULL;

	r = pcap_findalldevs(&alldevs, err);
	/* Note we cannot capture WiFi target as is , so check */
	if (r == 0)
	{
		while (alldevs && (alldevs->flags & PCAP_IF_LOOPBACK) == 0)
		{
			// fprintf(stderr, "%s: name = %s\n", __func__, alldevs->name);
			// fprintf(stderr, "%s: description = %s\n", __func__, alldevs->description);
			// fprintf(stderr, "%s: flag = %08x\n\n", __func__, alldevs->flags);
			alldevs = alldevs->next;
		}
		fprintf(stderr, "%s: Selected dev: name = %s\n", __func__, alldevs->name); 
		addrs = alldevs->addresses;
		while (addrs != NULL)
		{
	//		if (((struct sockaddr_storage*)addrs->addr)->ss_family == AF_INET)
	//		{
	//			memcpy(&nmap->ip4_src, addrs->addr, sizeof(struct sockaddr_storage));
	//		}
	//		if (((struct sockaddr_storage*)addrs->addr)->ss_family == AF_INET6)
	//		{ // TODO LMA this will not work as sockaddr is too small
	//			memcpy(&nmap->ip6_src, addrs->addr, sizeof(struct sockaddr_storage));
	//		}
			//fprintf(stderr, "ss_family = %d\n", 
			//	((struct sockaddr_storage*)addrs->addr)->ss_family);
			addrs = addrs->next;
		}
	}
	/* Note BUFSIZ is defined in stdio for std buffer : 8192 */
	if (r == 0)
	{
		nmap->pcap_handler = pcap_open_live(alldevs->name, BUFSIZ, 1, 1000, err);
		if (nmap->pcap_handler == NULL)
		{
			r = MAPY_ERR;
		}
	}
	if (r == 0)
	{
		// TODO save src addr too (only the one corresponding to this link layer)
		pcap_freealldevs(alldevs);
		snprintf(filter, sizeof(filter), "src host %s and (%s or %s or %s)",
							"localhost",
							pre_built_filter_icmp,
							pre_built_filter_rst,
							pre_built_filter_synack);
		fprintf(stderr, "filter = {%s}\n", filter);
		r = pcap_compile(nmap->pcap_handler, &bpf, filter, 0, PCAP_NETMASK_UNKNOWN);
	}
	if (r == 0)
	{
		r = pcap_setfilter(nmap->pcap_handler, &bpf);
	}
	if (r == PCAP_ERROR)
	{
		fprintf(stderr, "%s,%d\n", __func__, __LINE__);
		fprintf(stderr, "%s,%derr = %s\n", __func__, __LINE__, err);
		pcap_perror(nmap->pcap_handler, "setfilter");
		//pcap_perror(nmap->pcap_handler, "open_live:");
	}
	return (r);
}

int			set_pcap_close(t_nmap_setting *nmap)
{
	fprintf(stderr, "%s:%d\n", __func__, __LINE__);
	pcap_close(nmap->pcap_handler);
	return (MAPY_OK);
}

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
//		settings->ip_nb = 1;
//		settings->port_nb = 1;
//		settings->scan_nb = 1;
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
	//	pcap_test(settings);
		((t_root*)buf)->st_nb = settings->ip_nb;
		((t_root*)buf)->nd_nb = settings->port_nb;
		((t_root*)buf)->rd_nb = settings->scan_nb;
		if (set_pcap_init(&root->client))
			return (-1);
		
		pthread_create(&root->client.thread, NULL, run_pcap, (void*)root);
		//set_pcap_close(&root->client); // TODO 

		if (set_st(root, set_sockaddr))
			return (-1);
//		if (set_nd(root, set_port))
//			return (-1);
//		if (set_rd(root, set_tcpflag))
//			return (-1);
//		if (set_st(root, print_st))
//			return (-1);
		if (set_iter_nd(root, iter_set_port))
			return (-1);
		if (set_iter_rd(root, iter_set_tcpflag))
			return (-1);
//		if (set_st(root, set_socket))
//			return (-1);
		if (set_st(root, set_sockaddr))
			return (-1);
//		if (set_nd(root, print_nd))
//			return (-1);
//		if (set_rd(root, print_rd))
//			return (-1);

		exey_ctrl(root, nmap_init_exey);
		r = mapy(root);

		int i;
		pthread_join(root->client.thread, (void**)&i);
//		if (mapy_f(root, build_ipv4_tcp))
//			return (-1);
//		if (mapy_f(root, send_ipv4_tcp))
//			return (-1);
//		if (mapy_f(root, recv_ipv4_tcp))
//			return (-1);
//		if (mapy_f(root, print_all))
//			return (-1);
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

