/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nmap_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 19:39:38 by leon              #+#    #+#             */
/*   Updated: 2022/08/12 20:20:08 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NMAP_UTILS
# define FT_NMAP_UTILS

#include <stdint.h>

int					get_urandom(uint8_t *buf, int length);
uint16_t			ipv4_checksum(uint16_t *addr, int len);

#endif
