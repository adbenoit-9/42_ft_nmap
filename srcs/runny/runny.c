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

#include "runny.h"

#include <stdio.h>

#include "mappy.h"
#include "sendy.h"
#include <pthread.h>

int main(int ac, char **av)
{
	int32_t 		r = RUNNY_OK;
	uint8_t	*buf;
	t_opt	opt;
	(void)opt;
//	pthread_t	threads[opt->speedup];

	buf = malloc(MAPPY_SIZE);
	if (buf == NULL)
	{
		r = RUNNY_ERROR;
	}
	if (r == RUNNY_OK)
	{
		opt = parser(ac, av);
		fprintf(stderr, "%s:%d\n", __func__, __LINE__);
		//scan_start(&opt);
//		for (uint8_t i = 0; i < 250; i++) {
//			if (pthread_create(&threads[i], NULL, (void *)routine, opt) != 0)
//				fatal_error(-1, "thread_create: failed", opt);
//		}
//		r = mappy(buf, opt.ip_lst);
//		for (uint8_t i = 0; i < 250; i++) {
//			pthread_join(threads[i], NULL);
//		}
	}
//	if (r == RUNNY_OK)
//	{
//		ft_lstclear(&opt.ip_lst, clear_ip);
		free(buf);
//	}
	return (r);
}
