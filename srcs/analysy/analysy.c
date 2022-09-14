/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:54:37 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/14 16:35:14 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analysy.h"

int analyse(uint8_t *map, void *root, void *link, void *app)
{
    int ret = ANALYSY_OK;

    if (!map || !root || !link || !app) {
        ret = ANALYSY_ERROR;
    }
    // else if (((t_nmap_link*)link)->nb_scanned == {
        
    // }
    return (ret);
}
