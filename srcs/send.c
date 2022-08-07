/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:14:59 by leon              #+#    #+#             */
/*   Updated: 2022/08/07 22:43:10 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap.h"
#include "ft_nmap_send.h"
#include "ft_nmap_build.h"
#include "ft_nmap_tcp.h"
#include "ft_nmap_ip.h"

// ips as described in ft_nmap_send.h

static int32_t					scan_port(t_ip *ip, t_port *port, t_opt *opt,
								uint8_t *tcp_buf, uint8_t *udp_buf)
{
	int32_t			ret = FT_NMAP_OK;
	uint8_t			scans_flag;

	scans_flag = opt->scans;
	if ((scans_flag & NMAP_SCANS_FLAG_ANY_TCP) != 0)
	{
		SET_TCP_DPORT(&tcp_buf[sizeof(struct iphdr)], port->port); // TODO LMA sizeof ip6 if INET6 in ip
	}
	if ((scans_flag & NMAP_SCANS_FLAG_UDP) != 0)
	{
		//SET_UDP_DPORT(&tcp_buf[sizeof(iphdr)], port->port); // TODO LMA
	}
	// TODO LMA : let the kernel set the SPORT ?
	// TODO LMA 1 fonction par scan ?
	while ((ret == FT_NMAP_OK) && (scans_flag != (uint8_t)0x00))
	{
		if ((scans_flag & NMAP_SCANS_FLAG_SYN) != 0) {
			scans_flag &= ~NMAP_SCANS_FLAG_SYN;
			// ret = syn_scan(ip, port, tcp_buf);
			(void)ip;
		}
		else if ((scans_flag & NMAP_SCANS_FLAG_NULL) != 0x00) {
			scans_flag &= ~NMAP_SCANS_FLAG_NULL;
		}
		else if ((scans_flag & NMAP_SCANS_FLAG_ACK) != 0x00) {
			scans_flag &= ~NMAP_SCANS_FLAG_ACK;
		}
		else if ((scans_flag & NMAP_SCANS_FLAG_FIN) != 0x00) {
			scans_flag &= ~NMAP_SCANS_FLAG_FIN;
		}
		else if ((scans_flag & NMAP_SCANS_FLAG_XMAS) != 0x00) {
			scans_flag &= ~NMAP_SCANS_FLAG_XMAS;
		}
		else if ((scans_flag & NMAP_SCANS_FLAG_UDP) != 0x00) {
			scans_flag &= ~NMAP_SCANS_FLAG_UDP;
			(void)udp_buf;
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
				}
				if ((ret == FT_NMAP_OK) && ((opt->scans & NMAP_SCANS_FLAG_UDP) != 0))
				{
					ret = build_udp_ip_raw(&udp_buf);
				}
				// TODO LMA even if we are in raw ip hdr, we can safely
				// let the kernel add src addr and dst_addr to buffer ?
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

int32_t					scan_start(t_list *ips, t_opt *opt)
{
	int32_t		ret = FT_NMAP_OK;
	t_list		*head;

	if (!ips || !opt)
	{
		ret = FT_NMAP_ERROR;
	}
	else
	{
		head = ips;
		// start_thread(opt.nb_of_thread);
		while (head && (ret == FT_NMAP_OK))
		{
			if (!((t_ip*)head->content)->done) // If ip not done go into it
			{
				ret = scan_ip((t_ip*)head->content, opt);
			}
			head = head->next;
		}
		// close_thread ?
	}
	return (ret);
}
