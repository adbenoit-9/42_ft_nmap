/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setupy_ipv4_udp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 20:11:57 by leon              #+#    #+#             */
/*   Updated: 2022/08/22 19:24:41 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setupy.h"

int 				setup_ipv4_udp(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec)
{
	int			r		= SETUPY_OK;
       	int			optval		= 1;

	if (!buf || !conf_st || !conf_nd || !conf_exec)
	{
		r = SETUPY_ERROR;
	}
	else
	{
		((t_nmap_link*)conf_st)->socklen = sizeof(struct sockaddr);
		((t_nmap_link*)conf_st)->socket = socket(AF_INET, SOCK_RAW, IPPROTO_UDP);
		if (((t_nmap_link*)conf_st)->socket < 0)
		{
			perror("socket");
			r = SETUPY_ERROR;
		}
		if (r == SETUPY_OK)
		{
			if (setsockopt(((t_nmap_link*)conf_st)->socket, IPPROTO_IP, IP_HDRINCL,  &optval, sizeof(int)) < 0)
			{
				perror("setsockopt");
				r = SETUPY_ERROR;
			}
		}
	}
	return (r);
}
