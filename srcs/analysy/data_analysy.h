/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_analysy.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:34:55 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/14 16:42:11 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_ANALYSY_H
# define DATA_ANALYSY_H

# include "export_analysy.h"

#ifdef MAP_CMD_INDEX
# define REPORTY_CMD_INDEX MAP_CMD_INDEX
#endif

t_func_mapy _reporty_exec[EXEC_MAX_HOOK] = {
	analyse_ipv4_tcp,
	NULL,
	NULL,
	NULL
};

#endif
