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

#include <stdio.h>

#include "mappy.h"
#include "sendy.h"
#include <pthread.h>
//	BUILD_BUG_ON(sizeof()) ((void)sizeof(char[1 - 2*!!(condition)]))

#define 
static		uint8_t		set[];
static		uint8_t		map[MAPPY_SIZE + SETY_SIZE];

int main(int ac, char **av)
{
//	BUILD_BUG_ON(sizeof(buf))

	int32_t 		r = FT_NMAP_OK;
	uint8_t	*buf;
	t_nmap_setting		opt = {0};
//	pthread_t	threads[opt->speedup];

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
//		for (uint8_t i = 0; i < 250; i++) {
//			if (pthread_create(&threads[i], NULL, (void *)routine, opt) != 0)
//				fatal_error(-1, "thread_create: failed", opt);
//		}
		r = mappy(buf, opt.ip_lst);
//		for (uint8_t i = 0; i < 250; i++) {
//			pthread_join(threads[i], NULL);
//		}
	}
	if (r == FT_NMAP_OK)
	{
		ft_lstclear(&opt.ip_lst, clear_ip);
		free(buf);
	}
	return (r);
}
