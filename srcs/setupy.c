/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setupy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 20:11:57 by leon              #+#    #+#             */
/*   Updated: 2022/08/16 01:03:45 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>

#include "ft_nmap_structs.h"

#define SETUPY_OK	0
#define SETUPY_ERROR	-1

int 				setup_net(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec)
{
	int			r		= SETUPY_OK;
	int			optval	= 1;

	if (!buf || !conf_st || !conf_nd)
	{
		r = SETUPY_ERROR;
	}
	else
	{
		//fprintf(stderr, "%s:%d\n", __func__, __LINE__);
		/* Request a socket */
		((t_scan*)conf_exec)->socket = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
		if (((t_scan*)conf_exec)->socket < 0)
		{
			// TODO on error update status in conf_exec
			fprintf(stderr, "%s:%d socket call failed, are you root ?\n", __func__, __LINE__);
			r = SETUPY_ERROR;
		}
		if (r == SETUPY_OK)
		{
			if (setsockopt(((t_scan*)conf_exec)->socket, IPPROTO_IP, IP_HDRINCL,
							&optval, sizeof(int)) < 0)
			{
				// TODO on error update status in conf_exec
				perror("setsockopt");
				r = SETUPY_ERROR;
			}
		}
	}
	return (r);
}
