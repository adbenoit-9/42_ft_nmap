/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysy_ipv4_tcp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:54:37 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/14 16:50:08 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analysy.h"

int analyse_ipv4_tcp(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec)
{
    int ret = ANALYSY_OK;

	if (!buf || !conf_st || !conf_nd || !conf_exec) {
        ret = ANALYSY_ERROR;
    }
    else {
        
    }
    return (ret);
}
