
#include "recy.h"
#include "proty.h"
#include "libft.h"
#include "nmap_mapy_config.h"
#include <stdio.h>
#include <string.h>

#include "export_sendy.h"

#define FILTER_SIZE	1024
#define RECY_OK 0
#define RECY_ERROR -1

static char icmp6_port_unreach[] = "icmp6 and ip6[40] == 1";

int 				recv_ipv6_tcp(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec)
{
	int				r 				= RECY_OK;
	struct	bpf_program		bpf 				= {0};
	t_nmap_blkhdr			*blkhdr				= (t_nmap_blkhdr*)buf;
	char				filter[FILTER_SIZE]		= {0};
	char				ipstr[INET6_ADDRSTRLEN]		= {0};
	struct		timeval		tv				= {0};
	uint16_t			src_port			= 0;

#ifdef DEBUG
	fprintf(stderr, "%s:%d\n", __func__, __LINE__);
#endif
	if (!buf || !conf_st || !conf_nd || !conf_exec) {
		r = RECY_ERROR;
	}
	else {
		GET_TCP_SPORT(&buf[sizeof(t_nmap_blkhdr) + sizeof(struct ip6_hdr)], src_port);
		if (!inet_ntop(AF_INET6, &((struct sockaddr_in6*)&((t_nmap_link*)conf_st)->sock)->sin6_addr, ipstr, INET6_ADDRSTRLEN)) {
			perror("inet_ntop");
			r = RECY_ERROR;
		}
		if (r == RECY_OK) {
			snprintf(filter, FILTER_SIZE, "src host %s and ((tcp src port %d and tcp dst port %d) or\
 ((%s) and ip6[91] = %d and ip6[90] = %d and ip6[92] = %d and ip6[93] = %d))",
				ipstr,
				((t_nmap_app*)conf_nd)->port,
				ntohs(src_port),
				icmp6_port_unreach,
				((t_nmap_app*)conf_nd)->port & 0xFF,
				((((t_nmap_app*)conf_nd)->port) >> 8) & 0xFF,
				(src_port >> 8) & 0xFF,
				src_port & 0xFF
				);
			if (pcap_compile(blkhdr->pcap_handler, &bpf, filter, 0, PCAP_NETMASK_UNKNOWN) < 0) {
				pcap_perror(blkhdr->pcap_handler, "pcap compile");
				r = RECY_ERROR;
			}
		}
		if (r == RECY_OK) {
			if (pcap_setfilter(blkhdr->pcap_handler, &bpf) == PCAP_ERROR) {
				r = RECY_ERROR;
			}
		}
		if (r == RECY_OK) {
			gettimeofday(&tv, NULL);
			pthread_mutex_lock((pthread_mutex_t *)&buf[sizeof(pthread_mutex_t)]);
			blkhdr->send_time = tv.tv_sec;
			pthread_mutex_unlock((pthread_mutex_t *)&buf[sizeof(pthread_mutex_t)]);
			r = pcap_loop(blkhdr->pcap_handler, 1,
						nmap_pcap_handler, &buf[sizeof(t_nmap_blkhdr)]);
			pthread_mutex_lock((pthread_mutex_t *)&buf[sizeof(pthread_mutex_t)]);
			blkhdr->send_time = 0;
			pthread_mutex_unlock((pthread_mutex_t *)&buf[sizeof(pthread_mutex_t)]);
		}
		if (r == PCAP_ERROR_BREAK) {
			r = send_tcp(buf, conf_st, conf_nd, conf_exec);
			if (r == RECY_OK) {
				gettimeofday(&tv, NULL);
				pthread_mutex_lock((pthread_mutex_t *)&buf[sizeof(pthread_mutex_t)]);
				blkhdr->send_time = tv.tv_sec;
				pthread_mutex_unlock((pthread_mutex_t *)&buf[sizeof(pthread_mutex_t)]);
				r = pcap_loop(blkhdr->pcap_handler, 1,
						nmap_pcap_handler, &buf[sizeof(t_nmap_blkhdr)]);
				if (r == PCAP_ERROR_BREAK) {
					bzero(&buf[sizeof(t_nmap_blkhdr)], MAP_BLCK_SIZE - sizeof(t_nmap_blkhdr));
					r = RECY_OK;
				}
				pthread_mutex_lock((pthread_mutex_t *)&buf[sizeof(pthread_mutex_t)]);
				blkhdr->send_time = 0;
				pthread_mutex_unlock((pthread_mutex_t *)&buf[sizeof(pthread_mutex_t)]);
			}
		}
		else if (r != 0) {
			r = RECY_ERROR;
		}
		pcap_freecode(&bpf);
	}
	return (r);
}

