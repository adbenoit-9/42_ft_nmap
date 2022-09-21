/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsy_addr_family.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:17:45 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/21 12:26:32 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsy.h"

int     set_af_inet(t_nmap_setting *settings, char *value)
{
    int ret = PARSY_OK;

    (void)value;
    if (settings->addr_family != AF_INET6) {
        settings->addr_family = AF_INET;
    }
    else {
        ret = print_error(E_BOTHAF, NULL);
    }
    return (ret);
}

int     set_af_inet6(t_nmap_setting *settings, char *value)
{
    int ret = PARSY_OK;

    (void)value;
    if (settings->addr_family != AF_INET) {
        settings->addr_family = AF_INET6;
    }
    else {
        ret = print_error(E_BOTHAF, NULL);
    }
    return (ret);
}
