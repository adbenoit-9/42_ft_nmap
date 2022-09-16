/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsy_ports.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:53:39 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/16 10:43:11 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsy.h"
#include "parsy_error.h"

static int	check_ports(char *value, int32_t begin, int32_t end, bool isrange)
{
	int			ret = PARSY_OK;
	uint64_t	i = ft_strlen(value);

	if (ft_isnumber(value) == false || (isrange == true &&
			ft_isnumber(value + i) == false)) {
		if (isrange == true) {
			value[i] = '-';
		}
		ret = print_error(E_BADPORT, value);
	}
	else if (end - begin < 0 || end - begin > PORT_LIMIT) {
		ret = print_error(E_LIMIT_EXCEED, NULL);
	}
	else if (begin <= 0 || begin > PORT_MAX) {
		ret = print_error(E_BADPORT, value);
	}
	else if (end <= 0 || end > PORT_MAX) {
		ret = print_error(E_BADPORT, value + i + 1);
	}
	return (ret);
}

static int32_t	copy_ports_inf(uint16_t *dest, uint16_t *src, uint16_t max)
{
	int32_t i;
	
	for (i = 0; src[i] < max && src[i] != 0 && i < PORT_LIMIT; i++) {
		dest[i] = src[i];
	}
	return (i);
}

static int32_t	copy_ports_sup(uint16_t *dest, uint16_t *src, uint16_t min, int32_t n)
{
	for (uint16_t i = 0; src[i] != 0; i++) {
		if (n >= PORT_LIMIT)
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
	int	ret = PARSY_OK;
	
	for (; ret == PARSY_OK && begin <= end; i++, begin++) {
		if (i >= PORT_LIMIT) {
			ret = PARSY_KO;
		}
		else {
			dest[i] = begin;
		}
	}
	if (ret != PARSY_KO) {
		ret = i;
	}
	return (ret);
}

static int	add_ports(t_nmap_setting *settings, int32_t begin, int32_t end)
{
	int32_t		i;
	int32_t		ret = PARSY_OK;
	uint16_t	new_ports[PORT_LIMIT];

	bzero(new_ports, PORT_LIMIT * sizeof(uint16_t));
	i = copy_ports_inf(new_ports, settings->ports, begin);
	i = copy_new_range(new_ports, i, begin, end);
	if (i == -1) {
		ret = print_error(E_LIMIT_EXCEED, NULL);
	}
	else {
		i = copy_ports_sup(new_ports, settings->ports, end, i);
		if (i == -1) {
			ret = print_error(E_LIMIT_EXCEED, NULL);
		}
		else {
			ft_memcpy(settings->ports, new_ports, PORT_LIMIT * sizeof(uint16_t));
		}
	}
	return (ret);
}

int    set_ports(t_nmap_setting *settings, char *value)
{
	bool		isrange;
	uint64_t	i;
	int32_t		begin, end;
	int			ret = PARSY_OK;

	if (value == NULL) {
		ret = print_error(E_NOARG, "--ports");
	}
	else {
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
		ret = check_ports(value, begin, end, isrange);
		if (ret == PARSY_OK)
			ret = add_ports(settings, begin, end);
	}
	return (ret);
}
