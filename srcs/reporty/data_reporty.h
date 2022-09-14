/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_reporty.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:34:55 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/14 13:42:40 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_REPORTY_H
# define DATA_REPORTY_H

# include "export_reporty.h"

#ifdef MAP_CMD_INDEX
# define REPORTY_CMD_INDEX MAP_CMD_INDEX
#endif

t_func_mapy _reporty_exec[EXEC_MAX_HOOK] = {
	report,
	NULL,
	NULL,
	NULL
};

#endif
