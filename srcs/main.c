/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:12:32 by adbenoit          #+#    #+#             */
/*   Updated: 2022/08/08 17:14:54 by adbenoit         ###   ########.fr       */
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
	uint8_t *buffer = NULL;
	int32_t ret;
	t_opt	opt;

	opt = parser(ac, av);
	(void)opt;
	ret = build_tcp_ip_raw(&buffer);
	print_ipv4(buffer);
	SET_IP4_VERSION(buffer, 0x4);
	SET_IP4_TTL(buffer, 0xFF);
	SET_TCP_SPORT(&buffer[sizeof(struct iphdr)], 0xDEAD);
	print_ipv4(buffer);
	print_tcp(&buffer[sizeof(struct iphdr)]);
	ft_lstclear(&opt.ip_lst, clear_ip);
	return (ret);
}
