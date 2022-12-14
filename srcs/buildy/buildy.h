/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildy.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 21:25:20 by leon              #+#    #+#             */
/*   Updated: 2022/09/13 17:24:33 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILDY_H
# define BUILDY_H

# include <stdint.h>
# include <string.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <ifaddrs.h>
# include <net/if.h>

# include "mapy.h"
# include "nmap_structs.h"
	 
# include "proty_ip.h"
# include "proty_tcp.h"
# include "proty_udp.h"
# include "buildy_utils.h"

# define BUILDY_OK	0
# define BUILDY_ERROR -1

# ifndef MAC

#  define IPV6_VERSION            0x60
#  define IPV6_VERSION_MASK       0xf0

#  if BYTE_ORDER == BIG_ENDIAN
#   define IPV6_FLOWINFO_MASK      0x0fffffff      /* flow info (28 bits) */
#   define IPV6_FLOWLABEL_MASK     0x000fffff      /* flow label (20 bits) */
#   define IPV6_FLOW_ECN_MASK      0x00300000      /* the 2 ECN bits */
#  else
#   if BYTE_ORDER == LITTLE_ENDIAN
#    define IPV6_FLOWINFO_MASK      0xffffff0f      /* flow info (28 bits) */
#    define IPV6_FLOWLABEL_MASK     0xffff0f00      /* flow label (20 bits) */
#    define IPV6_FLOW_ECN_MASK      0x00003000      /* the 2 ECN bits */
#   endif /* LITTLE_ENDIAN */
#  endif

# endif

#endif
