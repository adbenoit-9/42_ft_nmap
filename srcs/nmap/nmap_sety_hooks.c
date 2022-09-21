/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmap_sety_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:13:55 by leon              #+#    #+#             */
/*   Updated: 2022/09/21 12:44:12 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/socket.h>
#include <pcap/pcap.h>
#include <netdb.h>
#include <string.h>
#include "proty_tcp.h"
#include "nmap_structs.h"

#include <stdio.h>
#include <stdbool.h>
#include <net/if.h>
#include <ifaddrs.h>

/* ST : t_func_sety_st */
int					set_src_sockaddr(t_nmap_setting *root, t_nmap_link *link, uint32_t index)
{
	int		r = NMAP_OK;
	struct ifaddrs	*top_saddr;
	struct ifaddrs	*saddr;
	bool			b = 0;

	(void)root;
	(void)index;
	if (getifaddrs(&top_saddr) < 0)
	{
		r = NMAP_ERROR;
	}
	saddr = top_saddr;
	while (saddr && b == 0 && r == NMAP_OK)
	{
		if (saddr->ifa_addr->sa_family == link->sock.ss_family && (saddr->ifa_flags & IFF_RUNNING))
		{
			if ((htonl(((struct sockaddr_in*)&link->sock)->sin_addr.s_addr) ==
			INADDR_LOOPBACK ||
			IN6_IS_ADDR_LOOPBACK(((struct sockaddr_in6*)&link->sock)->sin6_addr.s6_addr)) && (saddr->ifa_flags & IFF_LOOPBACK) != 0) {
				memcpy(&link->src_sock, (struct sockaddr_storage *)saddr->ifa_addr,
				(((struct sockaddr_storage *)saddr->ifa_addr)->ss_family == AF_INET ? sizeof(struct sockaddr_in) : sizeof(struct sockaddr_in6)));
				bzero(link->dev_name, 32);
				memcpy(link->dev_name, saddr->ifa_name, strlen(saddr->ifa_name));
				b = 1;
			}
			else if ((saddr->ifa_flags & IFF_LOOPBACK) == 0) {
				memcpy(&link->src_sock, (struct sockaddr_storage *)saddr->ifa_addr, 
				(((struct sockaddr_storage *)saddr->ifa_addr)->ss_family == AF_INET ? sizeof(struct sockaddr_in) : sizeof(struct sockaddr_in6)));
				bzero(link->dev_name, 32);
				memcpy(link->dev_name, saddr->ifa_name, strlen(saddr->ifa_name));
				b = 1;
			}
		}
		saddr = saddr->ifa_next;
	}
	freeifaddrs(top_saddr);
	return (r);
}

int					set_sockaddr(t_nmap_setting *root, t_nmap_link *link, uint32_t index)
{
	int						r 			= NMAP_OK;
	struct 		addrinfo	hints		= {0};
	struct 		addrinfo	*res		= NULL;

	if (!root || !link) {
		r = NMAP_ERROR;
	}
	else {
		memset(&hints, 0, sizeof(hints));
		hints.ai_family = root->addr_family;
		hints.ai_flags = 0;
		r = getaddrinfo(root->ips[index], NULL, &hints, &res);
		if (r == EAI_ADDRFAMILY) {
			dprintf(2, "ft_nmap: %s: address family not supported\n", root->ips[index]);
			r = NMAP_ERROR;
		}
		else if (r != 0) {
			dprintf(2, "ft_nmap: %s: name or service not known\n", root->ips[index]);
			r = NMAP_ERROR;
		}
		if (r == NMAP_OK) {
			memcpy(&link->sock, res->ai_addr, (res->ai_family == AF_INET ?\
				sizeof(struct sockaddr_in) : sizeof(struct sockaddr_in6)));
			freeaddrinfo(res);
		}
	}
	return (r);
}

int					set_socket(t_nmap_setting *root, t_nmap_link *link, t_nmap_app *app,
			t_nmap_scan *scan)
{
	int				r = NMAP_OK;
	int				optval = 1;

	(void)app;
	(void)scan;
	if (!root || !link)
	{
		r = NMAP_ERROR;
	}
	else
	{
		link->socket = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
		if (link->socket < 0)
		{
			r = NMAP_ERROR;
			perror("socket");
		}
		if (r == NMAP_OK)
		{
			if (setsockopt(link->socket, IPPROTO_IP, IP_HDRINCL,
							&optval, sizeof(int)) < 0)
			{
				r = NMAP_ERROR;
				perror("setsockopt");
			}
		}
	}
	return (r);
}

int					dump_config_nd(t_nmap_setting *root, t_nmap_link *link, t_nmap_app *app,
			t_nmap_scan *scan)
{
	(void)root;
	(void)link;
	(void)scan;
	fprintf(stderr, "port=%d\n", app->port);
	return (0);
}
