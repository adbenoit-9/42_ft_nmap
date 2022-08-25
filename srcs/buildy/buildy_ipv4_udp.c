/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildy_ipv4_udp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 02:04:56 by leon              #+#    #+#             */
/*   Updated: 2022/08/25 16:57:02 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buildy.h"
#include <string.h>
#include "mapy.h"
#include <arpa/inet.h>
#include "nmap_structs.h"

int	build_ipv4_udp(uint8_t *buf, T_CLIENT_ST *conf_st, T_CLIENT_ND *conf_nd,
		T_CLIENT_RD *conf_exec)
{
	int			ret			= BUILDY_OK;
	uint8_t		random[16]	= {0};
	uint32_t	i = 0;
	
	if (!buf || !conf_st || !conf_nd || !conf_exec) {
		ret = BUILDY_ERROR;
	}
	else {
#ifdef BUILDY_DEBUG
		fprintf(stderr, "%s:%d scantype=%02x\n", __func__, __LINE__, 
									((t_scan*)conf_exec)->tcpflag);
#endif /* BUILDY_DEBUG */
		ret = get_urandom(random, 16);
		if (ret == BUILDY_OK) {
			conf_exec->packet_length = sizeof(struct udphdr);
#ifndef MAC
			uint32_t dip = ((struct sockaddr_in *)&conf_st->sock)->sin_addr.s_addr;
			struct ifaddrs	*saddr;
			getifaddrs(&saddr);
			conf_exec->packet_length += sizeof(struct iphdr);
			i = sizeof(struct iphdr);
			SET_IP4_DADDR(buf, dip);
			SET_IP4_SADDR(buf, saddr->ifa_addr); // DEBUG
			SET_IP4_VERSION(buf, 0x04);
			SET_IP4_IHL(buf, 0x05);
			SET_IP4_TOS(buf, 0x00);
			SET_IP4_PROTOCOL(buf, 0x06);
			SET_IP4_FRAG_OFF(buf, 0x0000);
			SET_IP4_ID(buf, (uint16_t)(*(&random[0])));
			SET_IP4_TTL(buf, (uint8_t)(*(&random[2])));
			SET_IP4_TOT_LEN(buf, htons(conf_exec->packet_length));
			SET_IP4_CHECK(buf, ipv4_checksum((uint16_t*)buf, sizeof(struct iphdr)));
#endif
			SET_UDP_SPORT(&buf[i], (uint16_t)(*(&random[7])));
			SET_UDP_DPORT(&buf[i], htons(conf_nd->port));
			SET_UDP_LEN(&buf[i], htons(conf_exec->packet_length));
			SET_UDP_ACK(&buf[i], ipv4_checksum((uint16_t *)buf, sizeof(struct udphdr)));
		}
	}
	return (ret);
}

