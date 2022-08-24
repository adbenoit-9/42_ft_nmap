/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recy_pcap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 07:31:30 by leon              #+#    #+#             */
/*   Updated: 2022/08/24 07:39:47 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapy.h"
#include <pcap/pcap.h>
#include <pthread.h>

static char pre_built_filter_icmp[] = "icmp[icmptype] == icmp-unreach";
static char pre_built_filter_rst[] = "(tcp[tcpflags] & tcp-rst) == tcp-rst";
static char pre_built_filter_synack[] = "(tcp[tcpflags] & (tcp-syn | tcp-ack)) == (tcp-syn | tcp-ack)";

void				ft_pcap_handler(u_char *user, const struct pcap_pkthdr *h,
							const u_char *bytes)
{
	( void)user;
	uint32_t		i;

	/* TODO : go in tree and find corresponding scan for this response */
	/* TODO : some scan need to be re-send when timeout */
	i = 14; // pcap_hdr
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
	/* TODO clarify when it exit, it should only exit on error */
	int r = pcap_dispatch(((t_root*)root)->client.pcap_handler, -1,
					ft_pcap_handler, (void*)root);
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
	struct	bpf_program		bpf 				= {0};

	r = pcap_findalldevs(&alldevs, err);
	/* Note we cannot capture WiFi target as is , so check */
	if (r == 0)
	{
		while (alldevs && (alldevs->flags & PCAP_IF_LOOPBACK) == 0)
		{
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
		//fprintf(stderr, "%s,%derr = %s\n", __func__, __LINE__, err);
		//pcap_perror(nmap->pcap_handler, "setfilter");
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

