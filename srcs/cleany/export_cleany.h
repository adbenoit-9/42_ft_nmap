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
//int 				clean_net(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec);
//int 				clean_net(uint8_t *buf, T_CLIENT_ST *conf_st, T_CLIENT_ND *conf_nd, T_CLIENT_RD *conf_exec);
int 				clean_net(T_CLIENT_ROOT *root, T_CLIENT_ST *link, T_CLIENT_ND *app);

#define SELECT_HOOK_CLEANY(hook) do { \
		hook = 0; \
} while (0)


#endif
