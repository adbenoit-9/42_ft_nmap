/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sendy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 20:11:57 by leon              #+#    #+#             */
/*   Updated: 2022/08/16 01:07:21 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>

#include "ft_nmap_structs.h"

#define SENDY_OK	0
#define SENDY_ERROR	-1

// #define SENDY_DEBUG

int 				send_ip(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec)
{
	int			r		= SENDY_OK;

	if (!buf || !conf_st || !conf_nd)
	{
		r = SENDY_ERROR;
	}
	else
	{
			/* Send this scan */
#ifdef SENDY_DEBUG
			fprintf(stderr, "%s:%d\n", __func__, __LINE__);
#endif /* SENDY_DEBUG */
			
			if (((t_link*)conf_st)->sock.ss_family == AF_INET)
			{
				r = sendto(((t_scan*)conf_exec)->socket, buf, ((t_scan*)conf_exec)->packet_length, 0,
						(const struct sockaddr*)&((t_link*)conf_st)->sock, sizeof(struct sockaddr_in));
			}
			else
			{
				r = sendto(((t_scan*)conf_exec)->socket, buf, ((t_scan*)conf_exec)->packet_length, 0,
					 (const struct sockaddr*)&((t_link*)conf_st)->sock, sizeof(struct sockaddr_in6));
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
