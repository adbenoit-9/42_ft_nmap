/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsy_scan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:57:03 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/16 10:43:11 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "nmap_structs.h"
#include "parsy.h"
#include "parsy_error.h"
#include <errno.h>

int    set_scan(t_nmap_setting *settings, char *value)
{
	char	*scan_list[] = {"NULL", "SYN", "ACK", "FIN", "XMAS", "UDP", NULL};
	char	value_list[] = {FLAG_S_NULL, FLAG_S_SYN, FLAG_S_ACK, FLAG_S_FIN,
				FLAG_S_XMAS, FLAG_S_UDP};
	int		ret = PARSY_OK;

	if (value == NULL) {
		ret = print_error(E_NOARG, "--scan");
	}
	else if (settings->scan_nb != SCAN_LIMIT) {
		int32_t i = 0;
		for (; scan_list[i]; i++) {
			if (ft_strcmp(value, scan_list[i]) == 0) {
				settings->scans[settings->scan_nb] = value_list[i];
				++settings->scan_nb;
				break ;
			}
		}
		if (scan_list[i] == NULL)
			ret = print_error(E_BADSCAN, value);
	}
	return (ret);
}
