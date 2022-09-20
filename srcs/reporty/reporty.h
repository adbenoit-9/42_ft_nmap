/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reporty.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:27:55 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/20 11:35:02 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPORTY_H
# define REPORTY_H

# include <stdint.h>
# include <stdio.h>
# include <unistd.h>

/* Project Header */
# include "mapy.h"
# include "analysy.h"
# include "proty_tcp.h"
# include "proty_udp.h"
# include "libft.h"
# include "reporty_tcp_services.h"
# include "reporty_udp_services.h"

# define BORDER1 "-------------------------------------------------------------\
------------------------------------------------------------------------------"
# define BORDER2 ".............................................................\
.............................................................................."
# define SPACES "                                                             "
# define PRECISION(len_prec_val, len_prec_zone, val) (int)(len_prec_zone - len_prec_val + ft_strlen(val))
# define HDR_PRECISION(len_prec_val, len_prec_zone, len_val) (int)(len_prec_zone - len_prec_val + len_val)

/* report final */
# define HEADER_FORMAT		"%s\n%s%*s%*s%*s\n%.*s\n"
# define PORT_REPORT_FORMAT	"%d%*s%*s%*s\n"
# define PORT_ZONE_SIZE		10
# define SERV_ZONE_SIZE		30
# define RES_ZONE_SIZE		35
# define CONCL_ZONE_SIZE	15

/* report blk */
# define BLK_HDR_FORMAT		"%s%*s%*s%*s\n"
# define BLK_REPORT_FORMAT	"%.*f%*s%*d%*s\n\n"
# define TIME_ZONE_SIZE		15
# define IP_ZONE_SIZE		(INET6_ADDRSTRLEN + 1)
# define SCAN_ZONE_SIZE		10

#define REPORTY_OK      0
#define REPORTY_ERROR   -1

int     num_len(int num);
void    dns_resolution(void *sockaddr, char *ipstr, char *dest);
int     dns(void *sockaddr, char *ipstr, char *dest);
double	elapse_time(struct timeval *begin, struct timeval *end);

#endif
