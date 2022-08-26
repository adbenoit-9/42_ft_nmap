/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_buildy.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:52:52 by adbenoit          #+#    #+#             */
/*   Updated: 2022/08/22 15:52:55 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_BUILDY_H
# define DATA_BUILDY_H

#include "mapy.h"

/* Exported function */
int	build_ipv4_tcp(uint8_t *buf, T_CLIENT_ST *conf_st, T_CLIENT_ND *conf_nd, T_CLIENT_RD *conf_exec);
int	build_ipv4_udp(uint8_t *buf, T_CLIENT_ST *conf_st, T_CLIENT_ND *conf_nd, T_CLIENT_RD *conf_exec);
int	build_ipv6_tcp(uint8_t *buf, T_CLIENT_ST *conf_st, T_CLIENT_ND *conf_nd, T_CLIENT_RD *conf_exec);
int	build_ipv6_udp(uint8_t *buf, T_CLIENT_ST *conf_st, T_CLIENT_ND *conf_nd, T_CLIENT_RD *conf_exec);

#define SELECT_HOOK_BUILDY(sockaddr, nd, hook) do { \
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
