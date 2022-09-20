/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysy_icmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:02:39 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/20 19:33:38 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analysy.h"

uint8_t  analyse_tcpscan_icmp_ipv4(struct icmphdr *icmp)
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

uint8_t  analyse_tcpscan_icmp_ipv6(struct icmp6_hdr *icmp)
{
    uint8_t result = 0;
    
    if (icmp->icmp6_type == ICMP6_DST_UNREACH &&
            (icmp->icmp6_code == ICMP6_DST_UNREACH_ADDR ||
            icmp->icmp6_code == ICMP6_DST_UNREACH_NOPORT)) {
        result = PORT_S_FILTERED;
    }
    else {
        result = PORT_S_UNFILTERED;
    }
    return (result);
}


uint8_t  analyse_udpscan_icmp_ipv4(struct icmphdr *icmp)
{
    uint8_t result = 0;
    
    if (icmp->type == 1 &&
            (icmp->code == ICMP_HOST_UNREACH ||
                icmp->code == ICMP_PROT_UNREACH ||
                icmp->code == ICMP_NET_ANO ||
                icmp->code == ICMP_HOST_ANO ||
                icmp->code == ICMP_PKT_FILTERED)) {
        result = PORT_S_FILTERED;
    }
    else if (icmp->type == ICMP_DEST_UNREACH &&
            icmp->code == ICMP_PORT_UNREACH) {
        result = PORT_S_CLOSED;           
    }
    return (result);
}

uint8_t  analyse_udpscan_icmp_ipv6(struct icmp6_hdr *icmp)
{
    uint8_t result = 0;
    
    if (icmp->icmp6_type == ICMP6_DST_UNREACH &&
            icmp->icmp6_code == ICMP6_DST_UNREACH_ADDR) {
        result = PORT_S_FILTERED;
    }
    if (icmp->icmp6_type == ICMP6_DST_UNREACH &&
            icmp->icmp6_code == ICMP6_DST_UNREACH_NOPORT) {
        result = PORT_S_CLOSED;
    }
    return (result);
}
