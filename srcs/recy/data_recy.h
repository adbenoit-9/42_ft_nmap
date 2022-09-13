/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_recy.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:58:41 by leon              #+#    #+#             */
/*   Updated: 2022/09/13 17:23:24 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_RECY_H
# define DATA_RECY_H

#include "export_recy.h"

#ifdef MAP_CMD_INDEX
# define RECY_CMD_INDEX MAP_CMD_INDEX
#endif

t_func_mapy _recy_exec[EXEC_MAX_CMD] = {
		recv_ipv4_tcp,
		recv_ipv4_tcp,
		recv_ipv4_tcp,
		recv_ipv4_tcp,
		NULL,
		NULL,
		NULL,
		NULL,
};


#endif
