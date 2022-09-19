/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recy_ipv6.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 21:06:41 by leon              #+#    #+#             */
/*   Updated: 2022/09/19 14:59:23 by adbenoit         ###   ########.fr       */
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

//static char pre_built_filter_icmp6[] = "icmp6type == icmp6-destinationrunreach";
static char pre_built_filter_icmp6[] = "icmp6";

int 				recv_ipv6(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec)
{
	int				r 			= RECY_OK;
	struct	bpf_program		bpf 			= {0};
	t_nmap_blkhdr			*blkhdr			= (t_nmap_blkhdr*)buf;
	char				filter[FILTER_SIZE]	= {0};
	char				ipstr[32]		= {0};

#ifdef DEBUG
	fprintf(stderr, "%s:%d\n", __func__, __LINE__);
#endif
	if (!buf || !conf_st || !conf_nd || !conf_exec)
	{
		r = RECY_ERROR;
	}
	else
	{
		if (!inet_ntop(AF_INET6, &((struct sockaddr_in6*)&((t_nmap_link*)conf_st)->src_sock)->sin6_addr, ipstr, sizeof(struct sockaddr_in6)))
		{
			perror("inet_ntop");
			return (RECY_ERROR);
		}
		snprintf(filter, FILTER_SIZE, "src host %s and (tcp src port %d or %s or udp src port %d)",
			ipstr,
			((t_nmap_app*)conf_nd)->port,
			pre_built_filter_icmp6,
			((t_nmap_app*)conf_nd)->port);
		bzero(&buf[sizeof(t_nmap_blkhdr)], MAP_BLCK_SIZE - sizeof(t_nmap_blkhdr));
		if (pcap_compile(blkhdr->pcap_handler, &bpf, filter, 0, PCAP_NETMASK_UNKNOWN) < 0)
		{
			perror("pcap compile");
			r = RECY_ERROR;
		}
		if (r == RECY_OK) {
			if (pcap_setfilter(blkhdr->pcap_handler, &bpf) == PCAP_ERROR) {
				r = RECY_ERROR;
			}
		}
		pthread_mutex_lock((pthread_mutex_t *)&buf[sizeof(pthread_mutex_t)]);
		gettimeofday((struct timeval *)&buf[sizeof(pthread_mutex_t) * 2], NULL);
		pthread_mutex_unlock((pthread_mutex_t *)&buf[sizeof(pthread_mutex_t)]);
		pcap_loop(blkhdr->pcap_handler, 1,
					nmap_pcap_handler, &buf[sizeof(t_nmap_blkhdr)]);
		pcap_freecode(&bpf);
	}
	return (r);
}
