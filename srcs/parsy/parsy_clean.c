/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsy_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:20:09 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/22 10:40:02 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsy.h"

void    clean_settings(t_nmap_setting *settings)
{
    if (settings) {
        for (int i = 0; i < settings->ip_nb; i++) {
            free(settings->ips[i]);
        }
    }
}
