/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_reporty.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 01:52:24 by leon              #+#    #+#             */
/*   Updated: 2022/09/19 14:30:20 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_REPORTY_H
# define EXPORT_REPORTY_H

# include <stdint.h>
# include "mapy.h"

/* Exported function */
void	report_config(t_nmap_setting *settings);
void    report_final(t_root *root, double scan_time);
int     report_blk(uint8_t *buf, T_CLIENT_ST *conf_st, T_CLIENT_ND *conf_nd, T_CLIENT_RD *conf_exec);

# define SELECT_HOOK_REPORTY(sockaddr, nd, hook) do { \
	hook = 0; \
} while (0)

#endif
