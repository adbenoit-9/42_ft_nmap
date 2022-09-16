/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reporty.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:27:55 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/16 13:02:58 by adbenoit         ###   ########.fr       */
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

# define HEADER_FORMAT "%s\n%s%*s%*s%*s\n%.*s\n"
# define PORT_REPORT_FORMAT "%d%*s%*s%*s\n"
# define BORDER1 "-------------------------------------------------------------\
------------------------------------------------------------------------------"
# define BORDER2 ".............................................................\
.............................................................................."
# define SPACES "                                                             "
# define PRECISION(len_prec_val, len_prec_zone, val) (int)(len_prec_zone - len_prec_val + ft_strlen(val))
# define HDR_PRECISION(len_prec_val, len_prec_zone, len_val) (int)(len_prec_zone - len_prec_val + len_val)
# define PORT_ZONE_SIZE     10
# define SERV_ZONE_SIZE     30
# define RES_ZONE_SIZE      33
# define CONCL_ZONE_SIZE    15

#define REPORTY_OK      0
#define REPORTY_ERROR   -1

#endif
