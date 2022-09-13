/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_cleany.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 01:52:24 by leon              #+#    #+#             */
/*   Updated: 2022/08/21 16:23:07 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_CLEANY_H
# define EXPORT_CLEANY_H

#include <stdint.h>
#include "mapy.h"

/* Exported function */
int 				clean_net(uint8_t *map, T_CLIENT_ST *link, T_CLIENT_ND *app, T_CLIENT_RD *scan);


#endif
