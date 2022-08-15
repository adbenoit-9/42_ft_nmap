/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:14:59 by leon              #+#    #+#             */
/*   Updated: 2022/08/12 20:28:12 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** TODO : checksum ip, ip6, tcp, udp
** TODO : constant (to set at the beginning):
** 
**#define SET_IP4_VERSION(ip, value) do {((struct iphdr*)ip)->version =\
**					(uint8_t)value & (uint8_t)0x0F;} while (0)
** == 0x04
**#define SET_IP4_IHL(ip, value) do {((struct iphdr*)ip)->ihl =\
**					(uint8_t)value & (uint8_t)0x0F;} while (0)
** == 0x05
**#define SET_IP4_TOS(ip, value) do {((struct iphdr*)ip)->tos =\
**					(uint8_t)value;} while (0)
** == 0x00
**#define SET_IP4_PROTOCOL(ip, value) do {((struct iphdr*)ip)->protocol =\
**       				(uint8_t)value;} while (0)
** == 0x06 pour TCP
** == 0x11 pour UDP
**#define SET_TCP_URP(tcp, value) do {((struct tcphdr*)tcp)->th_urp =\
**       					(uint16_t)value;} while (0)
** == 0
** #define SET_TCP_WIN(tcp, value) do {((struct tcphdr*)tcp)->th_win =\
**        					(uint16_t)value;} while (0)
** -> Window size the sender want to receive, typically 0x0400
**
** #define SET_IP4_FRAG_OFF(ip, value) do {((struct iphdr*)ip)->frag_off =\
**        				(uint16_t)value;} while (0)
** == 0
**
** TODO : to set at the end :
** #define SET_IP4_TOT_LEN(ip, value) do {((struct iphdr*)ip)->tot_len =\
**        				(uint16_t)value;} while (0)
** -> total length
** #define SET_IP4_ID(ip, value) do {((struct iphdr*)ip)->id =\
** 					(uint16_t)value;} while (0)
**#define SET_IP4_TTL(ip, value) do {((struct iphdr*)ip)->ttl =\
**					(uint8_t)value;} while (0)
** #define SET_TCP_SEQ(tcp, value) do {((struct tcphdr*)tcp)->th_seq =\
**        					(uint32_t)value;} while (0)
** -> RNG : the kernel may do it ??
**#define SET_TCP_OFF(tcp, value) do {((struct tcphdr*)tcp)->th_off =\
**       					(uint8_t)value & (uint8_t)0x0F;} while (0)
** -> Size of TCP header in word, min 5, with MSS 6
*/

#include "ft_nmap.h"
#include "ft_nmap_send.h"
#include "ft_nmap_build.h"
#include "ft_nmap_tcp.h"
#include "ft_nmap_udp.h"
#include "ft_nmap_ip.h"
#include "ft_nmap_utils.h"

// ips as described in ft_nmap_send.h// 

static int32_t					set_flag(uint8_t *tcp_hdr, uint8_t flag)
{
	int			r = FT_NMAP_OK;

	if (!tcp_hdr)
	{
		r = FT_NMAP_ERROR;
	}
	else
	{
		if (flag == S_SYN)
		{
			SET_TCP_FLAGS(tcp_hdr, FLAG_S_SYN);
		}
		else if (flag == S_NULL)
		{
			SET_TCP_FLAGS(tcp_hdr, FLAG_S_NULL);
		}
		else if (flag == S_ACK)
		{
			SET_TCP_FLAGS(tcp_hdr, FLAG_S_ACK);
		}
		else if (flag == S_FIN)
		{
			SET_TCP_FLAGS(tcp_hdr, FLAG_S_FIN);
		}
		else if (flag == S_XMAS)
		{
			SET_TCP_FLAGS(tcp_hdr, FLAG_S_XMAS);
		}
		else
		{
			r = FT_NMAP_ERROR;
		}
	}
	return (r);
}

static int32_t					tcp_scan(t_ip *ip, t_port *port, uint8_t *tcp_buf, uint8_t flag)
{
	int			r				= FT_NMAP_OK;
	int32_t		length			= 0;
	uint16_t	tcpId			= 0;
	uint32_t	tcpSeq			= 0;
	uint8_t		ttl				= 0;

	if (!ip || !port || !tcp_buf)
	{
		r = FT_NMAP_OK;
	}
	else
	{
		if (ip->sock.ss_family == AF_INET)
		{
			get_urandom((uint8_t*)&tcpId, 2);
			get_urandom((uint8_t*)&tcpSeq, 4);
			while (ttl < 30)
				get_urandom(&ttl, 1);
			SET_IP4_ID(tcp_buf, tcpId);
			SET_IP4_TTL(tcp_buf, ttl);
			SET_TCP_SEQ(&tcp_buf[sizeof(struct iphdr)], tcpSeq);
			length = sizeof(struct iphdr) + sizeof(struct tcphdr);
			if (flag == S_SYN) /* Add MSS for S_SYN */
			{
				length += 4;
				SET_TCP_DATA(&tcp_buf[sizeof(struct iphdr)], syn_mss, 4);
				SET_TCP_OFF(&tcp_buf[sizeof(struct iphdr)], 6);
			}
			else
			{
				SET_TCP_OFF(&tcp_buf[sizeof(struct iphdr)], 5);
			}
			SET_IP4_TOT_LEN(tcp_buf, htons(length));
			r = set_flag(&tcp_buf[sizeof(struct iphdr)], flag);
			SET_IP4_CHECK(tcp_buf, ipv4_checksum((uint16_t*)tcp_buf, sizeof(struct iphdr)));
		}
		else
		{
		}
		printf("PACKET TYPE: %x ; Length = %d\n", flag, length);
		printf("PACKET : ");
		int j = 0;
		while (j < length - 1)
		{
			printf("%02x%02x ", tcp_buf[j], tcp_buf[j+1]);
			j += 2;
		}
		printf("\n");
	}
	return (r);
}

static int32_t					scan_port(t_ip *ip, t_port *port, t_opt *opt,
								uint8_t *tcp_buf, uint8_t *udp_buf)
{
	int32_t			ret = FT_NMAP_OK;
	uint8_t			scans_flag;
	int				offset;

	scans_flag = opt->scans;
	offset = (ip->sock.ss_family == AF_INET ? sizeof(struct iphdr) :
				sizeof(struct ip6_hdr));
	if ((scans_flag & S_ANYTCP) != 0)
	{
		SET_TCP_DPORT(&tcp_buf[offset], htons(port->port));
		SET_TCP_WIN(&tcp_buf[offset], 0x0004);
		SET_TCP_URP(&tcp_buf[offset], 0x0000);
	}
	if ((scans_flag & S_UDP) != 0)
	{
		SET_UDP_DPORT(&udp_buf[offset], htons(port->port));
	}
	// TODO LMA : let the kernel set the SPORT ?
	// TODO LMA 1 fonction par scan ?
	while ((ret == FT_NMAP_OK) && (scans_flag != (uint8_t)0x00))
	{
		if ((scans_flag & S_SYN) != 0) {
			scans_flag &= ~S_SYN;
			ret = tcp_scan(ip, port, tcp_buf, S_SYN);
		}
		else if ((scans_flag & S_NULL) != 0x00) {
			scans_flag &= ~S_NULL;
			ret = tcp_scan(ip, port, tcp_buf, S_NULL);
		}
		else if ((scans_flag & S_ACK) != 0x00) {
			scans_flag &= ~S_ACK;
			ret = tcp_scan(ip, port, tcp_buf, S_ACK);
		}
		else if ((scans_flag & S_FIN) != 0x00) {
			scans_flag &= ~S_FIN;
			ret = tcp_scan(ip, port, tcp_buf, S_FIN);
		}
		else if ((scans_flag & S_XMAS) != 0x00) {
			scans_flag &= ~S_XMAS;
			ret = tcp_scan(ip, port, tcp_buf, S_XMAS);
		}
		else if ((scans_flag & S_UDP) != 0x00) {
			scans_flag &= ~S_UDP;
		}
		else {
			scans_flag = 0; // should never reach this
		}
	}
	return (ret);
}

static int32_t					scan_ip(t_ip *ip, t_opt *opt)
{
	uint8_t			*tcp_buf;
	uint8_t			*udp_buf;
	uint8_t			lock_ip = 1;
	int32_t			ret = FT_NMAP_OK;
	t_list			*head;

	if (!ip || !opt)
	{
		ret = FT_NMAP_ERROR;
	}
	else
	{
		head = ip->ports;
		while (head && (ret == FT_NMAP_OK))
		{
			if (!(((t_port*)head->content)->lock))
			{
				((t_port*)head->content)->lock = 1;
				lock_ip = 0;
				if ((opt->scans & NMAP_SCANS_FLAG_ANY_TCP) != 0)
				{
					ret = build_tcp_ip_raw(&tcp_buf);
					SET_IP4_VERSION(tcp_buf, 0x04);
					SET_IP4_IHL(tcp_buf, 0x05);
					SET_IP4_TOS(tcp_buf, 0x00);
					SET_IP4_PROTOCOL(tcp_buf, 0x06);
					SET_IP4_FRAG_OFF(tcp_buf, 0x0000);
				}
				if ((ret == FT_NMAP_OK) && ((opt->scans & NMAP_SCANS_FLAG_UDP) != 0))
				{
					ret = build_udp_ip_raw(&udp_buf);
				}
				// TODO LMA even if we are in raw ip hdr, we can safely
				// let the kernel add src_addr and dst_addr to buffer ?
				if (ret == FT_NMAP_OK)
				{
					ret = scan_port(ip, (t_port*)head->content, opt, tcp_buf, udp_buf);
				}
			}
			head = head->next;
		}
	}
	if ((ret == FT_NMAP_OK) && (lock_ip != (uint8_t)0))
	{
		ip->done = 1;
	}
	return (ret);
}

void					routine(t_opt *opt)
{
	int32_t		ret = FT_NMAP_OK;
	t_list		*head = opt->ip_lst;
	
	while (head && (ret == FT_NMAP_OK))
	{
		if (!((t_ip*)head->content)->done) // If ip not done go into it
		{
			ret = scan_ip((t_ip*)head->content, opt);
		}
		head = head->next;
	}
	// return (NULL);
}

int32_t					scan_start(t_opt *opt)
{
	int32_t		ret = FT_NMAP_OK;
	pthread_t	threads[opt->speedup];

	if (!opt)
	{
		ret = FT_NMAP_ERROR;
	}
	else
	{
		for (uint8_t i = 0; i < opt->speedup; i++) {
			if (pthread_create(&threads[i], NULL, (void *)routine, opt) != 0)
				fatal_error(-1, "thread_create: failed", opt);
		}
		routine(opt);
		for (uint8_t i = 0; i < opt->speedup; i++) {
			pthread_join(threads[i], NULL);
		}
	}
	return (ret);
}
