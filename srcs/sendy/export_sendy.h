/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_sendy.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 01:52:24 by leon              #+#    #+#             */
/*   Updated: 2022/08/22 19:35:00 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_SENDY_H
# define EXPORT_SENDY_H

#include "mapy.h"
/* Exported function */
int 				send_ipv4_tcp(uint8_t *buf, T_CLIENT_ST *conf_st, T_CLIENT_ND *conf_nd, T_CLIENT_RD *conf_exec);
int 				send_ipv4_udp(uint8_t *buf, T_CLIENT_ST *conf_st, T_CLIENT_ND *conf_nd, T_CLIENT_RD *conf_exec);
//int 				send_ipv6_tcp(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec);
//int 				send_ipv6_udp(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec);
#define SELECT_HOOK_SENDY(sockaddr, nd, hook) do { \
if (((struct sockaddr_storage *)sockaddr).ss_family == AF_INET) { \
	if (nd == NMAP_UDP) { \
		hook = 1; \
}	else { \
		hook = 0; \
}else { \
	if { \
		hook = 4; \
}	else { \
		hook = 3; \
	} \
} \
} while (0)


#endif
