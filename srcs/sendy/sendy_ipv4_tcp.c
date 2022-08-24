/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sendy_ipv4_tcp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 20:11:57 by leon              #+#    #+#             */
/*   Updated: 2022/08/24 07:01:52 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sendy.h"
#include "proty_tcp.h"
#include <unistd.h>

// int 				send_ipv4_udp(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec);
// int 				send_ipv6_tcp(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec);
// int 				send_ipv6_udp(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec);

//int 				send_ipv4_tcp(uint8_t *buf, t_nmap_link *conf_st, t_nmap_app *conf_nd, t_nmap_scan *conf_exec)

int 				send_ipv4_tcp(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec)
{
	int			r		= SENDY_OK;

	if (!buf || !conf_st || !conf_nd || !conf_exec)
	{
		r = SENDY_ERROR;
	}
	else
	{
			/* Send this scan */
#ifdef SENDY_DEBUG
			fprintf(stderr, "%s:%d\n", __func__, __LINE__);
#endif /* SENDY_DEBUG */
			int optval = 1;
			int sock = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
			if (sock == -1)
			{
				perror("socket");
				return (-1);
			}
			if (setsockopt(sock, IPPROTO_IP, IP_HDRINCL,  &optval, sizeof(int)) < 0)
			{
				perror("setsockopt");
				return (-1);
			}
			if (((t_nmap_link*)conf_st)->sock.ss_family == AF_INET)
			{
				r = sendto(sock,
						buf,
						((t_nmap_scan*)conf_exec)->packet_length,
						0,
						(const struct sockaddr*)&((t_nmap_link*)conf_st)->sock,
						sizeof(struct sockaddr));
			}
			else
			{
				r = sendto(sock,
						buf,
						((t_nmap_scan*)conf_exec)->packet_length,
						0,
					 	(const struct sockaddr*)&((t_nmap_link*)conf_st)->sock,
						sizeof(struct sockaddr_in6));
			}
			if (r < 0)
			{
				perror("sendto");
				r = SENDY_ERROR;
			}
			else
			{
				r = SENDY_OK;
			}
			close(sock);
		//	recv_ipv4_tcp(buf, conf_st, conf_nd, conf_exec);
	}
	return (r);
}
