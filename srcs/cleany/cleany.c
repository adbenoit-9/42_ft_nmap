/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleany.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 20:11:57 by leon              #+#    #+#             */
/*   Updated: 2022/09/19 15:04:47 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleany.h"
#include <pthread.h>

int 				clean_net(uint8_t *map, void *root, void *link, void *app)
{
	int			r		= CLEANY_OK;
	t_nmap_blkhdr		*blkhdr		= (t_nmap_blkhdr*)map;

	(void)map;
	if (!root || !link || !app)
	{
		r = CLEANY_ERROR;
	}
	else
	{
#ifdef DEBUG
		fprintf(stderr, "%s:%d\n", __func__, __LINE__);
#endif /* DEBUG */
		/* Close a socket */
		close(blkhdr->socket);
		blkhdr->socket = 0;
		
		pthread_mutex_lock(&blkhdr->time_mutex);
		pcap_close(blkhdr->pcap_handler);
		pthread_mutex_unlock(&blkhdr->time_mutex);
	}
	return (r);
}

