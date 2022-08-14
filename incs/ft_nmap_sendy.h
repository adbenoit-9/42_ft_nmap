/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nmap_sendy.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:52:55 by leon              #+#    #+#             */
/*   Updated: 2022/08/14 17:07:33 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_NMAP_SENDY_H
# define FT_NMAP_SENDY_H

#include "ft_nmap.h" // TODO select header

#include <stdint.h>

/*
** Sendy
** Multi-threaded io manager.
** Take a work buffer in param with this value at compile time :
*/

# define MAX_LL							128
# define MAX_HL							1024
# define MAX_SCAN_TYPE					6
# define MAX_PACKET_SIZE				64
# define NMAP_BUFFER_SIZE				(MAX_LL * MAX_HL * MAX_SCAN_TYPE * MAX_PACKET_SIZE)
# define NMAP_LL_SIZE					(MAX_HL * MAX_SCAN_TYPE * MAX_PACKET_SIZE)
# define NMAP_HL_SIZE					(MAX_SCAN_TYPE * MAX_PACKET_SIZE)
# define NMAP_SCAN_NB					6 // can we have this with sizeof ?

/*
** Use t_list for config structure.
** New config structure can be added (for other layer support : bt, eth, ...), user just need
** to leave s_nmap_proto at the beginning of proto structure
** There is only 2 layer support : ll and hl. Where hl is a t_list in ll list.
**
** t_scan is the scan structure specific to scan type
** One can add new scan structure, but need to add t_ft_scan at its beginning
** t_scan can be used for specific scan parameters and for result report
**
** new scan must be set in the array of function nmap_scans in sendy.c
** User must update NMAP_SCAN_NB accordingly TODO
**
*/

/*
** Cross layer structures
*/
typedef struct		s_nmap_proto {
	uint32_t 					index;
	t_list						*hl;
	t_list						*scans;
}					t_nmap_proto;

typedef struct		s_ft_scan {
 uint32_t						scan_id;
 uint32_t						lock;
}					t_ft_scan;

/*
** Nmap structure for tcp and udp scan
** TODO rename t_ip with t_any
** TODO rename t_port ?
** TODO result size ?
*/

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
