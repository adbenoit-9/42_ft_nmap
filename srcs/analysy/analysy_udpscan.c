/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysy_udpscan.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:54:37 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/20 19:35:04 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analysy.h"

int analyse_udpscan_ipv4(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec)
{
    int ret = ANALYSY_OK;
    struct iphdr *ip = (struct iphdr *)(&buf[sizeof(t_nmap_blkhdr)]);

    ((t_nmap_blkhdr *)buf)->result = 0;
	if (!buf || !conf_st || !conf_nd || !conf_exec) {
        ret = ANALYSY_ERROR;
    }
    else if (ip->protocol == 0) {
        ((t_nmap_blkhdr *)buf)->result = PORT_S_FILTERED | PORT_S_OPEN;
    }
    else if (ip->protocol == IPPROTO_UDP) {
        ((t_nmap_blkhdr *)buf)->result =  PORT_S_OPEN;
    }
    else if (ip->protocol == IPPROTO_ICMP) {
        ((t_nmap_blkhdr *)buf)->result = analyse_udpscan_icmp_ipv4(
            (struct icmphdr *)(&buf[sizeof(t_nmap_blkhdr) + sizeof(struct iphdr)]));
    }
    return (ret);
}

int analyse_udpscan_ipv6(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec)
{
    int ret = ANALYSY_OK;
    struct ip6_hdr *ip = (struct ip6_hdr *)(&buf[sizeof(t_nmap_blkhdr)]);

    ((t_nmap_blkhdr *)buf)->result = 0;
	if (!buf || !conf_st || !conf_nd || !conf_exec) {
        ret = ANALYSY_ERROR;
    }
    else if (ip->ip6_nxt == 0) {
        ((t_nmap_blkhdr *)buf)->result = PORT_S_FILTERED | PORT_S_OPEN;
    }
    else if (ip->ip6_nxt == IPPROTO_UDP) {
        ((t_nmap_blkhdr *)buf)->result = PORT_S_OPEN;
    }
    else if (ip->ip6_nxt == IPPROTO_ICMPV6) {
        ((t_nmap_blkhdr *)buf)->result = analyse_udpscan_icmp_ipv6(
            (struct icmp6_hdr *)(&buf[sizeof(t_nmap_blkhdr) + sizeof(struct ip6_hdr)]));
    }
    else {
	    fprintf(stderr, "%s:%d nxt=%d\n", __func__, __LINE__, ip->ip6_nxt);
    }
    return (ret);
}
