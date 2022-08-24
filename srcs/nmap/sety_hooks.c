/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sety_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:13:55 by leon              #+#    #+#             */
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
	char					*host;

	host = root->ips[index];
	if (!root || !link)
	{
		r = NMAP_ERROR;
	}
	else
	{
		memset(&hints, 0, sizeof(hints));
		hints.ai_family = AF_UNSPEC;
		hints.ai_flags = 0;
		r = getaddrinfo(host, NULL, &hints, &res);
		if (r != 0)
		{
			dprintf(2, "%s: Name or service not known\n", host);
			r = NMAP_ERROR;
		}
		if (r == NMAP_OK)
		{
			bzero(link->host, 32);
			memcpy(link->host, host, strlen(host));
			memcpy(&link->sock, res->ai_addr, sizeof(struct sockaddr_storage));
			freeaddrinfo(res);
		}
	}
	//fprintf(stderr, "%s:%d r=%d\n", __func__, __LINE__, r);
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
		//app->socket = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
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
	fprintf(stderr, "%s:%d r=%d\n", __func__, __LINE__, r);
	return (r);
}


/* ND : t_func_sety_nd */
int					set_port(t_nmap_setting *root, t_nmap_link *link, t_nmap_app *app,
			t_nmap_scan *scan)
{
	(void)root;
	(void)link;
	(void)scan;
	app->port = 4242;
//	fprintf(stderr, "%s:%d\n", __func__, __LINE__);
	return (NMAP_OK);
}

/* RD : t_func_sety_rd */
int					set_tcpflag(t_nmap_setting *root, t_nmap_link *link, t_nmap_app *app,
			t_nmap_scan *scan)
{
	(void)root;
	(void)link;
	(void)app;
	scan->tcpflag = FLAG_S_SYN;
	return (NMAP_OK);
}
