/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysy_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:02:39 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/15 15:32:54 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analysy.h"

uint8_t  analyse_scan_icmp(struct icmphdr *icmp)
{
    uint8_t result = 0;
    
    if (icmp->type == ICMP_DEST_UNREACH &&
            (icmp->code == ICMP_HOST_UNREACH ||
                icmp->code == ICMP_PROT_UNREACH ||
                icmp->code == ICMP_PORT_UNREACH ||
                icmp->code == ICMP_NET_ANO ||
                icmp->code == ICMP_HOST_ANO ||
                icmp->code == ICMP_PKT_FILTERED)) {
        result = PORT_S_FILTERED;
    }
    else {
        result = PORT_S_UNFILTERED;
    }
    return (result);
}

