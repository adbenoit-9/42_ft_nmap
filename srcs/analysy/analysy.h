/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysy.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:27:55 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/14 18:12:44 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANALYSY_H
# define ANALYSY_H

# include <stdint.h>
# include <stdio.h>
# include <unistd.h>
# include <netinet/ip_icmp.h>
# include <netinet/tcp.h>
# include <netinet/ip.h>
# include <netinet/ip6.h>

/* Project Header */
# include "nmap_structs.h"

# define ANALYSY_OK      0
# define ANALYSY_ERROR   -1

/* RESULT TYPES */
# define OPEN 0x02
# define CLOSED 0x04
# define FILTERED 0x08
# define UNFILTERED 0x10

#endif
