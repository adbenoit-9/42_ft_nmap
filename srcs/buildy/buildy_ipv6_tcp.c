/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildy_ipv6_tcp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 02:04:56 by leon              #+#    #+#             */
/*   Updated: 2022/08/25 18:52:16 by adbenoit         ###   ########.fr       */
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
	uint8_t			tcpoff		= 5;
	uint32_t		length;
	uint32_t		i;
	struct ifaddrs	*saddr;
	struct in6_addr	sip, dip;

	// printf("ipv6 tcp\n");
	if (!buf || !conf_st || !conf_nd || !conf_exec) {
		ret = BUILDY_ERROR;
	}
	else if (ret == BUILDY_OK) {
#ifdef DEBUG
		fprintf(stderr, "%s:%d scantype=%02x\n", __func__, __LINE__, conf_exec->tcpflag);
#endif /* DEBUG */
		ret = get_urandom(random, 16);
		length = sizeof(struct ip6_hdr) + sizeof(struct tcphdr);
		i = sizeof(struct ip6_hdr);

		/* setup TCP header */
		SET_TCP_SEQ(&buf[i], (uint32_t)(*(&random[3])));
		SET_TCP_SPORT(&buf[i], (uint16_t)(*(&random[7])));
		SET_TCP_WIN(&buf[i], 0x0004);
		SET_TCP_URP(&buf[i], 0x0000);
		if (conf_exec->tcpflag == FLAG_S_SYN) {
			length += 4;
			++tcpoff;
			SET_TCP_DATA(&buf[i], syn_mss, 4);
		}
		conf_exec->packet_length = length;
		SET_TCP_FLAGS(&buf[i], conf_exec->tcpflag); // TODO 
		SET_TCP_DPORT(&buf[i], htons(conf_nd->port));
		SET_TCP_OFF(&buf[i], tcpoff);

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
		SET_IP6_FLOW(buf, 0);
		SET_IP6_NXT(buf, IPPROTO_TCP);
		SET_IP6_HLIM(buf, (uint8_t)(*(&random[2])));
		SET_IP6_VFC(buf, IPV6_VERSION, 0x0);
		SET_IP6_PLEN(buf, htons(length));

		SET_TCP_SUM(&buf[i], ipv6_checksum(buf, length - sizeof(struct ip6_hdr), IPPROTO_TCP));
	}
	return (ret);
}

