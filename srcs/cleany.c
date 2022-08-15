/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleany.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 20:11:57 by leon              #+#    #+#             */
/*   Updated: 2022/08/16 01:07:31 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

#include "ft_nmap_structs.h"

#define CLEANY_OK	0
#define CLEANY_ERROR	-1

// #define CLEANY_DEBUG

int 				clean_net(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec)
{
	int			r		= CLEANY_OK;

	if (!buf || !conf_st || !conf_nd)
	{
		r = CLEANY_ERROR;
	}
	else
	{
#ifdef CLEANY_DEBUG
		fprintf(stderr, "%s:%d\n", __func__, __LINE__);
#endif /* CLEANY_DEBUG */
		/* Close a socket */
		close(((t_scan*)conf_exec)->socket);
	}
	return (r);
}

