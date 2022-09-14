/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_speedup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:57:18 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/14 10:35:02 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_nmap_parsing.h"
#include "ft_nmap_error.h"

int    set_speedup(t_nmap_setting *settings, char *value)
{
	int32_t	nb;
	int32_t	ret = PARSY_OK;

	if (value == NULL) {
		ret = print_error(E_NOARG, "--speedup");
	}
	else {
		nb = ft_atoi(value);
		if (ft_isnumber(value) == false || nb < 0 || nb > 250) {
			ret = print_error(E_BADSPEEDUP, value);
		}
		else {
			settings->speedup = (uint8_t)nb;
		}
	}
	return (ret);
}
