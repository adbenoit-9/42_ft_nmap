/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setupy_ipv6_udp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 20:11:57 by leon              #+#    #+#             */
/*   Updated: 2022/08/18 21:26:36 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setupy.h"

int 				setup_ipv6_udp(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec)
{
	int			r		= SETUPY_OK;
	int			optval		= 1;

	if (!buf || !conf_st || !conf_nd || !conf_exec)
	{
		r = SETUPY_ERROR;
	}
	else
	{
        	((t_nmap_link*)conf_st)->socklen = sizeof(struct sockaddr_in6);
        	((t_nmap_link*)conf_st)->socket = socket(AF_INET6, SOCK_RAW, IPPROTO_UDP);
		if (((t_nmap_link*)conf_st)->socket < 0)
		{
			perror("socket");
			r = SETUPY_ERROR;
		}
		if (r == SETUPY_OK)
		{
			if (setsockopt(((t_nmap_link*)conf_st)->socket, IPPROTO_IPV6, IPV6_HDRINCL,  &optval, sizeof(int)) < 0)
			{
				perror("setsockopt");
				r = SETUPY_ERROR;
			}
		}
	}
	return (r);
}
