/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:57:03 by adbenoit          #+#    #+#             */
/*   Updated: 2022/08/21 17:42:08 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "nmap_structs.h"
#include "ft_nmap_parsing.h"
#include "ft_nmap_error.h"
#include <errno.h>

void    set_scan(t_opt *opt, char *value)
{
	char	*scan_list[] = {"SYN", "NULL", "ACK", "FIN", "XMAS", "UDP", NULL};
	char	value_list[] = {S_SYN, S_NULL, S_ACK, S_FIN, S_XMAS, S_UDP};

	if (value == NULL) {
		fatal_error(E_NOARG, "--scan", opt);
	}
	for (int32_t i = 0; scan_list[i]; i++) {
		if (ft_strcmp(value, scan_list[i]) == 0) {
			opt->scans |= value_list[i];
			return ;
		}
	}
	fatal_error(E_BADSCAN, value, opt);
}
