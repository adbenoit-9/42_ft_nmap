/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildy_ipv6_tcp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 02:04:56 by leon              #+#    #+#             */
/*   Updated: 2022/09/21 17:31:32 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buildy.h"
#include <string.h>
#include "mapy.h"
#include "nmap_structs.h"

int	build_ipv6_tcp(uint8_t *buf, T_CLIENT_ST *conf_st, T_CLIENT_ND *conf_nd,
		T_CLIENT_RD *conf_exec)
{
	int				ret			= BUILDY_OK;
	uint8_t			random[16]	= {0};
	uint8_t			tcpoff		= 5;
	uint32_t		length, i;
	struct in6_addr	dip;

	if (!buf || !conf_st || !conf_nd || !conf_exec) {
		ret = BUILDY_ERROR;
	}
	else if (ret == BUILDY_OK) {
#ifdef DEBUG
		fprintf(stderr, "%s:%d scantype=%02x\n", __func__, __LINE__, conf_exec->packet_flag);
#endif /* DEBUG */
		buf = &buf[sizeof(t_nmap_blkhdr)];
		bzero(buf, MAP_BLCK_SIZE - sizeof(t_nmap_blkhdr));
		ret = get_urandom(random, 16);
		length = sizeof(struct tcphdr);
		i = sizeof(struct ip6_hdr);

		/* setup TCP header */
		SET_TCP_SEQ(&buf[i], (uint32_t)(*(&random[3])));
		SET_TCP_SPORT(&buf[i], (uint16_t)(*(&random[7])));
		SET_TCP_WIN(&buf[i], 0x0004);
		SET_TCP_URP(&buf[i], 0x0000);
		if (conf_exec->packet_flag == FLAG_S_SYN) {
			length += 4;
			++tcpoff;
			SET_TCP_DATA(&buf[i], syn_mss, 4);
		}
		SET_TCP_FLAGS(&buf[i], conf_exec->packet_flag);
		SET_TCP_DPORT(&buf[i], htons(conf_nd->port));
		SET_TCP_OFF(&buf[i], tcpoff);

		/* setup IP6 header */
		dip = ((struct sockaddr_in6 *)&conf_st->src_sock)->sin6_addr;
		SET_IP6_SRC(buf, dip);
		dip = ((struct sockaddr_in6 *)&conf_st->sock)->sin6_addr;
		SET_IP6_DST(buf, dip);
		SET_IP6_FLOW(buf, 0x42424242);
		SET_IP6_NXT(buf, IPPROTO_TCP);
		SET_IP6_HLIM(buf, (uint8_t)255);
		SET_IP6_VFC(buf, IPV6_VERSION, 0x0);
		SET_IP6_PLEN(buf, htons(length));

		SET_TCP_SUM(&buf[i], ipv6_checksum(buf, length, IPPROTO_TCP));
	}
	return (ret);
}

