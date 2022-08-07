/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nmap_send.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:34:31 by leon              #+#    #+#             */
/*   Updated: 2022/08/07 22:26:18 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NMAP_SEND_H
# define FT_NMAP_SEND_H

#include <netinet/in.h>

/*
 * t_list ips containing t_ip containing t_list ports containing t_port
 * all of this need to be alloced
 *
 * Sending things can be organized this ways :
 * First, foreach entry in a t_list containing t_ip
 * 	build_[ip|ip6]_tcp and if UDP on build_[ip||ip6]_udp
 * 	set_ips in ip header (v6 or v4)
 * 	send ping && recv ping
 * 	foreach ports (can have a array, or a t_list but it's overkill to have a t_list for this... !!can have an array of 65535 bits (8191 bytes) with 
 * 										the position of each bits to 1 is the port to be tested) : 
 * 		set_ports (in TCP and UDP if on)
 * 		foreach scan :
 * 			set_types
 * 			set_ids + set_ttl
 * 			set_checksum
 * 			send
 * 			recv
 *
*/
struct s_list;

typedef struct		s_list
{
	int					content_size;
	void				*content;
	struct s_list		*next;
}					t_list;

typedef struct		s_ip {
	struct sockaddr_storage		sock;
	t_list						*ports;
	uint8_t						done;
}					t_ip;

/* 6 scan a gérer : 
 * 	stock le résultat de chaque scan sur 5 bits
 * 	ca devrait le faire
 *  result = SYN | NULL | ACK | FIN | XMAS | UDP | 2b(unused)
*/

#define MASK_RESULT				(uint32_t)0x1F

#define SYN_SHIFT_RESULT		(uint32_t)0;
#define NULL_SHIFT_RESULT		(uint32_t)5;
#define ACK_SHIFT_RESULT		(uint32_t)10;
#define FIN_SHIFT_RESULT		(uint32_t)15;
#define XMAS_SHIFT_RESULT		(uint32_t)20;
#define UDP_SHIFT_RESULT		(uint32_t)25;

// Default to all scan : 0x3F

#define NMAP_SCANS_FLAG_SYN		0x01
#define NMAP_SCANS_FLAG_NULL	0x02
#define NMAP_SCANS_FLAG_ACK		0x04
#define NMAP_SCANS_FLAG_FIN		0x08
#define NMAP_SCANS_FLAG_XMAS	0x10
#define NMAP_SCANS_FLAG_UDP		0x20

#define NMAP_SCANS_FLAG_ANY_TCP		0x1F

typedef struct			s_port {
	uint16_t 	port;
	uint8_t		lock;
	uint32_t	result;
}						t_port;

typedef struct		s_opt {
	uint8_t				scans;
}					t_opt;

#endif /* FT_NMAP_SEND_H */
