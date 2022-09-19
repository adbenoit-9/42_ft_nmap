/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:38:11 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/19 10:36:27 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmap.h"

static int	setup_root(t_root *root, t_nmap_setting *settings)
{
	int	r = 0;
	/* Update size of tree params */
	root->st_nb = settings->ip_nb;
	root->nd_nb = settings->port_nb;
	root->rd_nb = settings->scan_nb;
	/* Fill parameters in tree */
	if (set_iter_st(root, set_sockaddr))
		r = -1;
	if (set_iter_st(root, set_src_sockaddr))
		r = -1;
	if (set_iter_nd(root, iter_set_port))
		r = -1;
	if (set_iter_rd(root, iter_set_tcpflag))
		r = -1;
	return (r);
}

int main(int ac, char **av)
{
	int32_t 			r		= 0;
	uint8_t				*buf;
	t_nmap_controller	controller;
	t_nmap_setting		*settings = NULL;
	
	buf = (uint8_t*)malloc(SIZE);
	bzero(buf, SIZE);
	if (buf == NULL) {
		r = -1;
	}
	if (r == 0) {
		controller.status = NMAP_RUN;
		if (pthread_mutex_init(&controller.mutex, NULL) == -1) {
			r = -1;
		}
		else {
			controller.root = (t_root*)buf;
			controller.root->map = &buf[sizeof(t_root)];
			settings = &controller.root->client;
			/* Parsing */
			r = parser(ac, av, settings);
			if (r == PARSY_OK) {
				r = setup_root(controller.root, settings);
				ft_nmap(&controller);
			}
			else if (r == PARSY_STOP)
				r = PARSY_KO;
		}
	}
	clean_settings(settings);
	free(buf);
	return (r);
}
