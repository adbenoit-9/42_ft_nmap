/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:14:59 by leon              #+#    #+#             */
/*   Updated: 2022/08/08 21:28:19 by leon             ###   ########.fr       */
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

// ips as described in ft_nmap_send.h

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
		SET_TCP_DPORT(&tcp_buf[offset], port->port);
	}
	if ((scans_flag & S_UDP) != 0)
	{
		SET_UDP_DPORT(&udp_buf[offset], port->port);
	}
	// TODO LMA : let the kernel set the SPORT ?
	// TODO LMA 1 fonction par scan ?
	while ((ret == FT_NMAP_OK) && (scans_flag != (uint8_t)0x00))
	{
		if ((scans_flag & S_SYN) != 0) {
			scans_flag &= ~S_SYN;
			// ret = syn_scan(ip, port, tcp_buf);
			(void)ip;
		}
		else if ((scans_flag & S_NULL) != 0x00) {
			scans_flag &= ~S_NULL;
		}
		else if ((scans_flag & S_ACK) != 0x00) {
			scans_flag &= ~S_ACK;
		}
		else if ((scans_flag & S_FIN) != 0x00) {
			scans_flag &= ~S_FIN;
		}
		else if ((scans_flag & S_XMAS) != 0x00) {
			scans_flag &= ~S_XMAS;
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
					SET_TCP_WIN(tcp_buf, 0x0004);
					SET_TCP_URP(tcp_buf, 0x0000);
				}
				if ((ret == FT_NMAP_OK) && ((opt->scans & NMAP_SCANS_FLAG_UDP) != 0))
				{
					ret = build_udp_ip_raw(&udp_buf);
				}
				// TODO LMA even if we are in raw ip hdr, we can safely
				// let the kernel add src_addr and dst_addr to buffer ?
				if (ret == FT_NMAP_OK)
				{
					ret = scan_port(ip, (t_port*)head->content, opt, udp_buf, tcp_buf);
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
