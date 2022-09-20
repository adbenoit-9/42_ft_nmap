/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:25:07 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/20 12:27:47 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSY_H
# define PARSY_H

# include <stdint.h>
# include <stdbool.h>
# include <stdio.h>
# include <errno.h>
# include <netdb.h>
# include <arpa/inet.h>
# include "libft.h"
# include "nmap_structs.h"
# include "parsy_error.h"
# include "proty_tcp.h"
# include "proty_udp.h"
# include "parsy_export.h"

# define PORT_MAX   65536
# define NB_OPT     8

int		set_ip_from_file(t_nmap_setting *settings, char *file);
int		set_ip_from_arg(t_nmap_setting *settings, char *ip);
int		set_ports(t_nmap_setting *settings, char *value);
int		set_scan(t_nmap_setting *settings, char *value);
int		set_speedup(t_nmap_setting *settings, char *value);
int     set_verbose(t_nmap_setting *settings, char *value);
int     set_filter(t_nmap_setting *settings, char *value);

bool	ft_isnumber(char *str);
int32_t	copy_new_range(uint16_t *dest, int32_t i, uint16_t begin, uint16_t end);

#endif

