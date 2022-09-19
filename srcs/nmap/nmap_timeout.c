/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmap_timeout.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:04:44 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/19 10:36:49 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmap.h"
#include <pthread.h>

static int  get_status(t_nmap_controller *controller)
{
    int status;

    pthread_mutex_lock(&controller->mutex);
    status = controller->status;
    pthread_mutex_unlock(&controller->mutex);
    return (status);
}

void    *handle_timeout(void *attr)
{
    t_nmap_controller   *controller = (t_nmap_controller *)attr;
	uint64_t		    index;
	t_blk			    *blk;
	t_nmap_blkhdr	    *hdr;
    struct timeval      tv;

    while (attr && get_status(controller) == NMAP_RUN)
    {
        index = 0;
        while (index < BLCK_NB * sizeof(t_blk)) {
            blk = (t_blk*)&controller->root->map[index];
            hdr = (t_nmap_blkhdr *)(blk->map);
            gettimeofday(&tv, NULL);
            pthread_mutex_lock(&hdr->time_mutex);
            if (hdr->pcap_handler && hdr->send_time &&
                    tv.tv_sec - hdr->send_time > 1) {
                pcap_breakloop(hdr->pcap_handler);
            }
            pthread_mutex_unlock(&hdr->time_mutex);
			index += sizeof(t_blk);
        }
    }
	return (NULL); 
}
