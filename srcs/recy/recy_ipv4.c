/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recy_ipv4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 21:06:41 by leon              #+#    #+#             */
/*   Updated: 2022/09/16 15:45:23 by adbenoit         ###   ########.fr       */
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

int 				recv_ipv4(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec)
{
	int				r 			= RECY_OK;
	struct	bpf_program		bpf 			= {0};
	t_nmap_blkhdr			*blkhdr			= (t_nmap_blkhdr*)buf;
	char				filter[FILTER_SIZE]	= {0};
	struct		timeval		tv			= {0};

	if (!buf || !conf_st || !conf_nd || !conf_exec)
	{
		fprintf(stderr, "%s:%d", __func__, __LINE__);
		r = RECY_ERROR;
	}
	else
	{
		snprintf(filter, FILTER_SIZE, "src host %s and (tcp src port %d or %s or udp src port %d)",
			inet_ntoa(((struct sockaddr_in*)&((t_nmap_link*)conf_st)->src_sock)->sin_addr),
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
		//bzero(&buf[sizeof(t_nmap_blkhdr)], MAP_BLCK_SIZE - sizeof(t_nmap_blkhdr));
		gettimeofday(&tv, NULL);
		pthread_mutex_lock((pthread_mutex_t *)&buf[sizeof(pthread_mutex_t)]);
		blkhdr->send_time = tv.tv_sec;
		pthread_mutex_unlock((pthread_mutex_t *)&buf[sizeof(pthread_mutex_t)]);
		pcap_loop(blkhdr->pcap_handler, 1,
					nmap_pcap_handler, &buf[sizeof(t_nmap_blkhdr)]);
		pthread_mutex_lock((pthread_mutex_t *)&buf[sizeof(pthread_mutex_t)]);
		blkhdr->send_time = 0;
		pthread_mutex_unlock((pthread_mutex_t *)&buf[sizeof(pthread_mutex_t)]);
		pcap_freecode(&bpf);
	}
	return (r);
}
