/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildy_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 19:25:21 by leon              #+#    #+#             */
/*   Updated: 2022/09/13 18:27:05 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <net/if.h>
#include <ifaddrs.h>
#include <stdio.h>
#include "proty_ip.h"

int				get_urandom(uint8_t *buf, int length)
{
	int			randomfd;
	int			r = 0;
	uint8_t		tmp[512];
	int			offset = 0;

	if (!buf)
	{
		r = -1;
	}
	else
	{
		randomfd = open("/dev/urandom", O_RDONLY);
		if (randomfd < 0)
		{
			r = -1;
		}
		if (r == 0)
		{
			while ((r == 0) && offset < length)
			{
				if (read(randomfd, tmp, 512) < 0)
				{
					r = -1;
				}
				if (offset + 512 > length)
				{
					memcpy(&buf[offset], tmp, length % 512);
				}
				else
				{
					memcpy(&buf[offset], tmp, 512);
				}
				offset += 512;
			}
		}
		if (r == 0)
		{
			close(randomfd);
		}
	}
	return (r);
}

struct in6_addr	get_src_ipv6(struct in6_addr dest)
{
	struct ifaddrs	*saddr;
	struct in6_addr	sip;

	if (IN6_IS_ADDR_LOOPBACK(&dest)) {
		sip = dest;
	}
	else {
		printf("NOT LOOPBACK\n");
		getifaddrs(&saddr);
		sip = *(struct in6_addr *)saddr->ifa_addr;
		while (saddr && (saddr->ifa_addr->sa_family != AF_INET6
				|| saddr->ifa_flags & IFF_LOOPBACK)) {
			saddr = saddr->ifa_next;
			sip = *(struct in6_addr *)saddr->ifa_addr;
		}
	}
	return (sip);
}

in_addr_t	get_src_ipv4(in_addr_t dest)
{
	struct ifaddrs	*saddr;
	in_addr_t	sip;

	if (htonl(dest) != INADDR_LOOPBACK) {
		getifaddrs(&saddr);
		sip = ((struct sockaddr_in *)saddr->ifa_addr)->sin_addr.s_addr;
		while (saddr && (saddr->ifa_addr->sa_family != AF_INET
				|| saddr->ifa_flags & IFF_LOOPBACK)) {
			saddr = saddr->ifa_next;
			sip = ((struct sockaddr_in *)saddr->ifa_addr)->sin_addr.s_addr;
		}
	}
	else {
		sip = dest;
	}
	return (sip);
}
