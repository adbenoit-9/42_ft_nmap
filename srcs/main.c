/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:12:32 by adbenoit          #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap.h"
#include "ft_nmap_build.h"
#include "ft_nmap_ip.h"
#include "ft_nmap_tcp.h"

#include <stdio.h>

int main(int ac, char **av)
{
	int32_t 		r = FT_NMAP_OK;
	uint8_t	*buf;
	t_opt	opt;

	buf = malloc(NMAP_BUFFER_SIZE);
	if (buf == NULL)
	{
		r = FT_NMAP_ERROR;
	}
	if (r == FT_NMAP_OK)
	{
		opt = parser(ac, av);
		//scan_start(&opt);
		r = sendy(buf, opt.ip_lst);
	}
	if (r == FT_NMAP_OK)
	{
		ft_lstclear(&opt.ip_lst, clear_ip);
		free(buf);
	}
	return (r);
}
