/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sety_hooks.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:58:35 by leon              #+#    #+#             */
/*   Updated: 2022/08/23 17:04:03 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETY_HOOKS_H
# define SETY_HOOKS_H

/* For using sety_f */

#include "mapy.h"
#include "export_cleany.h"
// #include "export_setupy.h"

/* ST : t_func_sety_st */
int					set_sockaddr(t_nmap_setting *root, t_nmap_link *link, uint32_t index);
int					set_socket(t_nmap_setting *root, t_nmap_link *link, t_nmap_app *app,
				t_nmap_scan *scan);
int					set_pcap_init(t_nmap_setting *root, t_nmap_link *link, t_nmap_app *app,
			t_nmap_scan *scan);
int					set_pcap_close(t_nmap_setting *root, t_nmap_link *link, t_nmap_app *app,
			t_nmap_scan *scan);
/* ND : t_func_sety_nd */
int					set_port(t_nmap_setting *root, t_nmap_link *link, t_nmap_app *app,
				t_nmap_scan *scan);
/* RD : t_func_sety_rd */
int					set_tcpflag(t_nmap_setting *root, t_nmap_link *link, t_nmap_app *app,
				t_nmap_scan *scan);

#endif
