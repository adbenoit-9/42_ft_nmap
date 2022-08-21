/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nmap_parsing.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:25:07 by adbenoit          #+#    #+#             */
/*   Updated: 2022/08/17 23:19:18 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NMAP_PARSING_H
# define FT_NMAP_PARSING_H

# include <stdint.h>
# include <stdbool.h>
# include <stdio.h>
# include <errno.h>
# include <netdb.h>
# include <arpa/inet.h>
# include "../libft/inc/libft.h"

# define NFLAG 6
# define PORTS_SCAN_LIMIT 1024
# define PORT_MAX 65536

# define NONE		0
# define S_SYN		0b10000000
# define S_NULL		0b01000000
# define S_ACK		0b00100000
# define S_FIN		0b00010000
# define S_XMAS		0b00001000
# define S_UDP		0b00000100

# define S_ANYTCP	0b11111000

/*
** In order to speedup we could allocate an array of [MAX_IP][MAX_PORT][MAX_PACKET_SIZE + A struct header with
**																			port, lock and result variable]
** If we have
** #define MAX_IP						128
** #define MAX_PRIVATE_HDR_IP			64
** #define MAX_PORT						1024
** #define MAX_PRIVATE_HDR_PORT			64
** #define MAX_PACKET_SIZE				64
** #define MAX_PRIVATE_HDR_PACKET_SIZE	64
** We have : (MAX_IP * MAX_PRIVATE_HDR_IP) * (MAX_PORT + MAX_PRIVATE_HDR_PORT) * (MAX_PACKET_SIZE + MAX_PRIVATE_PACKET_HDR_SIZE)
** bufSize = 33554432 bytes
** If we do this we could choose to allocate it dynamically or stack it at compile time
** If more IP than MAX_IP juste allocate dynamically ** Or add buffers in struct t_port so it'll be contigus memory and optimized in size if we declare this as an array
**
** If we want to multi-thread the scans inside a port scan we should add :
** #define MAX_SCAN_TYPE				64
** #define MAX_PRIVATE_HDR_SCAN_TYPE	64

** And it become :
** (MAX_IP * MAX_PRIVATE_HDR_IP) * (MAX_PORT + MAX_PRIVATE_HDR_PORT) * (MAX_SCAN_TYPE + MAX_PRIVATE_HDR_SCAN_TYPE) (MAX_PACKET_SIZE + MAX_PRIVATE_PACKET_HDR_SIZE)
** But to get REALLY fast we should multithread PRIVATE_HDR too :/
** So we could do without header in memory but with config in linked list with index on buffer aaaand that should work
** well.
** #define SCAN_TYPEINDEX_SYN	0
** #define SCAN_TYPEINDEX_NULL	0
** #define SCAN_TYPEINDEX_ACK	0
** #define SCAN_TYPEINDEX_FIN	0
** #define SCAN_TYPEINDEX_XMAS	0
** #define SCAN_TYPEINDEX_UDP	0
** All packet shall be written in a :
** int 				io_scans(uint8_t *buf, t_ip *ip, t_port *port, uint8_t scan_type)
** following by a func array call for each scans
** with the proto :
** int 				proto_scan(uint8_t *buf, t_ip *ip, t_port *port)
** or even
** int 				proto_scan(uint8_t *buf, void *conf_osi_ll, void *conf_osi_hl)
** with conf_osi cast to specific piece of osi (ip, tcp or eth, bt, etc)
** Its ok as long as buffer size not overload MAX_PACKET_SIZE
** config is passed through ptr in send.c so we could handle other config struct than t_ip and t_port
** Also, all config in list is read-only
** No config osi_ll or osi_hl must be read in send.c as it just dispatch the thread. It need to read the index
** of the differents struct though.
** For that i could just leave the uint32_t index at the start of struct
** So if i do index_ll = ((uint32_t*)osi_ll)[0] * MAX_OSI_LL; i'll access the index
**
** With that, it should work well.
*/
#define MAX_LL							128
#define MAX_HL							1024
#define MAX_PACKET_SIZE					64
#define MAX_SCAN_TYPE					6

typedef struct		s_opt
{
	uint16_t	ports[PORTS_SCAN_LIMIT];
	uint8_t		scans;
	int8_t		speedup;
	t_list		*ip_lst;
}               	t_opt;

t_opt	parser(int ac, char **av);
void    set_ip_from_file(t_opt *opt, char *file);
void    set_ip_from_arg(t_opt *opt, char *ip);
void    set_ports(t_opt *opt, char *value);
void    set_scan(t_opt *opt, char *value);
void    set_speedup(t_opt *opt, char *value);
bool	ft_isnumber(char *str);
int32_t	copy_new_range(uint16_t *dest, int32_t i, uint16_t begin, uint16_t end);

void    fatal_error(int16_t error, char *arg, t_opt *opt);

#endif
