/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmap_exey_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:25:33 by leon              #+#    #+#             */
/*   Updated: 2022/08/25 16:20:21 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapy.h"
#include <pthread.h>

//#define EXEY_DEBUG

#define EXEY_OK 0
#define EXEY_ERR -1

#include <stdio.h>
#include <string.h>
#include <unistd.h>

static const uint8_t default_execution_list[] = {0x00, 0x01, 0x02};

int					nmap_init_exey(T_CLIENT_ROOT *root, t_exe *exe , t_blk *blk)
{
	uint32_t	i;
	int			ret;

	(void)root;
	i = 0;
	ret = EXEY_ERR;
	if ((ret = pthread_mutex_init(&exe->mutex, NULL)) != 0) {
		dprintf(STDERR_FILENO, "pthread_mutex_init (exe): %s\n", strerror(ret));
		ret = EXEY_ERR;
	}
	if (blk && (ret = pthread_mutex_init(&blk->mutex, NULL)) != 0) {
		dprintf(STDERR_FILENO, "pthread_mutex_init (blk): %s\n", strerror(ret));
		ret = EXEY_ERR;
	}
	while (ret == EXEY_OK && i < 2) //sizeof(default_execution_list))
	{
		exe->tasks[i] = default_execution_list[i] | EXEC_TODO_MSK;
		exe->hook[i] = 0x00;

#ifdef EXEY_DEBUG
		fprintf(stderr, "%s:%d exe->tasks[%d] = %08x hook=%08x\n", __func__, __LINE__, i, exe->tasks[i], exe->hook[i]);
#endif
		i++;
	}
	return (ret);
}

int					nmap_clean_exey(T_CLIENT_ROOT *root, t_exe *exe , t_blk *blk)
{
	(void)root;
	pthread_mutex_destroy(&exe->mutex);
	pthread_mutex_destroy(&blk->mutex);
	return (EXEY_OK);
}

//int					nmap_update_exey(T_CLIENT_ROOT *root, t_exe *exe , t_blk *blk)
//	 = SELECT_HOOK_BUILDY(root.stexe->hook[i++])
