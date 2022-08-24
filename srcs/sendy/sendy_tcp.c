/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sendy_tcp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 20:11:57 by leon              #+#    #+#             */
/*   Updated: 2022/08/24 13:23:37 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sendy.h"
#include "proty_ip.h"

int send_tcp(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec)
{
	int			ret		= SENDY_OK;
	int			sock;
	socklen_t	socklen;
//	fprintf(stdout, "%s:%d port=%d\n", __func__, __LINE__, ((t_nmap_app*)conf_nd)->port);
	if (!buf || !conf_st || !conf_nd || !conf_exec) {
		ret = SENDY_ERROR;
	}
	else {
        /* Send this scan */
#ifdef SENDY_DEBUG
//			fprintf(stderr, "%s:%d\n", __func__, __LINE__);
//			fprintf(stderr, "%s:%d ((t_nmap_link*)conf_st)->sock.ss_family = %d\n", __func__, __LINE__, ((t_nmap_link*)conf_st)->sock.ss_family);
#endif /* SENDY_DEBUG */
        if (((t_nmap_link*)conf_st)->sock.ss_family == AF_INET) {
            socklen = sizeof(struct sockaddr);
            sock = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
        }
        else {
            socklen = sizeof(struct sockaddr_in6);
            sock = socket(AF_INET6, SOCK_RAW, IPPROTO_TCP);
        }
#ifndef MAC
        int	optval	= 1;
        setsockopt(sock, IPPROTO_IP, IP_HDRINCL,  &optval, sizeof(int));
#endif
        ret = sendto(sock, buf,  ((t_nmap_scan*)conf_exec)->packet_length, 0,
            (const struct sockaddr*)&((t_nmap_link*)conf_st)->sock, socklen);
        if (ret < 0)  {
            perror("sendto");
            ret = SENDY_ERROR;
        }
        else {
            ret = SENDY_OK;
        }
        close(sock);
	}
	return (ret);
}
