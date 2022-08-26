/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_setupy.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 23:30:20 by leon              #+#    #+#             */
/*   Updated: 2022/08/22 18:20:32 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUPY_EXPORT
# define SETUPY_EXPORT

#include "mappy.h"

#ifdef MAP_CMD_INDEX
# define SETUPY_CMD_INDEX MAP_CMD_INDEX
#endif


/* Exported functions */
int 				setup_ipv4_tcp(uint8_t *buf, T_CLIENT_ST *conf_st, T_CLIENT_ND *conf_nd, T_CLIENT_RD *conf_exec);
// int 				setup_ipv4_udp(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec);
// int 				setup_ipv6_tcp(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec);
// int 				setup_ipv6_udp(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec);

#define SELECT_HOOK_SETUPY(sockaddr, nd, hook) do { \
if (((struct sockaddr_storage *)sockaddr).ss_family == AF_INET) { \
	if (nd == NMAP_UDP) { \
		hook = 1; \
}	else { \
		hook = 0; \
}else { \
	if { \
		hook = 3; \
}	else { \
		hook = 2; \
	} \
} \
} while (0)

#endif
