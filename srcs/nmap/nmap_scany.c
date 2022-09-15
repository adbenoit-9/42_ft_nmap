/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmap_scany.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:23:46 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/15 19:37:07 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmap.h"

void	*scany(void *root)
{
	int64_t		r = 0;
	
	blky_init(((t_root *)root)->map);
	r = mapy(root);
    return ((void *)r);
}
