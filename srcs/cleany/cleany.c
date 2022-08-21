/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleany.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 20:11:57 by leon              #+#    #+#             */
/*   Updated: 2022/08/21 16:32:07 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleany.h"

#define CLEANY_DEBUG

// t_sety_nd 
int 				clean_net(void *root, void *link, void *app)
{
	int			r		= CLEANY_OK;

	if (!root || !link || !app)
	{
		r = CLEANY_ERROR;
	}
	else
	{
#ifdef CLEANY_DEBUG
		fprintf(stderr, "%s:%d\n", __func__, __LINE__);
#endif /* CLEANY_DEBUG */
		/* Close a socket */
		close(((t_nmap_app*)app)->socket);
	}
	return (r);
}

