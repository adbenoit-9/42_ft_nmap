/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proty_ip.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:34:27 by leon              #+#    #+#             */
/*   Updated: 2022/08/22 17:51:20 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NMAP_IP_H
# define FT_NMAP_IP_H

# include <netinet/ip.h>
# include <netinet/ip6.h>

#define SET_IP4_VERSION(ip, value) do {((struct iphdr*)ip)->version =\
					(uint8_t)value & (uint8_t)0x0F;} while (0)
#define SET_IP4_IHL(ip, value) do {((struct iphdr*)ip)->ihl =\
					(uint8_t)value & (uint8_t)0x0F;} while (0)
#define SET_IP4_TOS(ip, value) do {((struct iphdr*)ip)->tos =\
					(uint8_t)value;} while (0)
#define SET_IP4_TOT_LEN(ip, value) do {((struct iphdr*)ip)->tot_len =\
       				(uint16_t)value;} while (0)
#define SET_IP4_ID(ip, value) do {((struct iphdr*)ip)->id =\
					(uint16_t)value;} while (0)
#define SET_IP4_FRAG_OFF(ip, value) do {((struct iphdr*)ip)->frag_off =\
       				(uint16_t)value;} while (0)
#define SET_IP4_TTL(ip, value) do {((struct iphdr*)ip)->ttl =\
					(uint8_t)value;} while (0)
#define SET_IP4_PROTOCOL(ip, value) do {((struct iphdr*)ip)->protocol =\
       				(uint8_t)value;} while (0)
#define SET_IP4_CHECK(ip, value) do {((struct iphdr*)ip)->check =\
					(uint16_t)value;} while (0)
#define SET_IP4_SADDR(ip, value) do {((struct iphdr*)ip)->saddr =\
					(uint32_t)value;} while (0)
#define SET_IP4_DADDR(ip, value) do {((struct iphdr*)ip)->daddr =\
					(uint32_t)value;} while (0)

#define SET_IP6_VFC(ip, version, class) do {((struct ip6_hdr*)ip)->ip6_vfc =\
					((uint32_t)version & IPV6_VERSION_MASK) | ((uint32_t)class & ~IPV6_VERSION_MASK);} while (0)
#define SET_IP6_FLOW(ip, value) do {((struct ip6_hdr*)ip)->ip6_flow =\
					(uint32_t)value & IPV6_FLOWLABEL_MASK;} while (0)
#define SET_IP6_PLEN(ip, value) do {((struct ip6_hdr*)ip)->ip6_plen =\
						(uint16_t)value;} while (0)
#define SET_IP6_NXT(ip, value) do {((struct ip6_hdr*)ip)->ip6_nxt =\
       					(uint8_t)value;} while (0)
#define SET_IP6_HLIM(ip, value) do {((struct ip6_hdr*)ip)->ip6_hops =\
       					(uint8_t)value;} while (0)
#define SET_IP6_SRC(ip, value) do {((struct ip6_hdr*)ip)->ip6_src =\
						(struct in6_addr)value;} while (0)
#define SET_IP6_DST(ip, value) do {((struct ip6_hdr*)ip)->ip6_dst =\
       					(struct in6_addr)value;} while (0)

#endif /* FT_NMAP_IP */
