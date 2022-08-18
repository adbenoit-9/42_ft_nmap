/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ports.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:53:39 by adbenoit          #+#    #+#             */
/*   Updated: 2022/08/17 23:24:15 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_nmap_parsing.h"
#include "ft_nmap_error.h"

static void	check_ports(char *value, int32_t begin, int32_t end,
bool isrange, t_opt *opt)
{
	uint64_t i = ft_strlen(value);

	if (ft_isnumber(value) == false || (isrange == true &&
			ft_isnumber(value + i) == false)) {
		if (isrange == true) {
			value[i] = '-';
		}
		fatal_error(E_BADPORT, value, opt);
	}
	else if (end - begin < 0 || end - begin > PORTS_SCAN_LIMIT) {
		fatal_error(E_LIMIT_EXCEED, NULL, opt);
	}
	else if (begin < 0 || begin > PORT_MAX) {
		fatal_error(E_BADPORT, value, opt);
	}
	else if (end < 0 || end > PORT_MAX) {
		fatal_error(E_BADPORT, value + i + 1, opt);
	}
}

static int32_t	copy_ports_inf(uint16_t *dest, uint16_t *src, uint16_t max)
{
	int32_t i;
	
	for (i = 0; src[i] < max && src[i] != 0 && i < PORTS_SCAN_LIMIT; i++) {
		dest[i] = src[i];
	}
	return (i);
}

static int32_t	copy_ports_sup(uint16_t *dest, uint16_t *src, uint16_t min, int32_t n)
{
	for (uint16_t i = 0; src[i] != 0; i++) {
		if (n >= PORTS_SCAN_LIMIT)
			return (-1);
		if (src[i] <= min) {
			continue ;
		}
		dest[n] = src[i];
		n++;
	}
	return (n);
}

int32_t	copy_new_range(uint16_t *dest, int32_t i, uint16_t begin, uint16_t end)
{
	for (; begin <= end; i++, begin++) {
		if (i >= PORTS_SCAN_LIMIT) {
			return (-1);
		}
		dest[i] = begin;
	}
	return (i);
}

static void	add_ports(t_opt *opt, int32_t begin, int32_t end)
{
	int32_t		i;
	uint16_t	new_ports[PORTS_SCAN_LIMIT];

	bzero(new_ports, PORTS_SCAN_LIMIT * sizeof(uint16_t));
	i = copy_ports_inf(new_ports, opt->ports, begin);
	i = copy_new_range(new_ports, i, begin, end);
	if (i == -1) {
		fatal_error(E_LIMIT_EXCEED, NULL, opt);
	}
	i = copy_ports_sup(new_ports, opt->ports, end, i);
	if (i == -1) {
		fatal_error(E_LIMIT_EXCEED, NULL, opt);
	}
	ft_memcpy(opt->ports, new_ports, PORTS_SCAN_LIMIT * sizeof(uint16_t));
}

void    set_ports(t_opt *opt, char *value)
{
	bool		isrange;
	uint64_t	i;
	int32_t		begin, end;

	if (value == NULL) {
		fatal_error(E_NOARG, "--ports", opt);
	}
	isrange = false;
	i = 0;
	while (value[i] != 0 && value[i] != '-') {
		++i;
	}
	if (value[i] == '-') {
		isrange = true;
	}
	value[i] = 0;
	begin = ft_atoi(value);
	if (isrange) {
		end = ft_atoi(value + i + 1);
	}
	else {
		end = begin;
	}
	check_ports(value, begin, end, isrange, opt);
	add_ports(opt, begin, end);
}
