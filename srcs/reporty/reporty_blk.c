/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reporty_blk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:21:56 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/19 17:06:36 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reporty.h"
#include "parsy_export.h"
#include <pthread.h>

int report_blk(t_blk *blk)
{
    int             r = REPORTY_OK;

#ifdef DEBUG
	fprintf(stderr, "%s:%d\n", __func__, __LINE__);
#endif
    if (!blk) {
        r = REPORTY_ERROR;
    }
    else {
        if (blk->root->options & OPT_VERBOSE) {
            pthread_mutex_lock(&blk->root->display_mutex);
            printf(BLK_HDR_FORMAT, "ip",
            HDR_PRECISION(2, IP_ZONE_SIZE, 4),
            "port",
            HDR_PRECISION(4, PORT_ZONE_SIZE, 4),
            "scan");
            pthread_mutex_unlock(&blk->root->display_mutex);
        }
    }
    return(r);
}
