/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setupy_ipv4_udp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 20:11:57 by leon              #+#    #+#             */
/*   Updated: 2022/09/19 15:33:39 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setupy.h"

int 				setup_ipv4_udp(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec)
{
	int			r		= SETUPY_OK;
       	int			optval		= 1;
	t_nmap_blkhdr		*blkhdr		= (t_nmap_blkhdr*)buf;

	if (!buf || !conf_st || !conf_nd || !conf_exec)
	{
		r = SETUPY_ERROR;
	}
	else
	{
		blkhdr->socklen = sizeof(struct sockaddr_in);
		blkhdr->socket = socket(AF_INET, SOCK_RAW, IPPROTO_UDP);
		blkhdr->result = 0;
		if (((t_nmap_link*)conf_st)->socket < 0)
		{
			perror("socket");
			r = SETUPY_ERROR;
		}
		if (r == SETUPY_OK)
		{
			if (setsockopt(blkhdr->socket, IPPROTO_IP, IP_HDRINCL,  &optval, sizeof(int)) < 0)
			{
				perror("setsockopt");
				r = SETUPY_ERROR;
			}
		}
		if (r == SETUPY_OK)
		{
			/* Note BUFSIZ is defined in stdio for std buffer : 8192 */
			if (r == 0)
			{
				pthread_mutex_lock(&blkhdr->time_mutex);
				blkhdr->pcap_handler = pcap_open_live(((t_nmap_link*)conf_st)->dev_name,
					BUFSIZ, 1, PCAP_BUFFER_TIMEOUT, NULL);
				if (blkhdr->pcap_handler == NULL)
				{
					perror("pcap_open_live");
					r = SETUPY_ERROR;
				}
				pthread_mutex_unlock(&blkhdr->time_mutex);
			}
		}
	}
	return (r);
}
