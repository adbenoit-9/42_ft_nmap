/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_sendy.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 01:52:24 by leon              #+#    #+#             */
/*   Updated: 2022/08/18 19:56:04 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SENDY_EXPORT
# define SENDY_EXPORT

#include "mappy.h"

#ifdef MAP_CMD_INDEX
# define SENDY_CMD_INDEX MAP_CMD_INDEX
#endif


/* Exported function */
int 				send_ipv4_tcp(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec);
int 				send_ipv4_udp(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec);
int 				send_ipv6_tcp(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec);
int 				send_ipv6_udp(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec);

t_func_mappy _sendy_exec[MAPPY_MAX_EXECUTION_HOOK] = {
		send_ipv4_tcp,
		send_ipv4_udp,
		send_ipv6_tcp,
		send_ipv6_udp,
		NULL,
		NULL,
		NULL,
		NULL,
};

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
