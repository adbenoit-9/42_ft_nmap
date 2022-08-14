/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nmap_scany.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:52:55 by leon              #+#    #+#             */
/*   Updated: 2022/08/14 15:09:28 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_NMAP_SCANY_H
# define FT_NMAP_SCANY_H

int 				scan_tcp_syn(uint8_t *buf, void *conf_ll, void *conf_hl, void *conf_scan);
int 				scan_tcp_null(uint8_t *buf, void *conf_ll, void *conf_hl, void *conf_scan);
int 				scan_tcp_fin(uint8_t *buf, void *conf_ll, void *conf_hl, void *conf_scan);
int 				scan_tcp_ack(uint8_t *buf, void *conf_ll, void *conf_hl, void *conf_scan);
int 				scan_tcp_xmas(uint8_t *buf, void *conf_ll, void *conf_hl, void *conf_scan);
int 				scan_udp(uint8_t *buf, void *conf_ll, void *conf_hl, void *conf_scan);

#endif
