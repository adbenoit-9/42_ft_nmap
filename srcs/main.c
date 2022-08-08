/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:12:32 by adbenoit          #+#    #+#             */
/*   Updated: 2022/08/08 21:27:07 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap.h"
#include "ft_nmap_build.h"
#include "ft_nmap_ip.h"
#include "ft_nmap_tcp.h"

#include <stdio.h>

static void	print_ipv4(uint8_t *buffer)
{
	int i = 0;
	printf("IPHDR :\n");
	while (i < 20) {
		printf("%02x ", buffer[i++]);
	}
	printf("\n");
}

static void	print_tcp(uint8_t *buffer)
{
	int i = 0;
	printf("TCPHDR :\n");
	while (i < 20) {
		printf("%02x ", buffer[i++]);
	}
	printf("\n");
}


int main(int ac, char **av)
{
	uint8_t *tcp_buf = NULL;
	int32_t ret;
	t_opt	opt;

	opt = parser(ac, av);
	// scan_start(&opt);
	ret = build_tcp_ip_raw(&tcp_buf);
	print_ipv4(tcp_buf);
	SET_IP4_VERSION(tcp_buf, 0x04);
	SET_IP4_IHL(tcp_buf, 0x05);
	SET_IP4_TOS(tcp_buf, 0x00);
	SET_IP4_PROTOCOL(tcp_buf, 0x06);
	SET_IP4_FRAG_OFF(tcp_buf, 0x0000);
	SET_TCP_WIN(&tcp_buf[sizeof(struct iphdr)], 0x0004);
	SET_TCP_URP(&tcp_buf[sizeof(struct iphdr)], 0x0000);
	SET_TCP_DPORT(&tcp_buf[sizeof(struct iphdr)], 42);
	SET_IP4_TOT_LEN(&tcp_buf[sizeof(struct iphdr)], 
				sizeof(struct iphdr) + sizeof(struct tcphdr));
	SET_IP4_ID(&tcp_buf[sizeof(struct iphdr)], 0xDEAD);
	SET_IP4_TTL(&tcp_buf[sizeof(struct iphdr)], 0xAA);
	SET_TCP_SEQ(&tcp_buf[sizeof(struct iphdr)], 0xBABEFACE);
	SET_TCP_OFF(&tcp_buf[sizeof(struct iphdr)], 0x05);
	print_ipv4(tcp_buf);
	print_tcp(&tcp_buf[sizeof(struct iphdr)]);
	ft_lstclear(&opt.ip_lst, clear_ip);
	return (ret);
}
