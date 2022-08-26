/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmap_sety_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:13:55 by leon              #+#    #+#             */
/*   Updated: 2022/08/26 11:01:18 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmap_structs.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <pcap/pcap.h>
#include <netdb.h>
#include <string.h>
#include "proty_tcp.h"

#include <stdio.h>

#define NMAP_OK			0
#define NMAP_ERROR		-1

/* ST : t_func_sety_st */
int					set_sockaddr(t_nmap_setting *root, t_nmap_link *link, uint32_t index)
{
	int						r 			= NMAP_OK;
	struct 		addrinfo	hints		= {0};
	struct 		addrinfo	*res		= NULL;
//	char					host[32];
//	char					*host;

//	host = root->ips[index];
	if (!root || !link)
	{
		r = NMAP_ERROR;
	}
	else
	{
		memset(&hints, 0, sizeof(hints));
		hints.ai_family = AF_UNSPEC;
		hints.ai_flags = 0;
		r = getaddrinfo(root->ips[index], NULL, &hints, &res);
		if (r != 0)
		{
			dprintf(2, "%s: Name or service not known\n", root->ips[index]);
			r = NMAP_ERROR;
		}
		if (r == NMAP_OK)
		{
	//		bzero(link->host, 32);
	//		memcpy(link->host, host, strlen(host));

	//		bzero(host, 32);
	//		memcpy(host, host, strlen(host));
			fprintf(stderr, "res->ai_addr.s_family=%x", res->ai_addr->sa_family);
			memcpy(&link->sock, res->ai_addr, sizeof(struct sockaddr_storage));
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
