/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exey_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:25:33 by leon              #+#    #+#             */
/*   Updated: 2022/08/21 18:57:20 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapy.h"

#define EXEY_DEBUG
#define EXEY_OK 0

#ifdef EXEY_DEBUG
#include <stdio.h>
#endif

static const uint8_t default_execution_list[] = {0x00, 0x01, 0x02};

//int					nmap_update_exey(T_CLIENT_ROOT *root, t_exe *exe , t_blk *blk)
//
//
int					nmap_init_exey(T_CLIENT_ROOT *root, t_exe *exe , t_blk *blk)
{
	uint32_t		i;

	(void)root;
	(void)blk;
	i = 0;
	while (i < sizeof(default_execution_list))
	{
		exe->tasks[i] = default_execution_list[i] | EXEC_TODO_MSK;
		exe->hook[i] = 0x00;
#ifdef EXEY_DEBUG
		fprintf(stderr, "%s:%d exe->tasks[%d] = %08x hook=%08x\n", __func__, __LINE__, i, exe->tasks[i], exe->hook[i]);
#endif
		i++;
	}
	return (EXEY_OK);
}

//	 = SELECT_HOOK_BUILDY(root.stexe->hook[i++])
