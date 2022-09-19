/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_reporty.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 01:52:24 by leon              #+#    #+#             */
/*   Updated: 2022/09/19 17:08:55 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_REPORTY_H
# define EXPORT_REPORTY_H

# include <stdint.h>
# include "mapy.h"

/* Exported function */
void	report_config(t_nmap_setting *settings);
void    report_final(t_root *root, double scan_time);
int     report_blk(t_blk *);

# define SELECT_HOOK_REPORTY(sockaddr, nd, hook) do { \
	hook = 0; \
} while (0)

#endif
