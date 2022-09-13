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

	if (!buf || !conf_st || !conf_nd || !conf_exec)
	{
		r = SETUPY_KO;
	}
	else
	{
	}
	return (r);
}
