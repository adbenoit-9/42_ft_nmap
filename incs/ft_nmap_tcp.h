/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nmap_tcp.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 20:11:38 by leon              #+#    #+#             */
/*   Updated: 2022/08/08 20:11:41 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NMAP_TCP_H
# define FT_NMAP_TCP_H

# include <netinet/tcp.h>

#define SET_TCP_SPORT(tcp, value) do {((struct tcphdr*)tcp)->th_sport =\
					(uint16_t)value;} while (0)
#define SET_TCP_DPORT(tcp, value) do {((struct tcphdr*)tcp)->th_dport =\
					(uint16_t)value;} while (0)
#define SET_TCP_SEQ(tcp, value) do {((struct tcphdr*)tcp)->th_seq =\
       					(uint32_t)value;} while (0)
#define SET_TCP_ACK(tcp, value) do {((struct tcphdr*)tcp)->th_ack =\
       					(uint32_t)value;} while (0)
#define SET_TCP_OFF(tcp, value) do {((struct tcphdr*)tcp)->th_off =\
       					(uint8_t)value & (uint8_t)0x0F;} while (0)
#define SET_TCP_FLAGS(tcp, value) do {((struct tcphdr*)tcp)->th_flags =\
       					(uint8_t)value;} while (0)
#define SET_TCP_WIN(tcp, value) do {((struct tcphdr*)tcp)->th_win =\
       					(uint16_t)value;} while (0)
#define SET_TCP_SUM(tcp, value) do {((struct tcphdr*)tcp)->th_sum =\
       					(uint16_t)value;} while (0)
#define SET_TCP_URP(tcp, value) do {((struct tcphdr*)tcp)->th_urp =\
       					(uint16_t)value;} while (0)

#endif /* FT_NMAP_TCP */
