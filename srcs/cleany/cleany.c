/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleany.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 20:11:57 by leon              #+#    #+#             */
/*   Updated: 2022/08/18 19:52:44 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleany.h"

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
		close(((t_nmap_scan*)conf_exec)->socket);
	}
	return (r);
}

