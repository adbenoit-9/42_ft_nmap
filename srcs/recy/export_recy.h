/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_recy.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 01:52:24 by leon              #+#    #+#             */
/*   Updated: 2022/08/24 07:38:13 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_RECY
# define EXPORT_RECY

#include "mapy.h"

/* Exported Functions */
int 				recv_ipv4_tcp(uint8_t *buf, T_CLIENT_ST *conf_st, T_CLIENT_ND *conf_nd, T_CLIENT_RD *conf_exec);
//int 				recv_ipv4_udp(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec);
//int 				recv_ipv6_tcp(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec);
//int 				recv_ipv6_udp(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec);

void				ft_pcap_handler(u_char *user, const struct pcap_pkthdr *h,
							const u_char *bytes);
void		*run_pcap(void *root);
int			set_pcap_init(t_nmap_setting *nmap);

#define SELECT_HOOK_RECY(sockaddr, nd, hook) do { \
if (((struct sockaddr_storage *)sockaddr).ss_family == AF_INET) { \
	if (nd == NMAP_UDP) { \
		hook = 1; \
}	else { \
		hook = 0; \
}else { \
	if { \
		hook = 4; \
}	else { \
		hook = 3; \
	} \
} \
} while (0)

#endif
