/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 20:11:57 by leon              #+#    #+#             */
/*   Updated: 2022/08/19 01:24:13 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** buildy
*/



//static const	uint8_t		template_ipv4[20] = {
//	0x45, 0x0, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//	0x00, 0x00, 0x00, 0x00 };
//
//static const	uint8_t		template_tcp[20] = {
//	0x45, 0x0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//	0x00, 0x00, 0x00, 0x00 };

//int 				build_ipv4_tcp(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec)
//{
//	int			r			= BUILDY_OK;
//	uint8_t		random[16]	= {0};
//	uint8_t		tcpoff		= 0;
//	uint32_t	length;
//
//	if (!buf || !conf_st || !conf_nd || !conf_exec)
//	{
//		r = BUILDY_ERROR;
//	}
//	else
//	{
//#ifdef BUILDY_DEBUG
//		fprintf(stderr, "%s:%d scantype=%02x\n", __func__, __LINE__, 
//									((t_scan*)conf_exec)->tcpflag);
//#endif /* BUILDY_DEBUG */
//		memset(buf, 0, MAPPY_MAX_BUFFER_SIZE);
////		memcpy(buf, template_ipv4, 20);
////		memcpy(&buf[20], template_tcp, 20);
//		r = get_urandom(random, 16);
//		if (r == BUILDY_OK)
//		{
//
//			uint32_t	dip; // DEBUG
//			inet_pton(AF_INET, "127.0.0.1", &dip); // DEBUG
//			SET_IP4_DADDR(buf, dip); // DEBUG
//			SET_IP4_SADDR(buf, dip); // DEBUG
//
//			SET_IP4_VERSION(buf, 0x04);
//			SET_IP4_IHL(buf, 0x05);
//			SET_IP4_TOS(buf, 0x00);
//			SET_IP4_PROTOCOL(buf, 0x06);
//			SET_IP4_FRAG_OFF(buf, 0x0000);
//			SET_IP4_ID(buf, (uint16_t)(*(&random[0])));
//			SET_IP4_TTL(buf, (uint8_t)(*(&random[2]))); //ttl);
//			SET_TCP_SEQ(&buf[sizeof(struct iphdr)], (uint32_t)(*(&random[3])));
//			SET_TCP_SPORT(&buf[sizeof(struct iphdr)], (uint16_t)(*(&random[7])));
//			SET_TCP_WIN(&buf[sizeof(struct iphdr)], 0x0004);
//			SET_TCP_URP(&buf[sizeof(struct iphdr)], 0x0000);
//			length = sizeof(struct iphdr) + sizeof(struct tcphdr);
//			tcpoff = 5;
//			//((t_scan*)conf_exec)->tcpflag = FLAG_S_SYN; // TODO LMA DEBUG
//			if (((t_nmap_scan*)conf_exec)->tcpflag == FLAG_S_SYN)
//			{
//	   			length += 4;
//				tcpoff++;
//	   			SET_TCP_DATA(&buf[sizeof(struct iphdr)], syn_mss, 4);
//			}
//			SET_TCP_FLAGS(&buf[sizeof(struct iphdr)], ((t_nmap_scan*)conf_exec)->tcpflag); // TODO 
//			SET_TCP_DPORT(&buf[sizeof(struct iphdr)], htons(((t_nmap_app*)conf_nd)->port));
//			SET_TCP_OFF(&buf[sizeof(struct iphdr)], tcpoff);
//			SET_IP4_TOT_LEN(buf, htons(length));
//			SET_IP4_CHECK(buf, ipv4_checksum((uint16_t*)buf,
//					sizeof(struct iphdr)));
//			SET_TCP_SUM(&buf[sizeof(struct iphdr)], tcp_ipv4_checksum(buf, length - sizeof(struct iphdr)));
//			((t_nmap_scan*)conf_exec)->packet_length = length;
//		}
//	}
//	return (r);
//}
