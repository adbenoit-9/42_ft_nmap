/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 13:33:37 by leon              #+#    #+#             */
/*   Updated: 2022/08/20 13:41:59 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TEST_STRUCTS_H
# define TEST_STRUCTS_H

#include <sys/types.h>
#include <sys/socket.h>

#define PORT_LIMIT			1024
#define SCAN_LIMIT			6
#define IP_LIMIT			16

typedef struct		s_nmap_setting {
	uint16_t							ports[PORT_LIMIT]; // Great nd config
	uint8_t								scans[SCAN_LIMIT]; // rd config
	int8_t								speedup;
	char								ipfile; // from a mmap
	char								*ips[IP_LIMIT];

}					t_nmap_setting;


typedef struct		s_nmap_link {
	struct sockaddr_storage				sock;
}					t_nmap_link;

typedef struct		s_nmap_app {
	uint16_t							port;
	int									sock;
}					t_nmap_app;

typedef struct		s_nmap_scan {
	int									packet_length;
	uint8_t								tcpflag;
	int									result;
}					t_nmap_scan;


#endif
