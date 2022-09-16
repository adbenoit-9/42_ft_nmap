/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recy.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 21:26:38 by leon              #+#    #+#             */
/*   Updated: 2022/09/16 15:44:25 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECVY_H
# define RECVY_H

#include <stdint.h>
#include <netinet/ip.h>
#include <netinet/ip6.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <pthread.h>

#include "proty_tcp.h"
#include "nmap_structs.h"

#define RECY_OK 0
#define RECY_ERROR -1

void				nmap_pcap_handler(u_char *user, const struct pcap_pkthdr *h,
							const u_char *bytes);

#endif
