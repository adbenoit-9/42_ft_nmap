/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_setupy.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 23:30:20 by leon              #+#    #+#             */
/*   Updated: 2022/08/18 19:56:16 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUPY_EXPORT
# define SETUPY_EXPORT

#include "mappy.h"

#ifdef MAP_CMD_INDEX
# define SETUPY_CMD_INDEX MAP_CMD_INDEX
#endif


/* Exported functions */
int 				setup_ipv4_tcp(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec);
int 				setup_ipv4_udp(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec);
int 				setup_ipv6_tcp(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec);
int 				setup_ipv6_udp(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec);

t_func_mappy _setupy_exec[MAPPY_MAX_EXECUTION_HOOK] = {
		setup_ipv4_tcp,
		setup_ipv4_udp,
		setup_ipv6_tcp,
		setup_ipv6_udp,
		NULL,
		NULL,
		NULL,
		NULL,
};

// This macro can be used for setup hook index 
// This will be used by setty

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
