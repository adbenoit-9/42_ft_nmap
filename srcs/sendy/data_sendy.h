/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sendy.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:02:05 by leon              #+#    #+#             */
/*   Updated: 2022/08/21 16:08:27 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_SENDY_H
#define DATA_SENDY_H

#include "export_sendy.h"

#ifdef MAP_CMD_INDEX
# define SENDY_CMD_INDEX MAP_CMD_INDEX
#endif

t_func_mapy _sendy_exec[EXEC_MAX_HOOK] = {
		send_ipv4_tcp,
		NULL,
		NULL,
		NULL,
		NULL,
};

#endif
