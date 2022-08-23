/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmap_mapy_export.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:07:46 by leon              #+#    #+#             */
/*   Updated: 2022/08/23 23:52:13 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NMAP_MAPY_EXPORT_H
# define NMAP_MAPY_EXPORT_H

/* for using mapy_f */

#include "mapy.h"
#include "export_buildy.h"
#include "export_sendy.h"
#include "export_cleany.h"
#include "export_recy.h"

int					print_all(uint8_t *buf, t_nmap_link *link, t_nmap_app *app, t_nmap_scan *scan);
int					print_report(uint8_t *buf, t_nmap_link *link, t_nmap_app *app, t_nmap_scan *scan);

#endif


