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

#include <stdio.h>

#include "mappy.h"
#include "sendy.h"
#include <pthread.h>
# include <string.h>
# include "ft_nmap_parsing.h"
# include "libft.h"

//# include "ft_nmap_sendy.h"
//# include "ft_nmap_error.h"
#define RUNNY_OK 0
#define RUNNY_ERROR -1

static		uint8_t		buf[MAPPY_SIZE + SETY_SIZE];


int main(int ac, char **av)
{
	int32_t 		r = RUNNY_OK;
	uint8_t			*buf;
	t_nmap_config	opt;

	if (buf == NULL)
	{
		r = RUNNY_ERROR;
	}
	if (r == RUNNY_OK)
	{
		/* Set buffer config and map */
		opt.map = buf;
		opt.config = &buf[MAPPY_SIZE];

		/* Now fill opt with cmdline options */
		opt = parsy_getopt(ac, av, opt);

		/* Set opt tasks + elements_nb -> function sety_root_hook ? */
		opt.elements_nb = 0x42;
		int i = 0;
		while (j < opt.elements_nb)
		{
			/* Cmd target */
			/* Hook target */
		}
		r = sety_root(&opt);
		r = mappy(&opt);

//		for (uint8_t i = 0; i < 250; i++) {
//			if (pthread_create(&threads[i], NULL, (void *)routine, opt) != 0)
//				fatal_error(-1, "thread_create: failed", opt);
//		}
//		for (uint8_t i = 0; i < 250; i++) {
//			pthread_join(threads[i], NULL);
//		}
	}
	return (r);
}
