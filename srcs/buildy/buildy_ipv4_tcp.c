/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildy_ipv4_tcp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 02:04:56 by leon              #+#    #+#             */
/*   Updated: 2022/09/16 17:40:58 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buildy.h"
#include <string.h>
#include "mapy.h"
#include <arpa/inet.h>

#include "nmap_structs.h"

int	build_ipv4_tcp(uint8_t *buf, T_CLIENT_ST *conf_st, T_CLIENT_ND *conf_nd,
					T_CLIENT_RD *conf_exec)
{
	int				ret			= BUILDY_OK;
	uint8_t			random[16]	= {0};
	uint8_t			tcpoff		= 5;
	uint32_t		length, i;
	in_addr_t		dip;

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
		length = sizeof(struct tcphdr) + sizeof(struct iphdr);
		i = sizeof(struct iphdr);

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

		/* setup IP header */
		dip = ((struct sockaddr_in *)&conf_st->sock)->sin_addr.s_addr;
		SET_IP4_SADDR(buf, ((struct sockaddr_in*)&conf_st->src_sock)->sin_addr.s_addr);
		SET_IP4_DADDR(buf, dip);
		SET_IP4_VERSION(buf, 0x04);
		SET_IP4_IHL(buf, 0x05);
		SET_IP4_TOS(buf, 0x00);
		SET_IP4_PROTOCOL(buf, IPPROTO_TCP);
		SET_IP4_FRAG_OFF(buf, 0x0000);
		SET_IP4_ID(buf, (uint16_t)(*(&random[0])));
		random[2] |= (1 << 5);
		random[2] &= 0x3F;
		SET_IP4_TTL(buf, (uint8_t)(*(&random[2])));
		SET_IP4_TOT_LEN(buf, htons(length));

		SET_IP4_CHECK(buf, checksum((uint16_t*)buf, sizeof(struct iphdr)));
		SET_TCP_SUM(&buf[i], ipv4_checksum(buf, length - sizeof(struct iphdr)));
	}
	return (ret);
}

