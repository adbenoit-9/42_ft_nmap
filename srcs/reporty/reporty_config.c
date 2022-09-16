/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reporty_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 10:12:44 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/16 10:25:22 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reporty.h"

void	report_config(t_nmap_setting *settings)
{
	char	ip_list[settings->ip_nb * INET6_ADDRSTRLEN + settings->ip_nb];
	char	scan_list[settings->scan_nb * 4 + settings->scan_nb];
	char	*scan_str[] = {"NULL", "SYN", "ACK", "FIN", "XMAS", "UDP"};
	char	scan_value[] = {FLAG_S_NULL, FLAG_S_SYN, FLAG_S_ACK, FLAG_S_FIN,
				FLAG_S_XMAS, FLAG_S_UDP};

	ip_list[0] = 0;
	scan_list[0] = 0;
	for (int i = 0; i < settings->ip_nb; i++) {
		ft_strcat(ip_list, settings->ips[i]);
		ft_strcat(ip_list, " ");
	}
	for (int i = 0; i < settings->scan_nb; i++) {
		for (int j = 0; j < 6; j++) {
			if (settings->scans[i] == scan_value[j]) {
				ft_strcat(scan_list, scan_str[j]);
				break ;
			}
		}
		ft_strcat(scan_list, " ");
	}
	printf("Scan Configurations\nTarget Ip-Address : %s\n\
No of Ports to scan : %d\n\
Scans to be performed : %s\n\
No of threads : %d\nScanning..\n",
		ip_list, settings->port_nb, scan_list, settings->speedup);
}
