/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildy_ipv6_tcp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 02:04:56 by leon              #+#    #+#             */
/*   Updated: 2022/08/23 17:24:27 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buildy.h"
#include <string.h>
#include "mapy.h"
#include <arpa/inet.h>
#include "nmap_structs.h"

int	build_ipv6_tcp(uint8_t *buf, T_CLIENT_ST *conf_st, T_CLIENT_ND *conf_nd,
		T_CLIENT_RD *conf_exec)
{
	int				ret			= BUILDY_OK;
	uint8_t			random[16]	= {0};
	uint8_t			tcpoff		= 0;
	uint32_t		length;
	struct in6_addr	dip;

	if (!buf || !conf_st || !conf_nd || !conf_exec) {
		ret = BUILDY_ERROR;
	}
	else {
#ifdef BUILDY_DEBUG
		fprintf(stderr, "%s:%d scantype=%02x\n", __func__, __LINE__, 
									((t_scan*)conf_exec)->tcpflag);
#endif /* BUILDY_DEBUG */
		memset(buf, 0, MAP_BLCK_SIZE);
		ret = get_urandom(random, 16);
		if (ret == BUILDY_OK) {
			dip = ((struct sockaddr_in6 *)&conf_st->sock)->sin6_addr;
			length = sizeof(struct ip6_hdr) + sizeof(struct tcphdr);
			
			SET_IP6_SRC(buf, dip);
			SET_IP6_DST(buf, dip);
			SET_IP6_FLOW(buf, 0x0b0500); // NOT OK
			SET_IP6_NXT(buf, 0x11); // UDP
			SET_IP6_HLIM(buf, (uint8_t)(*(&random[2])));
			SET_IP6_VFC(buf, IPV6_VERSION, 0x0);
			SET_TCP_SEQ(&buf[sizeof(struct ip6_hdr)], (uint32_t)(*(&random[3])));
			SET_TCP_SPORT(&buf[sizeof(struct ip6_hdr)], (uint16_t)(*(&random[7])));
			SET_TCP_WIN(&buf[sizeof(struct ip6_hdr)], 0x0004);
			SET_TCP_URP(&buf[sizeof(struct ip6_hdr)], 0x0000);
			
			tcpoff = 5;
			if (conf_exec->tcpflag == FLAG_S_SYN) {
	   			length += 4;
				++tcpoff;
	   			SET_TCP_DATA(&buf[sizeof(struct ip6_hdr)], syn_mss, 4);
			}
			conf_exec->packet_length = length;
			SET_TCP_FLAGS(&buf[sizeof(struct ip6_hdr)], conf_exec->tcpflag); // TODO 
			SET_TCP_DPORT(&buf[sizeof(struct ip6_hdr)], htons(conf_nd->port));
			SET_TCP_OFF(&buf[sizeof(struct ip6_hdr)], tcpoff);
			SET_IP6_PLEN(buf, htons(length));
			SET_TCP_SUM(&buf[sizeof(struct ip6_hdr)], tcp_ipv4_checksum(buf, length - sizeof(struct ip6_hdr)));
		}
	}
	return (ret);
}

