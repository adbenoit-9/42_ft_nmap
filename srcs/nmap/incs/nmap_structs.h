/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmap_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 23:43:19 by leon              #+#    #+#             */
/*   Updated: 2022/09/16 15:31:20 by adbenoit         ###   ########.fr       */
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
	pthread_mutex_t				mutex;
	pthread_mutex_t				time_mutex;
	struct timeval				pcap_time;
	int							socket;
	pcap_t						*pcap_handler;
	socklen_t					socklen;
	uint8_t						result;
}			t_nmap_blkhdr;

typedef struct		s_nmap_setting {
	uint16_t					ports[PORT_LIMIT];
	uint8_t						scans[SCAN_LIMIT];
	uint8_t						speedup;
	char						*ips[IP_LIMIT];
	int							ip_nb;
	int							port_nb;
	int							scan_nb;
	pthread_t					thread;
}					t_nmap_setting;

typedef struct		s_nmap_link {
	struct sockaddr_storage		sock;
	int							socket;
	socklen_t					socklen;
	char						dev_name[32];
	struct sockaddr_storage		src_sock;
}					t_nmap_link;

typedef struct		s_nmap_app {
	uint16_t					port;
}					t_nmap_app;

typedef struct		s_nmap_scan {
	int							packet_length;
	uint8_t						packet_flag;
	int							result;
}					t_nmap_scan;

#endif
