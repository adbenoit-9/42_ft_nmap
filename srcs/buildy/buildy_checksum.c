 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildy_checksum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:41:49 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/13 16:05:05 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "nmap_structs.h"
#include "proty_ip.h"

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

uint16_t			ipv4_checksum(uint8_t *ip, uint16_t len)
{
	uint8_t						hdr[64] = {0};
	int							offset = 0;
	uint16_t					tmp;

	memcpy(&hdr[offset], &ip[12], 4); // saddr
	offset += 4;
	memcpy(&hdr[offset], &ip[16], 4); // daddr
	offset += 4;
	offset += 1; // zero
	memcpy(&hdr[offset], &ip[9], 1); // protocol
	offset += 1;
	tmp = htons(len);
	memcpy(&hdr[offset], &tmp, 2);
	offset += 2;
	memcpy(&hdr[offset], &ip[sizeof(struct iphdr)], len);
	offset += len;

	return (checksum((uint16_t*)hdr, offset));
}

uint16_t	ipv6_checksum(uint8_t *ip, uint16_t len, uint8_t nxt_hdr)
{
	uint8_t		hdr[64] = {0};
	int			offset = 0;
	uint32_t	tmp;

	memcpy(&hdr[offset], &ip[8], 16); // saddr
	offset += 16;
	memcpy(&hdr[offset], &ip[24], 16); // daddr
	offset += 16;
	tmp = htonl(len);
	memcpy(&hdr[offset], &tmp, 4);
	offset += 4;
	offset += 3; // zero
 	memcpy(&hdr[offset], &nxt_hdr, 1);
	offset += 1;
	memcpy(&hdr[offset], &ip[sizeof(struct ip6_hdr)], len);
	offset += len;
	return (checksum((uint16_t*)hdr, offset));
}
