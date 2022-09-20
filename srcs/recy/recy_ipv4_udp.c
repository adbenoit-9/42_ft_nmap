
#include "recy.h"
#include "proty.h"
#include "libft.h"
#include "nmap_mapy_config.h"
#include <stdio.h>
#include <string.h>
#include "export_sendy.h"

#define FILTER_SIZE	256
#define RECY_OK 0
#define RECY_ERROR -1

static char icmp_port_unreach[] = "icmp[icmptype] == icmp-unreach";

int 				recv_ipv4_udp(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec)
{
	int					r 					= RECY_OK;
	struct	bpf_program	bpf 				= {0};
	t_nmap_blkhdr		*blkhdr				= (t_nmap_blkhdr*)buf;
	char				filter[FILTER_SIZE]	= {0};
	struct		timeval	tv					= {0};

#ifdef DEBUG
	fprintf(stderr, "%s:%d\n", __func__, __LINE__);
#endif
	if (!buf || !conf_st || !conf_nd || !conf_exec)
	{
		r = RECY_ERROR;
	}
	else
	{
		//snprintf(filter, FILTER_SIZE, "src host %s and (tcp src port %d or %s or udp src port %d)",
		//snprintf(filter, FILTER_SIZE, "src host %s and (tcp src port %d or (%s and (ip[49] = %d)) or udp src port %d)",
		snprintf(filter, FILTER_SIZE, "src host %s and ((%s and ip[51] = %d and ip[50] = %d) or udp src port %d)",
			inet_ntoa(((struct sockaddr_in*)&((t_nmap_link*)conf_st)->sock)->sin_addr),
			icmp_port_unreach,
			((t_nmap_app*)conf_nd)->port & 0xFF,
			((((t_nmap_app*)conf_nd)->port) >> 8) & 0xFF,
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
		gettimeofday(&tv, NULL);
		pthread_mutex_lock((pthread_mutex_t *)&buf[sizeof(pthread_mutex_t)]);
		blkhdr->send_time = tv.tv_sec;
		pthread_mutex_unlock((pthread_mutex_t *)&buf[sizeof(pthread_mutex_t)]);
		r = pcap_loop(blkhdr->pcap_handler, 1,
					nmap_pcap_handler, &buf[sizeof(t_nmap_blkhdr)]);
		pthread_mutex_lock((pthread_mutex_t *)&buf[sizeof(pthread_mutex_t)]);
		blkhdr->send_time = 0;
		pthread_mutex_unlock((pthread_mutex_t *)&buf[sizeof(pthread_mutex_t)]);
		if (r == PCAP_ERROR_BREAK)
		{
			r = send_udp(buf, conf_st, conf_nd, conf_exec);
			if (r == RECY_OK)
			{
				gettimeofday(&tv, NULL);
				pthread_mutex_lock((pthread_mutex_t *)&buf[sizeof(pthread_mutex_t)]);
				blkhdr->send_time = tv.tv_sec;
				pthread_mutex_unlock((pthread_mutex_t *)&buf[sizeof(pthread_mutex_t)]);
				r = pcap_loop(blkhdr->pcap_handler, 1,
						nmap_pcap_handler, &buf[sizeof(t_nmap_blkhdr)]);
				if (r == PCAP_ERROR_BREAK) {
					bzero(&buf[sizeof(t_nmap_blkhdr)], MAP_BLCK_SIZE - sizeof(t_nmap_blkhdr));
				}
				pthread_mutex_lock((pthread_mutex_t *)&buf[sizeof(pthread_mutex_t)]);
				blkhdr->send_time = 0;
				pthread_mutex_unlock((pthread_mutex_t *)&buf[sizeof(pthread_mutex_t)]);
				r = RECY_OK;
			}
		}
		pcap_freecode(&bpf);
	}
	return (r);
}

