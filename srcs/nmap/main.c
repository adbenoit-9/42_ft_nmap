/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:38:11 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/15 14:12:26 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/time.h>
#include "nmap.h"
#include "nmap_mapy_config.h"

static	double elapse_time(struct timeval *begin, struct timeval *end)
{
	double begin_sec = begin->tv_sec + (double)begin->tv_usec / 1000000;
	double end_sec = end->tv_sec + (double)end->tv_usec / 1000000;

	return (end_sec - begin_sec);
}

int main(int ac, char **av)
{
	int32_t 		r		= 0;
	uint8_t			*buf;
	t_root			*root;
	t_nmap_setting	*settings;
	struct timeval	begin, end;
	
	
	buf = (uint8_t*)malloc(SIZE);
	bzero(buf, SIZE);
	if (buf == NULL) {
		r = -1;
	}
	if (r == 0) {
		root = (t_root*)buf;
		root->map = &buf[sizeof(t_root)];
		settings = &root->client;
		/* Parsing */
		r = parser(ac, av, settings);
		if (r == PARSY_OK) {
			/* Update size of tree params */
			((t_root*)buf)->st_nb = settings->ip_nb;
			((t_root*)buf)->nd_nb = settings->port_nb;
			((t_root*)buf)->rd_nb = settings->scan_nb;
			/* Fill parameters in tree */
			if (set_iter_st(root, set_sockaddr))
				return (-1);
			if (set_iter_st(root, set_src_sockaddr))
				return (-1);
			if (set_iter_nd(root, iter_set_port))
				return (-1);
			if (set_iter_rd(root, iter_set_tcpflag))
				return (-1);
			signal(SIGALRM, handle_signal);
			display_config(settings);
			alarm(1);
			gettimeofday(&begin, NULL);
			scany(settings, root);
			gettimeofday(&end, NULL);
			display_report(root, elapse_time(&begin, &end));
		}
		else if (r == PARSY_STOP)
			r = PARSY_KO;
	}
	return (r);
}
