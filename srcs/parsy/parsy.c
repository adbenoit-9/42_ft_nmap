/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:08:14 by adbenoit          #+#    #+#             */
/*   Updated: 2022/08/22 14:28:09 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap_parsing.h"
#include "proty_tcp.h"

#define PARSY_OK 0

static uint8_t default_scans[SCAN_LIMIT] = {FLAG_S_NULL, FLAG_S_SYN, FLAG_S_ACK, FLAG_S_FIN, FLAG_S_XMAS};

static void    init_nmap_settings(t_nmap_setting *settings)
{
	ft_bzero(settings->ports, PORT_LIMIT * sizeof(uint16_t));
	ft_bzero(settings->ips, IP_LIMIT * sizeof(uint64_t));
	ft_bzero(settings->scans, SCAN_LIMIT * sizeof(uint8_t));
	settings->speedup = 0;
	settings->ip_nb = 0;
	settings->port_nb = 1024;
	settings->scan_nb = 0;
}

static void    print_usage(void)
{
	printf("Usage:\n");
	printf("  ft_nmap --ip <host> [opts]\n or\n");
	printf("  ft_nmap --file <path> [opts]\n");
	printf("\nopts:\n");
	printf("--ip <host>                 host to scan\n");
	printf("--file <path>               read an IP list to scan from a file\n");
	printf("--ports <number/range>      ports to be scanned (default 1 to PORT_LIMIT)\n");
	printf("--scan <type>               type of scan to run (SYN, NULL, ACK, FIN, XMAS, UDP)\n");
	printf("--speedup <number>          number of threads (default 0), to make the scan faster\n");
	
}

static void    exit_help(t_nmap_setting *opt, char *value)
{
	(void)value;
	(void)opt;
	print_usage();
	exit(EXIT_SUCCESS);
}

int parser(int ac, char **av, t_nmap_setting	*settings)
{
	void			(*flags_handler[])(t_nmap_setting *, char *) = {
						set_ip_from_file, exit_help, set_ip_from_arg,
						set_ports, set_scan, set_speedup};
	char			*flag_lst[] = {"--file", "--help", "--ip", "--ports",
						"--scan", "--speedup", NULL};
	int64_t i, j;

	if (ac == 1) {
		print_usage();
		exit(EXIT_FAILURE);
	}
	init_nmap_settings(settings);
	for (i = 1; av[i]; i++)  {
		for (j = 0; flag_lst[j]; j++) {
			if (ft_strcmp(av[i], flag_lst[j]) == 0) {
				flags_handler[j](settings, av[i + 1]);
				i++;
				break ;
			}
		}
		if (j == NFLAG) {
			if (av[i][0] == '-') {
				fatal_error(E_BADOPT, av[i]);
			}
			else {
				fatal_error(E_BADARG, av[i]);
			}
		}
	}
	if (settings->ip_nb == 0) {
		fatal_error(E_NOHOST, NULL);
	}
	if (settings->scan_nb == 0) {
		memcpy(settings->scans, default_scans, SCAN_LIMIT);
		settings->scan_nb = 6;
	}
	if (settings->ports[0] == 0) {
		copy_new_range(settings->ports, 0, 1, PORT_LIMIT);
	}
	return (PARSY_OK);
}
