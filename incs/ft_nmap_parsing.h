/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nmap_parsing.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:25:07 by adbenoit          #+#    #+#             */
/*   Updated: 2022/08/08 16:30:29 by adbenoit         ###   ########.fr       */
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
# include "../libft/inc/libft.h"

# define NFLAG 6
# define PORTS_SCAN_LIMIT 1024
# define PORT_MAX 65536

# define NONE 0
# define S_SYN 0b10000000
# define S_NULL 0b01000000
# define S_ACK 0b00100000
# define S_FIN 0b00010000
# define S_XMAS 0b00001000
# define S_UDP 0b00000100

typedef struct s_opt
{
	uint16_t	ports[PORTS_SCAN_LIMIT];
	uint8_t		scans;
	int8_t		speedup;
	t_list		*ip_lst;
}               t_opt;

t_opt	parser(int ac, char **av);
void    set_ip_from_file(t_opt *opt, char *file);
void    set_ip_from_arg(t_opt *opt, char *ip);
void    set_ports(t_opt *opt, char *value);
void    set_scan(t_opt *opt, char *value);
void    set_speedup(t_opt *opt, char *value);
bool	ft_isnumber(char *str);

#endif
