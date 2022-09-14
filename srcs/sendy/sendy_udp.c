/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sendy_udp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 20:11:57 by leon              #+#    #+#             */
/*   Updated: 2022/09/13 16:44:30 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sendy.h"
#include "proty_ip.h"

int send_udp(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec)
{
	int			ret		= SENDY_OK;
	t_nmap_blkhdr		*blkhdr		= (t_nmap_blkhdr*)buf;

	if (!buf || !conf_st || !conf_nd || !conf_exec) {
		ret = SENDY_ERROR;
	}
	else {
        /* Send this scan */
#ifdef DEBUG
			fprintf(stderr, "%s:%d\n", __func__, __LINE__);
#endif /* DEBUG */
		buf = &buf[sizeof(t_nmap_blkhdr)];
        	ret = sendto(blkhdr->socket, buf,  ((t_nmap_scan*)conf_exec)->packet_length, 0,
        	    (const struct sockaddr*)&((t_nmap_link*)conf_st)->sock, blkhdr->socklen);
        	if (ret < 0)  {
        	    perror("sendto");
        	    ret = SENDY_ERROR;
        	}
        	else {
        	    ret = SENDY_OK;
        	}
	}
	return (ret);
}
