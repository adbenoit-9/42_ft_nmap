/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recy.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 21:26:38 by leon              #+#    #+#             */
/*   Updated: 2022/09/13 17:04:30 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECVY_H
# define RECVY_H

#include <stdint.h>
#include <netinet/ip.h>
#include <netinet/ip6.h>
#include <sys/types.h>
#include <sys/socket.h>

#include "proty_tcp.h" // TODO Avoid this dependency 
#include "nmap_structs.h"

#define RECY_OK 0
#define RECY_ERROR -1

# define SELECT_HOOK_RECY(sockaddr, nd, hook) do { \
if (((struct sockaddr_storage *)sockaddr)->ss_family == AF_INET) { \
	if (nd == FLAG_S_UDP) { \
		hook = 1; \
}	else { \
		hook = 0; \
}} else { \
	if (nd == FLAG_S_UDP){ \
		hook = 4; \
}	else { \
		hook = 3; \
	} \
} \
} while (0)

#endif
