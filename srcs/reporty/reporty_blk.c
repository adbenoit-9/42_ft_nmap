/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reporty_blk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:21:56 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/19 14:59:23 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reporty.h"

int report_blk(uint8_t *buf, T_CLIENT_ST *conf_st, T_CLIENT_ND *conf_nd, T_CLIENT_RD *conf_exec)
{
    int r = REPORTY_OK;

#ifdef DEBUG
	fprintf(stderr, "%s:%d\n", __func__, __LINE__);
#endif
    if (!buf || !conf_st || !conf_nd || !conf_exec) {
        r = REPORTY_ERROR;
    }
    return(r);
}
