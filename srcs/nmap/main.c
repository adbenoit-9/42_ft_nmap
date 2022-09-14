/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:38:11 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/14 19:52:05 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmap.h"
#include "nmap_mapy_config.h"

static void	display_conf(t_nmap_setting *settings)
{
	char	ip_list[settings->ip_nb * INET6_ADDRSTRLEN + settings->ip_nb];
	char	scan_list[settings->scan_nb * 4 + settings->scan_nb];
	char	*scan_str[] = {"NULL", "SYN", "ACK", "FIN", "XMAS", "UDP"};
	char	scan_value[] = {FLAG_S_NULL, FLAG_S_SYN, FLAG_S_ACK, FLAG_S_FIN,
				FLAG_S_XMAS, FLAG_S_UDP};

	ip_list[0] = 0;
	scan_list[0] = 0;
	for (int i = 0; i < settings->ip_nb; i++) {
		strcat(ip_list, settings->ips[i]);
		strcat(ip_list, " ");
	}
	for (int i = 0; i < settings->scan_nb; i++) {
		for (int j = 0; j < 6; j++) {
			if (settings->scans[i] == scan_value[j]) {
				strcat(scan_list, scan_str[j]);
				break ;
			}
		}
		strcat(scan_list, " ");
	}
	printf("Scan Configurations\nTarget Ip-Address : %s\n\
No of Ports to scan : %d\n\
Scans to be performed : %s\n\
No of threads : %d\nScanning.\n",
		ip_list, settings->port_nb, scan_list, settings->speedup);
}

int main(int ac, char **av)
{
	int32_t 		r		= 0;
	uint8_t			*buf;
	t_root			*root;
	t_nmap_setting	*settings;
	
	buf = (uint8_t*)malloc(SIZE);
	bzero(buf, SIZE);
	if (buf == NULL) {
		r = -1;
	}
	if (r == 0) {
		root = (t_root*)buf;
		root->map = &buf[sizeof(t_root)];
		settings = &root->client;
		/* Parsing */
		r = parser(ac, av, settings);
		if (r == PARSY_OK) {
			/* Update size of tree params */
			((t_root*)buf)->st_nb = settings->ip_nb;
			((t_root*)buf)->nd_nb = settings->port_nb;
			((t_root*)buf)->rd_nb = settings->scan_nb;
			/* Fill parameters in tree */
			if (set_iter_st(root, set_sockaddr))
				return (-1);
			if (set_iter_st(root, set_src_sockaddr))
				return (-1);
			if (set_iter_nd(root, iter_set_port))
				return (-1);
			if (set_iter_rd(root, iter_set_tcpflag))
				return (-1);
			display_conf(settings);
			scany(settings, root);
		}
		else if (r == PARSY_STOP)
			r = PARSY_KO;
	}
	return (r);
}
