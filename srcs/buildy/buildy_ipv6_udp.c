/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildy_ipv6_udp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 02:04:56 by leon              #+#    #+#             */
/*   Updated: 2022/08/25 18:52:26 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buildy.h"
#include <string.h>
#include <stdio.h>
#include "mapy.h"
#include <arpa/inet.h>
#include "nmap_structs.h"

int build_ipv6_udp(uint8_t *buf, T_CLIENT_ST *conf_st, T_CLIENT_ND *conf_nd,
		T_CLIENT_RD *conf_exec)
{
	int				ret = BUILDY_OK;
	uint8_t			random[16] = {0};
	uint32_t		i;
	struct ifaddrs	*saddr;
	struct in6_addr	dip, sip;

	if (!buf || !conf_st || !conf_nd || !conf_exec) {
		ret = BUILDY_ERROR;
	}
	else if (ret == BUILDY_OK) {
#ifdef DEBUG
		fprintf(stderr, "%s:%d scantype=%02x\n", __func__, __LINE__, conf_exec->tcpflag);
#endif /* DEBUG */
		ret = get_urandom(random, 16);
			conf_exec->packet_length = sizeof(struct ip6_hdr) + sizeof(struct udphdr);
		i = sizeof(struct ip6_hdr);

		/* setup IP6 header */
		getifaddrs(&saddr);
		dip = ((struct sockaddr_in6 *)&conf_st->sock)->sin6_addr;
		sip = *(struct in6_addr *)saddr->ifa_addr;
		while (saddr && (saddr->ifa_addr->sa_family != AF_INET6 ||
				(IN6_IS_ADDR_LOOPBACK(&dip) && saddr->ifa_flags & IFF_LOOPBACK))) {
			saddr = saddr->ifa_next;
			sip = *(struct in6_addr *)saddr->ifa_addr;
		}
		SET_IP6_SRC(buf, sip);
		SET_IP6_DST(buf, dip);
		SET_IP6_FLOW(buf, 0x050b00); // DEBUG
		SET_IP6_NXT(buf, 0x11); // UDP
		SET_IP6_HLIM(buf, (uint8_t)(*(&random[2])));
		SET_IP6_VFC(buf, IPV6_VERSION, 0x0);
		SET_IP6_PLEN(buf, htons(sizeof(struct udphdr)));

		/* setup UDP header */
		SET_UDP_SPORT(&buf[i], (uint16_t)(*(&random[7])));
		SET_UDP_DPORT(&buf[i], htons(conf_nd->port));
		SET_UDP_LEN(&buf[i], htons(conf_exec->packet_length));
		SET_UDP_ACK(&buf[i], ipv4_checksum((uint16_t *)buf, sizeof(struct udphdr)));
	}
	return (ret);
}

