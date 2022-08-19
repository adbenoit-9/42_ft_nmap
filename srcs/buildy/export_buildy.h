/* ************************************************************************** */
/*                                                                            */ /*                                                        :::      ::::::::   */
/*   export_buildy.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 01:52:24 by leon              #+#    #+#             */
/*   Updated: 2022/08/19 01:22:02 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILDY_EXPORT
# define BUILDY_EXPORT

#include "mappy.h"

#ifdef MAP_CMD_INDEX
# define BUILDY_CMD_INDEX MAP_CMD_INDEX
#endif

/* Exported function */
int 				build_ipv4_tcp(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec);
int 				build_ipv4_udp(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec);
int 				build_ipv6_tcp(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec);
int 				build_ipv6_udp(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec);

t_func_mappy _buildy_exec[MAPPY_MAX_EXECUTION_HOOK] = {
		build_ipv4_tcp,
		build_ipv4_udp,
		build_ipv6_tcp,
		build_ipv6_udp,
		NULL,
		NULL,
		NULL,
		NULL,
};

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
