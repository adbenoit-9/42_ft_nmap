/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reporty_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 10:12:44 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/20 18:16:37 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reporty.h"

void	report_config(t_nmap_setting *settings)
{
	char	ip_list[settings->ip_nb * INET6_ADDRSTRLEN + settings->ip_nb];
	char	scan_list[settings->scan_nb * 4 + settings->scan_nb];
	char	filter[36];

	ip_list[0] = 0;
	scan_list[0] = 0;
	for (int i = 0; i < settings->ip_nb; i++) {
		ft_strcat(ip_list, settings->ips[i]);
		ft_strcat(ip_list, " ");
	}
	for (int i = 0; i < settings->scan_nb; i++) {
		if (i != 0)
			ft_strcat(scan_list, " ");
		scan_to_str(scan_list, settings->scans[i]);
	}
	if ((settings->options & OPT_ALL_FILTER) == OPT_ALL_FILTER) {
		printf("Scan Configurations\n\
Target Ip-Address : %s\n\
No of Ports to scan : %d\n\
Scans to be performed : %s\n\
No of threads : %d\n\
Scanning..\n",
			ip_list, settings->port_nb, scan_list, settings->speedup);
	}
	else {
		status_to_str(filter, settings->options, " ");
		printf("Scan Configurations\n\
Target Ip-Address : %s\n\
No of Ports to scan : %d\n\
Scans to be performed : %s\n\
No of threads : %d\n\
Filter on port status : %s\n\
Scanning..\n",
			ip_list, settings->port_nb, scan_list, settings->speedup, filter);
	}
}
