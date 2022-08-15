/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nmap_build.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:34:21 by leon              #+#    #+#             */
/*   Updated: 2022/08/07 22:24:08 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NMAP_BUILD_H
# define FT_NMAP_BUILD_H

#include <stdint.h>

int32_t			build_tcp_ip_raw(uint8_t **buffer);
int32_t			build_udp_ip_raw(uint8_t **buffer);
int32_t			build_tcp_ip6_raw(uint8_t **buffer);
int32_t			build_udp_ip6_raw(uint8_t **buffer);

#endif
