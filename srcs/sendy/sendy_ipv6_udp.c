/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sendy_ipv6_udp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 20:11:57 by leon              #+#    #+#             */
/*   Updated: 2022/08/23 14:49:25 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sendy.h"
#include "proty_ip.h"
#include "proty_tcp.h"

int 				send_ipv6_udp(uint8_t *buf, void *conf_st, void *conf_nd,
														void *conf_exec)
{
	int			r		= SENDY_OK;
	int			sock;

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
			
			sock = socket(AF_INET6, SOCK_RAW, IPPROTO_UDP);
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
	}
	return (r);
}
