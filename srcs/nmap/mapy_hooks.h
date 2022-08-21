/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapy_hooks.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:07:46 by leon              #+#    #+#             */
/*   Updated: 2022/08/21 15:32:28 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPY_HOOKS_H
# define MAPY_HOOKS_H

/* for using mapy_f */

#include "mapy.h"
#include "export_buildy.h"

int					print_all(uint8_t *buf, t_nmap_link *link, t_nmap_app *app, t_nmap_scan *scan);
// #include "export_sendy.h"
// #include "export_cleany.h"
// #include "export_recy.h"
// #include "export_setupy.h"

#endif


