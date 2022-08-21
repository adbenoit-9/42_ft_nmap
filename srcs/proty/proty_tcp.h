/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proty_tcp.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 20:11:38 by leon              #+#    #+#             */
/*   Updated: 2022/08/20 15:50:44 by leon             ###   ########.fr       */
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

#define GET_TCP_SEQ(tcp, value) do {value = ((struct tcphdr*)tcp)->th_seq;} while (0)

#define SET_TCP_ACK(tcp, value) do {((struct tcphdr*)tcp)->th_ack =\
       					(uint32_t)value;} while (0)
#define GET_TCP_ACK(tcp, value) do {value = ((struct tcphdr*)tcp)->th_ack;} while (0)
#define SET_TCP_OFF(tcp, value) do {((struct tcphdr*)tcp)->th_off =\
       					(uint8_t)value & (uint8_t)0x0F;} while (0)
#define SET_TCP_FLAGS(tcp, value) do {((struct tcphdr*)tcp)->th_flags =\
       					(uint8_t)value;} while (0)

#define GET_TCP_FLAGS(tcp, value) do {value = ((struct tcphdr*)tcp)->th_flags;} while (0)

#define SET_TCP_WIN(tcp, value) do {((struct tcphdr*)tcp)->th_win =\
       					(uint16_t)value;} while (0)
#define SET_TCP_SUM(tcp, value) do {((struct tcphdr*)tcp)->th_sum =\
       					(uint16_t)value;} while (0)
#define SET_TCP_URP(tcp, value) do {((struct tcphdr*)tcp)->th_urp =\
       					(uint16_t)value;} while (0)
#define SET_TCP_DATA(tcp, value, length) do {if (value != 0)\
						{memcpy(&((uint8_t*)tcp)[sizeof(struct tcphdr)],\
						value, length);}} while (0)

static const uint8_t syn_mss[4] = {0x02, 0x04, 0x05, 0xb4};

#define FLAG_S_NULL				0x00
#define FLAG_S_SYN				TH_SYN
#define FLAG_S_ACK				TH_ACK
#define FLAG_S_FIN				TH_RST | TH_ACK
#define FLAG_S_XMAS				TH_FIN | TH_SYN | TH_RST | TH_ACK

#endif /* FT_NMAP_TCP */
