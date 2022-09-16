/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sendy_udp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 20:11:57 by leon              #+#    #+#             */
/*   Updated: 2022/09/16 17:39:04 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sendy.h"
#include "proty_ip.h"

int send_udp(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec)
{
	int				ret		= SENDY_OK;
	t_nmap_blkhdr	*blkhdr		= (t_nmap_blkhdr*)buf;
	int				length;

	if (!buf || !conf_st || !conf_nd || !conf_exec) {
		ret = SENDY_ERROR;
	}
	else {
        /* Send this scan */
#ifdef DEBUG
			fprintf(stderr, "%s:%d\n", __func__, __LINE__);
#endif /* DEBUG */
		buf = &buf[sizeof(t_nmap_blkhdr)];
		if (((t_nmap_link*)conf_st)->sock.ss_family == AF_INET6) {
			length = ntohs(((struct ip6_hdr *)buf)->ip6_plen +
				sizeof(struct ip6_hdr));
		}
		else {
			length = ntohs(((struct iphdr *)buf)->tot_len);
		}
		ret = sendto(blkhdr->socket, buf, length, 0,
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
