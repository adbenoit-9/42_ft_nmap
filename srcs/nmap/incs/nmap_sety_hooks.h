/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sety_hooks.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:58:35 by leon              #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#ifndef NMAP_SETY_HOOKS_H
# define NMAP_SETY_HOOKS_H

/* For using sety_f */

#include "mapy.h"
#include "export_cleany.h"
// #include "export_setupy.h"

/* ST : t_func_sety_st */
//int					set_socket(t_nmap_setting *root, t_nmap_link *link, t_nmap_app *app, t_nmap_scan *scan);
/* RD : t_func_sety_rd */

int					dump_config_nd(t_nmap_setting *root, t_nmap_link *link, t_nmap_app *app,
			t_nmap_scan *scan);
#endif
