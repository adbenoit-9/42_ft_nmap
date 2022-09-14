/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nmap_parsing.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:25:07 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/14 10:37:52 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NMAP_PARSING_H
# define FT_NMAP_PARSING_H

# include <stdint.h>
# include <stdbool.h>
# include <stdio.h>
# include <errno.h>
# include <netdb.h>
# include <arpa/inet.h>
# include "libft.h"
# include "nmap_structs.h"
# include "ft_nmap_error.h"
# include "proty_tcp.h"
# include "proty_udp.h"

# define PARSY_OK   0
# define PARSY_KO   -1
# define PARSY_STOP	1

# define NFLAG      6
# define PORT_MAX   65536

# define NONE		0
# define S_SYN		0b10000000
# define S_NULL		0b01000000
# define S_ACK		0b00100000
# define S_FIN		0b00010000
# define S_XMAS		0b00001000
# define S_UDP		0b00000100

# define S_ANYTCP	0b11111000

#define MAX_LL              128
#define MAX_HL              1024
#define MAX_PACKET_SIZE     64

int		parser(int ac, char **av, t_nmap_setting *settings);
int		set_ip_from_file(t_nmap_setting *settings, char *file);
int		set_ip_from_arg(t_nmap_setting *settings, char *ip);
int		set_ports(t_nmap_setting *settings, char *value);
int		set_scan(t_nmap_setting *settings, char *value);
int		set_speedup(t_nmap_setting *settings, char *value);
bool	ft_isnumber(char *str);
int32_t	copy_new_range(uint16_t *dest, int32_t i, uint16_t begin, uint16_t end);

#endif
