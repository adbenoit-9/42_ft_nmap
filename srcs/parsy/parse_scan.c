/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:57:03 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/13 16:24:41 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "nmap_structs.h"
#include "ft_nmap_parsing.h"
#include "ft_nmap_error.h"
#include <errno.h>

void    set_scan(t_nmap_setting *settings, char *value)
{
	char	*scan_list[] = {"NULL", "SYN", "ACK", "FIN", "XMAS", "UDP", NULL};
	char	value_list[] = {FLAG_S_NULL, FLAG_S_SYN, FLAG_S_ACK, FLAG_S_FIN,
				FLAG_S_XMAS, FLAG_S_UDP};

	if (value == NULL) {
		fatal_error(E_NOARG, "--scan");
	}
	else if (settings->scan_nb == SCAN_LIMIT)
		return ;
	for (int32_t i = 0; scan_list[i]; i++) {
		if (ft_strcmp(value, scan_list[i]) == 0) {
			settings->scans[settings->scan_nb] = value_list[i];
			++settings->scan_nb;
			return ;
		}
	}
	fatal_error(E_BADSCAN, value);
}
