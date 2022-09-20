/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysy_ackscan.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:54:37 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/20 19:35:28 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analysy.h"

static uint8_t  analyse_ackscan_tcp(struct tcphdr *tcp)
{
    uint8_t result = 0;
    
    if (tcp->th_flags & TH_RST)
        result = PORT_S_UNFILTERED;
    return (result);
}

int analyse_ackscan_ipv4(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec)
{
    int ret = ANALYSY_OK;
    struct iphdr *ip = (struct iphdr *)(&buf[sizeof(t_nmap_blkhdr)]);

    ((t_nmap_blkhdr *)buf)->result = 0;
	if (!buf || !conf_st || !conf_nd || !conf_exec) {
        ret = ANALYSY_ERROR;
    }
    else if (ip->protocol == 0) {
        ((t_nmap_blkhdr *)buf)->result = PORT_S_FILTERED;
    }
    else if (ip->protocol == IPPROTO_TCP) {
        ((t_nmap_blkhdr *)buf)->result = analyse_ackscan_tcp(
            (struct tcphdr *)(&buf[sizeof(t_nmap_blkhdr) + sizeof(struct iphdr)]));
    }
    else if (ip->protocol == IPPROTO_ICMP) {
        ((t_nmap_blkhdr *)buf)->result = analyse_tcpscan_icmp_ipv4(
            (struct icmphdr *)(&buf[sizeof(t_nmap_blkhdr) + sizeof(struct iphdr)]));
    }
    return (ret);
}

int analyse_ackscan_ipv6(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec)
{
    int ret             = ANALYSY_OK;
    struct ip6_hdr *ip  = (struct ip6_hdr *)(&buf[sizeof(t_nmap_blkhdr)]);

    ((t_nmap_blkhdr *)buf)->result = 0;
	if (!buf || !conf_st || !conf_nd || !conf_exec) {
        ret = ANALYSY_ERROR;
    }
    else if (ip->ip6_nxt == 0) {
        ((t_nmap_blkhdr *)buf)->result = PORT_S_FILTERED;
    }
    else if (ip->ip6_nxt == IPPROTO_TCP) {
        ((t_nmap_blkhdr *)buf)->result = analyse_ackscan_tcp(
            (struct tcphdr *)(&buf[sizeof(t_nmap_blkhdr) + sizeof(struct ip6_hdr)]));
    }
    else if (ip->ip6_nxt == IPPROTO_ICMPV6) {
        ((t_nmap_blkhdr *)buf)->result = analyse_tcpscan_icmp_ipv6(
            (struct icmp6_hdr *)(&buf[sizeof(t_nmap_blkhdr) + sizeof(struct ip6_hdr)]));
    }
    return (ret);
}
