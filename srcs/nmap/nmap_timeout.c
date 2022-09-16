/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmap_timeout.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:04:44 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/16 16:19:54 by adbenoit         ###   ########.fr       */
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
	uint64_t		    count;
	uint64_t		    index;
	t_blk			    *blk;
	t_nmap_blkhdr	    *hdr;
    struct timeval      tv;
	
    while (get_status(controller) == NMAP_RUN)
    {
        count = 0;
        for (int i = 0; i < controller->root->st_nb; i++) {
            for (int j = 0; j < controller->root->nd_nb; j++) {
                for (int k = 0; k < controller->root->rd_nb; k++, count++) {
                    index = (count % BLCK_NB) * sizeof(t_blk);
                    blk = (t_blk*)&controller->root->map[index];
                    hdr = (t_nmap_blkhdr *)(blk->map);
                    gettimeofday(&tv, NULL);
                    pthread_mutex_lock(&hdr->time_mutex);
                    if (hdr->pcap_time.tv_usec && elapse_time(&hdr->pcap_time, &tv) > 1.0) {
                        pcap_breakloop(hdr->pcap_handler);
                    }
                    pthread_mutex_unlock(&hdr->time_mutex);
                }
            }
        }
    }
	return (NULL); 
}
