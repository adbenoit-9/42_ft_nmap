/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recy_ipv4_tcp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 21:06:41 by leon              #+#    #+#             */
/*   Updated: 2022/09/13 17:50:50 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recy.h"
#include "proty.h"
#include "libft.h"
#include "nmap_mapy_config.h"
#include <stdio.h>
#include <string.h>

#define FILTER_SIZE	128
#define RECY_OK 0
#define RECY_ERROR -1

static char pre_built_filter_icmp[] = "icmp[icmptype] == icmp-unreach";

int 				recv_ipv6(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec)
{
	int				r 			= RECY_OK;
	struct	bpf_program		bpf 			= {0};
	t_nmap_blkhdr			*blkhdr			= (t_nmap_blkhdr*)buf;
	char				filter[FILTER_SIZE]	= {0};
	char				ipstr[32]		= {0};

	if (!buf || !conf_st || !conf_nd || !conf_exec)
	{
		r = RECY_ERROR;
	}
	else
	{
		inet_ntop(AF_INET6, &((struct sockaddr_in6*)&((t_nmap_link*)conf_st)->src_sock)->sin6_addr, ipstr, sizeof(struct sockaddr_in6)),
		snprintf(filter, FILTER_SIZE, "src host %s and (tcp port %d or %s or udp port %d)",
			ipstr,
			((t_nmap_app*)conf_nd)->port,
			pre_built_filter_icmp,
			((t_nmap_app*)conf_nd)->port);
		if (pcap_compile(blkhdr->pcap_handler, &bpf, filter, 0, PCAP_NETMASK_UNKNOWN) < 0)
		{
			r = RECY_ERROR;
		}
		if (r == RECY_OK) {
			if (pcap_setfilter(blkhdr->pcap_handler, &bpf) == PCAP_ERROR) {
				r = RECY_ERROR;
			}
		}
		bzero(&buf[sizeof(t_nmap_blkhdr)], MAP_BLCK_SIZE - sizeof(t_nmap_blkhdr));
		pcap_loop(blkhdr->pcap_handler, 1,
					nmap_pcap_handler, &buf[sizeof(t_nmap_blkhdr)]);
		pcap_freecode(&bpf);
	}
	return (r);
}
