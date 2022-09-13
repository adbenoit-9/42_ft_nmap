/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setupy.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 23:43:41 by leon              #+#    #+#             */
/*   Updated: 2022/09/13 17:24:33 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SETUPY_H
# define SETUPY_H

#include <stdint.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>

/* Project header */
#include "nmap_structs.h"

#include "proty_ip.h"
#include "proty_tcp.h"
#include "proty_udp.h"

#define SETUPY_OK 0
#define SETUPY_KO -1

# define SELECT_HOOK_SETUPY(sockaddr, nd, hook) do { \
if (((struct sockaddr_storage *)sockaddr)->ss_family == AF_INET) { \
	if (nd == FLAG_S_UDP) { \
		hook = 1; \
}	else { \
		hook = 0; \
}} else { \
	if (nd == FLAG_S_UDP){ \
		hook = 3; \
}	else { \
		hook = 2; \
	} \
} \
} while (0)

#endif
