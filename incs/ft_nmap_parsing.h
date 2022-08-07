/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nmap_parsing.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:25:07 by adbenoit          #+#    #+#             */
/*   Updated: 2022/08/07 21:30:30 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NMAP_PARSING_H
# define FT_NMAP_PARSING_H

# include <stdint.h>
# include <stdbool.h>
# include <stdio.h>
# include <errno.h>

# define NFLAG 6

# define S_SYN 0b10000000
# define S_NULL 0b01000000
# define S_ACK 0b00100000
# define S_FIN 0b00010000
# define S_XMAS 0b00001000
# define S_UDP 0b00000100

typedef struct s_param
{
	int32_t	ports[2];
	uint8_t	scan;
	int8_t	speedup;
	uint8_t	**ip;
}               t_param;

t_param	parser(int ac, char **av);
void    set_ip_from_file(t_param *param, char *file);
void    set_ip_from_arg(t_param *param, char *ip);
void    set_ports(t_param *param, char *value);
void    set_scan(t_param *param, char *value);
void    set_speedup(t_param *param, char *value);

#endif
