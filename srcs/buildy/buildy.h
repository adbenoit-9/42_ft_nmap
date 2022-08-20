/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildy.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 21:25:20 by leon              #+#    #+#             */
/*   Updated: 2022/08/19 20:15:14 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILDY_H
# define BUILDY_H

#include <stdint.h>
#include <string.h>

#include "mappy.h"
#include "ft_nmap_structs.h"

#include "proty_ip.h"
#include "proty_tcp.h"
#include "proty_udp.h"
#include "buildy_utils.h"

#define BUILDY_OK	0
#define BUILDY_ERROR -1

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
