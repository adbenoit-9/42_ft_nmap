/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_setupy.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:04:19 by leon              #+#    #+#             */
/*   Updated: 2022/08/21 16:05:12 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_SETUPY_H
# define DATA_SETUPY_H

#include "export_setupy.h"

t_func_mappy _setupy_exec[MAPPY_MAX_EXECUTION_HOOK] = {
		setup_ipv4_tcp,
		NULL,
		NULL,
		NULL,
		NULL,
};



#endif
