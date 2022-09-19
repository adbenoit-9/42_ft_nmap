/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reporty_blk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:21:56 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/19 18:24:42 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reporty.h"
#include "parsy_export.h"
#include <pthread.h>

double	elapse_time(struct timeval *begin, struct timeval *end);

int num_len(int num)
{
    int len = 1;

    while (num > 10) {
        num /= 10;
        ++len;
    }
    return len;
}

int report_blk(t_blk *blk, char *ip)
{
    int             r = REPORTY_OK;
    int             port_len, time_len, scan_index;
    static char	*scan_str[] = {"NULL", "SYN", "ACK", "FIN", "XMAS", "UDP", NULL};
	static char	scan_value[] = {FLAG_S_NULL, FLAG_S_SYN, FLAG_S_ACK, FLAG_S_FIN,
				FLAG_S_XMAS, FLAG_S_UDP};
    struct timeval  tv;
    double          time_elapsed;

#ifdef DEBUG
	fprintf(stderr, "%s:%d\n", __func__, __LINE__);
#endif
    if (!blk) {
        r = REPORTY_ERROR;
    }
    else {
        if (blk->root->options & OPT_VERBOSE) {
            port_len = num_len(blk->nd->port);
            for (scan_index = 0; scan_index < 6; scan_index++) {
                if (blk->rd->packet_flag == scan_value[scan_index]) {
                    break ;
                }
            }
            gettimeofday(&tv, NULL);
            time_elapsed = elapse_time(&blk->root->time, &tv);
            time_len = num_len((int)time_elapsed);
            pthread_mutex_lock(&blk->root->display_mutex);
            printf(BLK_HDR_FORMAT,
                "TIME ELAPSED",
                HDR_PRECISION(12, TIME_ZONE_SIZE, 2),
                "IP",
                HDR_PRECISION(2, IP_ZONE_SIZE, 4),
                "PORT",
                HDR_PRECISION(4, PORT_ZONE_SIZE, 4),
                "SCAN");
            printf(BLK_REPORT_FORMAT,
                5,
                time_elapsed,
                PRECISION((time_len + 6), TIME_ZONE_SIZE, ip),
                ip,
                HDR_PRECISION(ft_strlen(ip), IP_ZONE_SIZE, port_len),
                blk->nd->port,
                PRECISION(port_len, PORT_ZONE_SIZE, scan_str[scan_index]),
                scan_str[scan_index]);
            pthread_mutex_unlock(&blk->root->display_mutex);
        }
    }
    return(r);
}
