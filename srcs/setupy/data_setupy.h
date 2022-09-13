/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_setupy.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:04:19 by leon              #+#    #+#             */
/*   Updated: 2022/08/21 18:00:22 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_SETUPY_H
# define DATA_SETUPY_H

#include "export_setupy.h"

t_func_mapy _setupy_exec[EXEC_MAX_HOOK] = {
		setup_ipv4_tcp,
		setup_ipv4_udp,
		setup_ipv6_tcp,
		setup_ipv6_udp,
};



#endif
