/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reporty.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:54:37 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/14 14:22:51 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reporty.h"

int report(uint8_t *map, void *root, void *link, void *app)
{
    int ret = REPORTY_OK;

    if (!map || !root || !link || !app) {
        ret = REPORTY_ERROR;
    }
    // else if (((t_nmap_link*)link)->nb_scanned == {
        
    // }
    return (ret);
}
