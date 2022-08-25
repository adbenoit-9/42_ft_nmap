/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmap_scany.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:23:46 by adbenoit          #+#    #+#             */
/*   Updated: 2022/08/25 18:39:32 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmap.h"

static void *run_mapy(void *root)
{
	mapy(root);
	return (NULL);
}

int	scany(t_nmap_setting *settings, t_root *root)
{
	int32_t		r = 0;
	int			thread_r;
	pthread_t	ph[settings->speedup];

	/* Pcap handler init */
	if (set_pcap_init(&root->client) != 0)
		return (-1);
	pthread_create(&root->client.thread, NULL, run_pcap, (void*)root);

	for (int i = 0; i < settings->speedup; i++) {
		pthread_create(&ph[i], NULL, run_mapy, (void *)root);
	}
	r = mapy(root);
	for (int i = 0; i < settings->speedup; i++) {
		pthread_join(ph[i], NULL);
	}
	pthread_join(root->client.thread, (void**)&thread_r);
    return (r);
}
