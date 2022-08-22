/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildy_ipv6_udp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 02:04:56 by leon              #+#    #+#             */
/*   Updated: 2022/08/22 16:01:33 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buildy.h"
#include <string.h>
#include "mapy.h"
#include <arpa/inet.h>
#include "nmap_structs.h"

int build_ipv6_udp(uint8_t *buf, T_CLIENT_ST *conf_st, T_CLIENT_ND *conf_nd,
		T_CLIENT_RD *conf_exec)
{
	int		ret = BUILDY_OK;
	uint8_t	random[16] = {0};

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
			struct in6_addr	dip; // DEBUG
			conf_exec->packet_length = sizeof(struct ip6_hdr) + sizeof(struct udphdr);
			
			inet_pton(AF_INET6, "127.0.0.1", &dip); // DEBUG
			SET_IP6_SRC(buf, dip); // DEBUG
			SET_IP6_DST(buf, dip); // DEBUG
			SET_IP6_FLOW(buf, 0x00);
			SET_IP6_NXT(buf, 0x11); // UDP
			SET_IP6_HLIM(buf, (uint8_t)(*(&random[2])));
			SET_TCP_SEQ(&buf[sizeof(struct ip6_hdr)], (uint32_t)(*(&random[3])));
			SET_TCP_SPORT(&buf[sizeof(struct ip6_hdr)], (uint16_t)(*(&random[7])));
			SET_TCP_WIN(&buf[sizeof(struct ip6_hdr)], 0x0004);
			SET_TCP_URP(&buf[sizeof(struct ip6_hdr)], 0x0000);
			SET_IP6_PLEN(buf, htons(conf_exec->packet_length));
			
			SET_UDP_SPORT(&buf[sizeof(struct ip6_hdr)], (uint16_t)(*(&random[7])));
			SET_UDP_DPORT(&buf[sizeof(struct ip6_hdr)], htons(conf_nd->port));
			SET_UDP_SEQ(&buf[sizeof(struct ip6_hdr)], (uint32_t)(*(&random[3])));
			SET_UDP_ACK(&buf[sizeof(struct ip6_hdr)], ipv4_checksum((uint16_t *)buf, sizeof(struct udphdr)));
		}
	}
	return (ret);
}

