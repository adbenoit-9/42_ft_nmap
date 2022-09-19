/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsy_verbose.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:54:34 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/19 14:00:22 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsy.h"

int    set_verbose(t_nmap_setting *settings, char *value)
{
    (void)value;
    settings->options |= OPT_VERBOSE;
    return (PARSY_OK);
}
