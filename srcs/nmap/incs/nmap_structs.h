/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmap_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 23:43:19 by leon              #+#    #+#             */
/*   Updated: 2022/08/24 09:40:32 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_NMAP_STRUCTS_H
# define FT_NMAP_STRUCTS_H

#include <stdint.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <pcap/pcap.h>

#define SCAN_LIMIT			6
#define PORT_LIMIT			1024
#define IP_LIMIT			32

typedef struct		s_nmap_blkhdr {
	int					socket;
	pcap_t					*pcap_handler;
	socklen_t				socklen;
}			t_nmap_blkhdr;

typedef struct		s_nmap_setting {
	uint16_t							ports[PORT_LIMIT];
	uint8_t								scans[SCAN_LIMIT];
	int8_t								speedup;
	char								*ips[IP_LIMIT];
	int								ip_nb;
	int								port_nb;
	int								scan_nb;
	pcap_t								*pcap_handler;
	pthread_t							thread;
	//struct sockaddr_storage				ip4_src;
	//struct sockaddr_storage				ip6_src;
}					t_nmap_setting;

typedef struct		s_nmap_link {
	struct sockaddr_storage							sock;
	int									socket;
	socklen_t								socklen;
	char									dev_name[32];
	struct sockaddr_storage							src_sock;
}					t_nmap_link;

typedef struct		s_nmap_app {
	//int									socket;
	uint16_t							port;
}					t_nmap_app;

typedef struct		s_nmap_scan {
	int									packet_length;
	uint8_t									packet_flag;
	int									result;
}					t_nmap_scan;

#endif
