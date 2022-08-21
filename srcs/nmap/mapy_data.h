/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapy_data.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:16:18 by leon              #+#    #+#             */
/*   Updated: 2022/08/21 15:12:39 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPY_DATA_H
# define MAPY_DATA_H

//#include "mapy.h"
#include "data_buildy.h"
// #include "export_sendy.h"
// #include "export_cleany.h"
// #include "export_recy.h"
// #include "export_setupy.h"

t_func_mapy *_exec[EXEC_MAX_CMD] = {
	_buildy_exec,
};

//	_sendy_exec,
//	_recy_exec,
//	_cleany_exec,
//	_setupy_exec,


#endif
