/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_cleany.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 01:52:24 by leon              #+#    #+#             */
/*   Updated: 2022/08/18 19:56:21 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEANY_EXPORT
# define CLEANY_EXPORT

#include "mappy.h"

#ifdef MAP_CMD_INDEX
# define CLEANY_CMD_INDEX MAP_CMD_INDEX
#endif
/* Exported function */
int 				clean_net(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec);


t_func_mappy _cleany_exec[MAPPY_MAX_EXECUTION_HOOK] = {
		clean_net,
		NULL,
		NULL,
		NULL,
		NULL,
};

#define SELECT_HOOK_CLEANY(hook) do { \
		hook = 0; \
} while (0)



#endif
