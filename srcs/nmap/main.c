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

#include "mapy.h"
#include <pthread.h>
# include <string.h>
# include "ft_nmap_parsing.h"
# include "ft_nmap_structs.h"
# include "libft.h"

//# include "ft_nmap_sendy.h"
//# include "ft_nmap_error.h"
#define NMAP_OK 0
#define NMAP_ERROR -1

static		uint8_t		buf[SIZE];
//	BUILD_BUG_ON(sizeof(set))

//root = (*t_root)buf;
//map = &buf[sizeof(t_root)];


int main(int ac, char **av)
{
	t_root			*root;
	t_nmap_setting	*conf;

	root = (t_root*)buf;
	conf = (t_nmap_setting*)&root->client;


	/* Now fill conf with cmdline options */

	// r = nmap_getopt(ac, av, conf);

	/* Now we have filled conf , update t_root */
	root->st_nb = conf->ip_nb;
	root->nd_nb = conf->port_nb;
	root->rd_nb = conf->scan_nb;

	/* Apply conf in sub config structs */
	r = set_st(root, setupy_getaddr);
	set_nd(root, setupy_socket);
//	set_nd(root, setupy_port);
//	set_rd(root, setupy_scan);

	root->map = &buf[sizeof(t_root)];

	mapy(root);
	/* Set opt tasks + elements_nb -> function nmap_config_branch_hook -> hooky ? */

		uint32_t j = 0;
		while (j < opt.cross.nb_elements)
		{
			/* Cmd target */
			/* Hook target */
		}
		r = sety_root((t_proto_root*)&opt);
		r = mappy((t_proto_root*)&opt);

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
