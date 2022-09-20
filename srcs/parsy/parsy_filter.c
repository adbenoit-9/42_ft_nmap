/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsy_filter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:01:31 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/20 12:50:09 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsy.h"

int	set_filter(t_nmap_setting *settings, char *value)
{
	static char	*state[] = {"open", "closed", "filtered", "unfiltered", NULL};
	static int	filter[] = {PORT_S_OPEN, PORT_S_CLOSED, PORT_S_FILTERED,
		PORT_S_UNFILTERED};
	int			ret = PARSY_OK;
	int			i;

	if (value == NULL) {
		ret = print_error(E_NOARG, "--filter");
	}
	else {
		for (i = 0; state[i]; i++) {
			if (ft_strcmp(value, state[i]) == 0) {
				settings->options |= filter[i];
				break ;
			}
		}
		if (state[i] == NULL) {
			ret = print_error(E_BADFILTER, value);
		}
	}
	return (ret);
}
