/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sety_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:13:55 by leon              #+#    #+#             */
/*   Updated: 2022/08/21 18:50:11 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmap_structs.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include "proty_tcp.h"

#include <stdio.h>

#define NMAP_OK			0
#define NMAP_ERROR		-1

/* ST : t_func_sety_st */
int					set_sockaddr(t_nmap_setting *root, t_nmap_link *link)
{
	int						r 			= NMAP_OK;
	struct 		addrinfo	hints		= {0};
	struct 		addrinfo	*res		= NULL;

	if (!root || !link)
	{
		r = NMAP_ERROR;
	}
	else
	{
		memset(&hints, 0, sizeof(hints));
		hints.ai_family = AF_UNSPEC;
		hints.ai_flags = 0;
		r = getaddrinfo("localhost", NULL, &hints, &res);
		if (r != 0)
		{
			r = NMAP_ERROR;
		}
		if (r == NMAP_OK)
		{
			memcpy(&link->sock, res->ai_addr, sizeof(struct sockaddr_storage));
			freeaddrinfo(res);
		}
	}
	//fprintf(stderr, "%s:%d r=%d\n", __func__, __LINE__, r);
	return (r);
}

/* ND : t_func_sety_nd */
int					set_port(t_nmap_setting *root, t_nmap_link *link, t_nmap_app *app)
{
	(void)root;
	(void)link;
	app->port = 4242;
//	fprintf(stderr, "%s:%d\n", __func__, __LINE__);
	return (NMAP_OK);
}

int					set_socket(t_nmap_setting *root, t_nmap_link *link, t_nmap_app *app)
{
	int				r = NMAP_OK;
	int				optval = 1;

	if (!root || !link || !app)
	{
		r = NMAP_ERROR;
	}
	else
	{
		app->socket = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
		if (app->socket < 0)
		{
			r = NMAP_ERROR;
		}
		if (r == NMAP_OK)
		{
			if (setsockopt(app->socket, IPPROTO_IP, IP_HDRINCL,
							&optval, sizeof(int)) < 0)
			{
				r = NMAP_ERROR;
			}
		}
	}
	fprintf(stderr, "%s:%d r=%d\n", __func__, __LINE__, r);
	return (r);
}

/* RD : t_func_sety_rd */
int					set_tcpflag(t_nmap_setting *root, t_nmap_link *link, t_nmap_app *app, t_nmap_scan *scan)
{
	(void)root;
	(void)link;
	(void)app;
	scan->tcpflag = FLAG_S_SYN;
	return (NMAP_OK);
}
