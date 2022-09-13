/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nmap_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 19:39:38 by leon              #+#    #+#             */
/*   Updated: 2022/08/14 16:40:52 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NMAP_UTILS
# define FT_NMAP_UTILS

#include <stdint.h>

int			    get_urandom(uint8_t *buf, int length);
uint16_t	    checksum(uint16_t *addr, int len);
uint16_t	    tcp_ipv4_checksum(uint8_t *ip, uint16_t tcplen);
uint16_t	    ipv6_checksum(uint8_t *ip, uint16_t tcplen, uint8_t nxt_hdr);
struct in6_addr	get_src_ipv6(struct in6_addr dest);
in_addr_t	    get_src_ipv4(in_addr_t dest);

#endif
