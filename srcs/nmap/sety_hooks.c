/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sety_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:13:55 by leon              #+#    #+#             */
/*   Updated: 2022/08/23 17:37:45 by adbenoit         ###   ########.fr       */
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

int			set_pcap_init(t_nmap_setting *root, t_nmap_link *link, t_nmap_app *app,
			t_nmap_scan *scan)
{
	int					r 						= NMAP_OK;
	pcap_if_t			*alldevs				= NULL;
	char				err[PCAP_ERRBUF_SIZE]	= {0};
	pcap_t 				*pcap					= NULL;

	(void)app;
	(void)scan;
	if (!root || !link)
	{
		r = NMAP_ERROR;
	}
	else
	{
		r = pcap_findalldevs(&alldevs, err);
		/* Note we cannot capture WiFi target as is , so check */
		if (r == 0)
		{
			while (alldevs && (alldevs->flags & PCAP_IF_LOOPBACK) == 0)
			{
				// fprintf(stderr, "%s: name = %s\n", __func__, alldevs->name);
				// fprintf(stderr, "%s: description = %s\n", __func__, alldevs->description);
				// fprintf(stderr, "%s: flag = %08x\n\n", __func__, alldevs->flags);
				alldevs = alldevs->next;
			}
			fprintf(stderr, "%s: Selected dev: name = %s\n", __func__, alldevs->name); 
		}
		/* Note BUFSIZ is defined in stdio for std buffer : 8192 */
		if (r == 0)
		{
			pcap = pcap_open_live(alldevs->name, BUFSIZ, 1, 1000, err);
			if (pcap == NULL)
			{
				r = NMAP_ERROR;
			}
		}
		if (r == 0)
		{
			// TODO save src addr too (only the one corresponding to this link layer)
			link->pcap_handler = pcap;
			pcap_freealldevs(alldevs);
		}
	}
	if (r == PCAP_ERROR)
	{
		fprintf(stderr, "%s,%d", __func__, __LINE__);
		pcap_perror(pcap, "open_live:");
		while (1)
			;
	}
	return (r);
}

int			set_pcap_close(t_nmap_setting *root, t_nmap_link *link, t_nmap_app *app,
			t_nmap_scan *scan)
{
	(void)root;
	(void)app;
	(void)scan;
	fprintf(stderr, "%s:%d\n", __func__, __LINE__);
	pcap_close(link->pcap_handler);
	return (NMAP_OK);
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
