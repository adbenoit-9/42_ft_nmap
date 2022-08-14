/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nmap_sendy.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:52:55 by leon              #+#    #+#             */
/*   Updated: 2022/08/14 15:04:47 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_NMAP_SENDY_H
# define FT_NMAP_SENDY_H

#include "ft_nmap.h"
#include <stdint.h>

# define MAX_LL							128
# define MAX_HL							1024
# define MAX_SCAN_TYPE					6
# define MAX_PACKET_SIZE					64
# define NMAP_BUFFER_SIZE				(MAX_LL * MAX_HL * MAX_SCAN_TYPE * MAX_PACKET_SIZE)
# define NMAP_LL_SIZE					(MAX_HL * MAX_SCAN_TYPE * MAX_PACKET_SIZE)
# define NMAP_HL_SIZE					(MAX_SCAN_TYPE * MAX_PACKET_SIZE)
# define NMAP_SCAN_NB					6 // can we have this with sizeof ?

typedef struct		s_nmap_proto {
	uint32_t 					index;
	t_list						*hl;
	t_list						*scans;
}					t_nmap_proto;

typedef struct		s_ft_scan {
 uint32_t						scan_id;
 uint32_t						lock;
}					t_ft_scan;

typedef struct		s_ip {
	t_nmap_proto				cross;
	struct sockaddr_storage		sock;
}					t_ip;
typedef struct			s_port {
	t_nmap_proto				cross;
	uint16_t 					port;
}						t_port;

typedef struct		s_scan {
	t_ft_scan					cross;
	uint32_t					result;
}					t_scan;

/* Exported functions */
int32_t					sendy(uint8_t *buf, t_list *lst_ll);

#endif
