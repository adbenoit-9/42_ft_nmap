/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nmap_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 23:43:19 by leon              #+#    #+#             */
/*   Updated: 2022/08/20 17:24:19 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_NMAP_STRUCTS_H
# define FT_NMAP_STRUCTS_H

#include <sys/types.h>
#include <sys/socket.h>

#define SCAN_LIMIT			6
#define PORT_LIMIT			1024
#define IP_LIMIT			16

typedef struct		s_nmap_setting {
	uint16_t							ports[PORT_LIMIT];
	uint8_t								scans[SCAN_LIMIT];
	int8_t								speedup;
	char								*ips[IP_LIMIT];
	int									ip_nb;
	int									port_nb;
	int									scan_nb;
}					t_nmap_setting;

typedef struct		s_nmap_link {
	struct sockaddr_storage				sock;
}					t_nmap_link;

typedef struct		s_nmap_app {
	int									socket;
}					t_nmap_app;

typedef struct		s_nmap_scan {
	uint16_t							port;
	int									packet_length;
	uint8_t								tcpflag;
	int									result;
}					t_nmap_scan;

#endif
