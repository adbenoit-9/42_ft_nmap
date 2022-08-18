/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recy_ipv6_udp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 21:06:41 by leon              #+#    #+#             */
/*   Updated: 2022/08/18 21:28:48 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO LMA 
// We can avoid polling
//			- using select
//			- using pcap

#include "recy.h"

int 				recv_ipv6_udp(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec)
{
	int				r = RECY_OK;
	uint32_t		sockaddrlen = sizeof(struct sockaddr_in);
	uint32_t		seq = 0;
	uint32_t		seqverif = 0;
	uint16_t		flag;

//	fprintf(stderr, "%s:%d\n", __func__, __LINE__);
	if (!buf || !conf_st || !conf_nd || !conf_exec)
	{
		r = RECY_ERROR;
	}
	else
	{
		GET_TCP_SEQ(&buf[sizeof(struct iphdr)], seq);
		seq = htonl(seq);
		seq += 1;
		while (r != -1 && seq != htonl(seqverif) && seq - 1 != htonl(seqverif))
		{
			r = recvfrom(((t_nmap_scan*)conf_exec)->socket, buf,
				((t_nmap_scan*)conf_exec)->packet_length - 4, 0,
				 (struct sockaddr*)&((t_nmap_app*)conf_st)->sock, &sockaddrlen);
			GET_TCP_ACK(&buf[sizeof(struct iphdr)], seqverif);
//			fprintf(stderr, "seq = %08x ack = %08x\n", seq, htonl(seqverif));
		}
		if (r != -1)
		{
			//print_packet(buf, length);
			GET_TCP_FLAGS(&buf[sizeof(struct iphdr)], flag);
			((t_nmap_scan*)conf_exec)->scan_result = flag;
			r = RECY_OK;
//			fprintf(stderr, "flag received = %04x\n", flag);
		}
	}
	return (r);
}
