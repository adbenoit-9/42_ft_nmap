/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_cleany.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:55:59 by leon              #+#    #+#             */
/*   Updated: 2022/08/21 16:24:19 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_CLEANY_H
# define DATA_CLEANY_H

#include "export_cleany.h"

#ifdef MAP_CMD_INDEX
# define CLEANY_CMD_INDEX MAP_CMD_INDEX
#endif


t_func_mapy _cleany_exec[EXEC_MAX_CMD] = {
		clean_net,
		NULL,
		NULL,
		NULL,
		NULL,
};


#endif
