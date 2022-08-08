/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_seedup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:57:18 by adbenoit          #+#    #+#             */
/*   Updated: 2022/08/08 13:57:38 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap.h"

void    set_speedup(t_opt *opt, char *value)
{
	int32_t	nb;

	if (value == NULL) {
		fatal_error(E_NOARG, "--speedup", opt);
	}
	nb = ft_atoi(value);
	if (ft_isnumber(value) == false || nb < 0 || nb > 250) {
		fatal_error(E_BADSPEEDUP, value, opt);
	}
	opt->speedup = (uint8_t)nb;
}
