/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleany.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 20:11:57 by leon              #+#    #+#             */
/*   Updated: 2022/08/25 18:52:55 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleany.h"

int 				clean_net(uint8_t *map, void *root, void *link, void *app)
{
	int			r		= CLEANY_OK;

	(void)map;
	if (!root || !link || !app)
	{
		r = CLEANY_ERROR;
	}
	else
	{
#ifdef DEBUG
		fprintf(stderr, "%s:%d\n", __func__, __LINE__);
#endif /* DEBUG */
		/* Close a socket */
//		close(((t_nmap_link*)link)->socket);
	}
	return (r);
}

