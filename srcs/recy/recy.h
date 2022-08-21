/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recy.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 21:26:38 by leon              #+#    #+#             */
/*   Updated: 2022/08/21 16:17:44 by leon             ###   ########.fr       */
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

#endif
