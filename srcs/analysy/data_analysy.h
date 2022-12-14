/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_analysy.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:34:55 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/14 19:08:03 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_ANALYSY_H
# define DATA_ANALYSY_H

# include "export_analysy.h"

#ifdef MAP_CMD_INDEX
# define REPORTY_CMD_INDEX MAP_CMD_INDEX
#endif

t_func_mapy _analysy_exec[EXEC_MAX_HOOK] = {
	analyse_synscan_ipv4,
	analyse_synscan_ipv6,
	analyse_ackscan_ipv4,
	analyse_ackscan_ipv6,
	analyse_fnxscan_ipv4,
	analyse_fnxscan_ipv6,
	analyse_udpscan_ipv4,
	analyse_udpscan_ipv6
};

#endif
