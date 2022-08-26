/* ************************************************************************** */
/*                                                                            */ /*                                                        :::      ::::::::   */
/*   export_buildy.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 01:52:24 by leon              #+#    #+#             */
/*   Updated: 2022/08/19 01:22:02 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILDY_EXPORT
# define BUILDY_EXPORT

#include "mapy.h"
#include "export_buildy.h"

#ifdef MAP_CMD_INDEX
# define BUILDY_CMD_INDEX MAP_CMD_INDEX
#endif

t_func_mapy _buildy_exec[EXEC_MAX_CMD] = {
		build_ipv4_tcp,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
};

#endif