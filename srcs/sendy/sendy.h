/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sendy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:52:55 by leon              #+#    #+#             */
/*   Updated: 2022/09/13 17:24:33 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_NMAP_SENDY_H
# define FT_NMAP_SENDY_H

#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

#include "nmap_structs.h"

#define SENDY_OK	0
#define SENDY_ERROR	-1

# define SELECT_HOOK_SENDY(sockaddr, nd, hook) do { \
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
