/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildy_ipv4_tcp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 02:04:56 by leon              #+#    #+#             */
/*   Updated: 2022/08/23 23:57:16 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buildy.h"
#include <string.h>
#include "mapy.h"
#include <arpa/inet.h>

#include "nmap_structs.h"

//static const	uint8_t		template_ipv4[20] = {
//	0x45, 0x0, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//	0x00, 0x00, 0x00, 0x00 };
//
//static const	uint8_t		template_tcp[20] = {
//	0x45, 0x0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//	0x00, 0x00, 0x00, 0x00 };

int	build_ipv4_tcp(uint8_t *buf, T_CLIENT_ST *conf_st, T_CLIENT_ND *conf_nd,
					T_CLIENT_RD *conf_exec)
{
	int			ret			= BUILDY_OK;
	uint8_t		random[16]	= {0};
	uint8_t		tcpoff		= 0;
	uint32_t	length;
	uint32_t	dip;

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
		if (ret == BUILDY_OK)
		{
			dip = ((struct sockaddr_in *)&conf_st->sock)->sin_addr.s_addr;
			SET_IP4_DADDR(buf, dip);
			SET_IP4_SADDR(buf, dip);

			SET_IP4_VERSION(buf, 0x04);
			SET_IP4_IHL(buf, 0x05);
			SET_IP4_TOS(buf, 0x00);
			SET_IP4_PROTOCOL(buf, 0x06);
			SET_IP4_FRAG_OFF(buf, 0x0000);
			SET_IP4_ID(buf, (uint16_t)(*(&random[0])));
			SET_IP4_TTL(buf, (uint8_t)(*(&random[2]))); //ttl);
			SET_TCP_SEQ(&buf[sizeof(struct iphdr)], (uint32_t)(*(&random[3])));
			SET_TCP_SPORT(&buf[sizeof(struct iphdr)], (uint16_t)(*(&random[7])));
			SET_TCP_WIN(&buf[sizeof(struct iphdr)], 0x0004);
			SET_TCP_URP(&buf[sizeof(struct iphdr)], 0x0000);
			length = sizeof(struct iphdr) + sizeof(struct tcphdr);
			tcpoff = 5;
			if (conf_exec->tcpflag == FLAG_S_SYN)
			{
	   			length += 4;
				tcpoff++;
	   			SET_TCP_DATA(&buf[sizeof(struct iphdr)], syn_mss, 4);
			}
			SET_TCP_FLAGS(&buf[sizeof(struct iphdr)], conf_exec->tcpflag); // TODO 
			SET_TCP_DPORT(&buf[sizeof(struct iphdr)], __builtin_bswap16(conf_nd->port));
			SET_TCP_OFF(&buf[sizeof(struct iphdr)], tcpoff);
			SET_IP4_TOT_LEN(buf, htons(length));
			SET_IP4_CHECK(buf, ipv4_checksum((uint16_t*)buf,
					sizeof(struct iphdr)));
			SET_TCP_SUM(&buf[sizeof(struct iphdr)], tcp_ipv4_checksum(buf, length - sizeof(struct iphdr)));
			conf_exec->packet_length = length;
			printf("length: %d\n", length);
		}
	}
	return (ret);
}

