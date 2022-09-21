/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:38:11 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/21 14:42:31 by adbenoit         ###   ########.fr       */
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
	if (r == 0 && set_iter_st(root, set_sockaddr)) {
		r = -1;
	}
	if (r == 0 && set_iter_st(root, set_src_sockaddr)) {
		r = -1;
	}
	if (r == 0 && set_iter_nd(root, iter_set_port)) {
		r = -1;
	}
	if (r == 0 && set_iter_rd(root, iter_set_tcpflag)) {
		r = -1;
	}
	return (r);
}

int main(int ac, char **av)
{
	int32_t 			r		= NMAP_OK;
	uint8_t				*buf;
	t_nmap_controller	controller;
	t_nmap_setting		*settings = NULL;

	buf = (uint8_t*)malloc(SIZE);
	if (buf == NULL) {
		r = NMAP_ERROR;
	}
	if (r == NMAP_OK) {
		bzero(buf, SIZE);
		controller.status = NMAP_RUN;
		if (pthread_mutex_init(&controller.mutex, NULL) < 0) {
			r = NMAP_ERROR;
		}
		else {
			controller.root = (t_root*)buf;
			controller.root->map = &buf[sizeof(t_root)];
			settings = &controller.root->client;
			if (pthread_mutex_init(&settings->display_mutex, NULL) < 0) {
				r = NMAP_ERROR;
			}
			else {
				r = parser(ac, av, settings);
			}
			if (r == PARSY_OK) {
				r = setup_root(controller.root, settings);
			}
			else if (r == PARSY_STOP)
				r = PARSY_KO;
			if (r == PARSY_OK) {
				ft_nmap(&controller);
			}
		}
	}
	clean_settings(settings);
	free(buf);
	return (r);
}
