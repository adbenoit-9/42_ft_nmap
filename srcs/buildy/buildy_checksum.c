/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildy_checksum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:41:49 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/13 15:44:08 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <net/if.h>
#include <ifaddrs.h>
#include "nmap_structs.h"
#include "proty_ip.h"

// TODO bufferriser avec une static
// 4096 bytes should do it


uint16_t			checksum(uint16_t *addr, int len)
{
	int							nleft;
	int							sum;
	uint16_t					*w;
	uint16_t					answer;

	answer = 0;
	w = addr;
	sum = 0;
	nleft = len;
	while (nleft > 1)
	{
		sum += *w++;
		nleft -= sizeof(uint16_t);
	}
	if (nleft == 1)
	{
		*(uint16_t*)(&answer) = *(uint16_t*)w;
		sum += answer;
	}
	sum = (sum >> 16) + (sum & 0xFFFF);
	sum += (sum >> 16);
	answer = ~sum;
	return (answer);
}

#include <netinet/ip.h>
#include <stdio.h>

uint16_t			tcp_ipv4_checksum(uint8_t *ip, uint16_t tcplen)
{
	uint8_t						tcp[64] = {0};
	int							offset = 0;
	uint16_t					tmp;

	memcpy(&tcp[offset], &ip[12], 4); // saddr
	offset += 4;
	memcpy(&tcp[offset], &ip[16], 4); // daddr
	offset += 4;
	offset += 1; // zero
	memcpy(&tcp[offset], &ip[9], 1); // protocol
	offset += 1;
	tmp = htons(tcplen);
	memcpy(&tcp[offset], &tmp, 2);
	offset += 2;
	memcpy(&tcp[offset], &ip[sizeof(struct iphdr)], tcplen);
	offset += tcplen;
	
	return (checksum((uint16_t*)tcp, offset));
}

uint16_t	ipv6_checksum(uint8_t *ip, uint16_t tcplen, uint8_t nxt_hdr)
{
	uint8_t		tcp[64] = {0};
	int			offset = 0;
	uint32_t	len;

	memcpy(&tcp[offset], &ip[8], 16); // saddr
	offset += 16;
	memcpy(&tcp[offset], &ip[24], 16); // daddr
	offset += 16;
	len = htonl(tcplen);
	memcpy(&tcp[offset], &len, 4);
	offset += 4;
	offset += 3; // zero
 	memcpy(&tcp[offset], &nxt_hdr, 1);
	offset += 1;
	memcpy(&tcp[offset], &ip[sizeof(struct ip6_hdr)], tcplen);
	offset += tcplen;
	return (checksum((uint16_t*)tcp, offset));
}
