/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sety_hooks.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:58:35 by leon              #+#    #+#             */
/*   Updated: 2022/08/22 09:19:12 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETY_HOOKS_H
# define SETY_HOOKS_H

/* For using sety_f */

#include "mapy.h"
#include "export_cleany.h"
// #include "export_setupy.h"

/* ST : t_func_sety_st */
int					set_sockaddr(t_nmap_setting *root, t_nmap_link *link);
int					set_socket(t_nmap_setting *root, t_nmap_link *link);
/* ND : t_func_sety_nd */
int					set_port(t_nmap_setting *root, t_nmap_link *link, t_nmap_app *app);
/* RD : t_func_sety_rd */
int					set_tcpflag(t_nmap_setting *root, t_nmap_link *link, t_nmap_app *app, t_nmap_scan *scan);

#endif
