/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_hooks.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 23:05:17 by leon              #+#    #+#             */
/*   Updated: 2022/08/22 08:24:50 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmap_structs.h"

/* ND : t_func_iter_nd */
int					iter_set_port(t_nmap_setting *root, t_nmap_app *app, uint32_t index);
/* RD : t_func_iter_rd */
int					iter_set_tcpflag(t_nmap_setting *root, t_nmap_scan *scan, uint32_t index);
