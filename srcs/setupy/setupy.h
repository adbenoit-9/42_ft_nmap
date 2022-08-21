/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setupy.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 23:43:41 by leon              #+#    #+#             */
/*   Updated: 2022/08/21 17:42:08 by adbenoit         ###   ########.fr       */
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

#endif
