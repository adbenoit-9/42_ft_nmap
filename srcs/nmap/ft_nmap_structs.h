/* ************************************************************************** */
/*                                                                            */ /*                                                        :::      ::::::::   */
/*   ft_nmap_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 23:43:19 by leon              #+#    #+#             */
/*   Updated: 2022/08/18 20:53:00 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_NMAP_STRUCTS_H
# define FT_NMAP_STRUCTS_H

#include "mappy.h"

#include <sys/types.h>
#include <sys/socket.h>

#define PORTS_SCAN_LIMIT 1024

typedef struct				s_nmap_setting {
	t_proto_root							cross;
	uint32_t 									nmap_flag;
	uint16_t									ports[PORTS_SCAN_LIMIT]; // Great nd config
	uint8_t										scans[MAPPY_MAX_RD]; // rd config
	int8_t										speedup; // We open it in the nmap so meh
	char											ipfile; // from a mmap
	t_list										*ip_lst; // ?
	char										*ips[MAPPY_MAX_ST]; // only take char ** from gnl TODO
	struct sockaddr_storage		socks[MAPPY_MAX_ST];

}								t_nmap_setting;


typedef struct		s_nmap_link {
	t_proto_tree								cross;
	struct sockaddr_storage			sock; // remove ?
	uint8_t 					st_flag;
}									t_nmap_link;

typedef struct		s_nmap_app {
	t_proto_tree				cross;
	uint16_t					ports[PORTS_SCAN_LIMIT]; // Great nd config
	int								sock; // TODO remove
	uint8_t 					nd_flag;
	int								port;		// TODO remove ?
}									t_nmap_app;

typedef struct		s_nmap_scan {
	t_proto_elem			cross;
	uint8_t						exec_flag;
	uint8_t						scans; // rd config
	int								packet_length;
	int								socket; // TODO go to st layer
	uint8_t						tcpflag;
	int								scan_result;
}					t_nmap_scan;


#endif
