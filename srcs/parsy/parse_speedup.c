/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_speedup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:57:18 by adbenoit          #+#    #+#             */
/*   Updated: 2022/08/21 20:02:15 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_nmap_parsing.h"
#include "ft_nmap_error.h"

void    set_speedup(t_nmap_setting *settings, char *value)
{
	int32_t	nb;

	if (value == NULL) {
		fatal_error(E_NOARG, "--speedup");
	}
	nb = ft_atoi(value);
	if (ft_isnumber(value) == false || nb < 0 || nb > 250) {
		fatal_error(E_BADSPEEDUP, value);
	}
	settings->speedup = (uint8_t)nb;
}
