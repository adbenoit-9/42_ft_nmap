#ifndef FT_NMAP_SEND_H
# define FT_NMAP_SEND_H

#include <netinet/in.h>

/*
 * t_list ips containing t_ip containing t_list ports containing t_port
 * all of this need to be alloced
 *
 * Sending things can be organized this ways :
 * First, foreach entry in a t_list of sockaddr_storage obtained via parsing cmdline :
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

typedef struct		s_ip {
	struct sockaddr_storage sock;
	t_list			ports;
}			t_ip;

/* 6 scan a gérer : 
 * 	stock le résultat de chaque scan sur 6 bits
 * 	ca devrait le faire
*/

typedef struct			s_port {
	uint16_t 	port;
	uint8_t		lock;
	uint32_t	result;
}				t_port;

#endif /* FT_NMAP_SEND_H */
