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

#include <stdio.h>

#include "mappy.h"
#include "sendy.h"

int main(int ac, char **av)
{
	int32_t 		r = FT_NMAP_OK;
	uint8_t	*buf;
	t_opt	opt;

	buf = malloc(MAPPY_SIZE);
	if (buf == NULL)
	{
		r = FT_NMAP_ERROR;
	}
	if (r == FT_NMAP_OK)
	{
		opt = parser(ac, av);
		fprintf(stderr, "%s:%d\n", __func__, __LINE__);
		//scan_start(&opt);
		r = mappy(buf, opt.ip_lst);
	}
	if (r == FT_NMAP_OK)
	{
		ft_lstclear(&opt.ip_lst, clear_ip);
		free(buf);
	}
	return (r);
}
