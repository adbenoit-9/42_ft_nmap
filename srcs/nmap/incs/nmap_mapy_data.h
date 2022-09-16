/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmap_mapy_data.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:16:18 by leon              #+#    #+#             */
/*   Updated: 2022/09/16 17:10:08 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPY_DATA_H
# define MAPY_DATA_H

//#include "mapy.h"
#include "data_buildy.h"
#include "data_sendy.h"
#include "data_cleany.h"
#include "data_recy.h"
#include "data_setupy.h"
#include "data_analysy.h"

t_func_mapy *_exec[EXEC_MAX_CMD] = {
	_buildy_exec,
	_setupy_exec,
	_sendy_exec,
	_recy_exec,
	_cleany_exec,
	_analysy_exec
};


#endif
