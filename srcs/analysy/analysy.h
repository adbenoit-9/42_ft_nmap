/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysy.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:27:55 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/20 19:36:21 by adbenoit         ###   ########.fr       */
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
# include <netinet/icmp6.h>

/* Project Header */
# include "nmap_structs.h"

# define ANALYSY_OK      	0
# define ANALYSY_ERROR   	-1

/* RESULT TYPES */
# define PORT_S_OPEN		0x02
# define PORT_S_CLOSED		0x04
# define PORT_S_FILTERED	0x08
# define PORT_S_UNFILTERED	0x10

uint8_t  analyse_tcpscan_icmp_ipv4(struct icmphdr *icmp);
uint8_t  analyse_tcpscan_icmp_ipv6(struct icmp6_hdr *icmp);
uint8_t  analyse_udpscan_icmp_ipv4(struct icmphdr *icmp);
uint8_t  analyse_udpscan_icmp_ipv6(struct icmp6_hdr *icmp);

#endif
