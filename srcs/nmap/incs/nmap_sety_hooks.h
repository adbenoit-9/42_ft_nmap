/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmap_sety_hooks.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:58:35 by leon              #+#    #+#             */
/*   Updated: 2022/09/21 17:33:05 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NMAP_SETY_HOOKS_H
# define NMAP_SETY_HOOKS_H

/* For using sety_f */

#include "mapy.h"
#include "export_cleany.h"

int					dump_config_nd(t_nmap_setting *root, t_nmap_link *link, t_nmap_app *app,
			t_nmap_scan *scan);
int					set_src_sockaddr(t_nmap_setting *root, t_nmap_link *link, uint32_t index);
#endif
