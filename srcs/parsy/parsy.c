/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:08:14 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/21 14:41:01 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsy.h"

static void    init_nmap_settings(t_nmap_setting *settings)
{
	ft_bzero(settings, sizeof(t_nmap_setting));
	settings->addr_family = AF_UNSPEC;
}

static void    print_usage(void)
{
	printf("Usage:\n");
	printf("  ft_nmap [OPTIONS]\n");
	printf("\nOptions:\n");
	printf("--help                      Print this help summary page\n");
	printf("--ip <host>                 Ip addresses to scan\n");
	printf("--file <name>               File name containing IP addresses to scan,\n");
	printf("--filter <state>            Filter the output by the state of the port (open, closed, filtered, unfiltered)\n");
	printf("--ports <number/range>      Ports to be scanned (default 1 to 1024)\n");
	printf("--scan <type>               Type of scan to run (SYN, NULL, ACK, FIN, XMAS, UDP)\n");
	printf("--speedup <number>          Number of parallel threads to use (default 0, max 250)\n");
	printf("--verbose                   verbose output.\n");
	
}

static int    exit_help(t_nmap_setting *opt, char *value)
{
	(void)value;
	(void)opt;
	print_usage();
	return (PARSY_STOP);
}

static int	parse_options(char **av, t_nmap_setting *settings)
{
	int			(*flags_handler[])(t_nmap_setting *, char *) = {
						set_ip_from_file,
						exit_help, set_ip_from_arg,
						set_ports, set_scan, set_speedup, set_filter,
						set_verbose, set_af_inet, set_af_inet6};
						
	char			*flag_lst[] = {"--file", "--help", "--ip", "--ports",
						"--scan", "--speedup", "--filter", "--verbose",
						"-4", "-6", NULL};
	int64_t i, j;
	int	ret = PARSY_OK;
	
	for (i = 1; ret == PARSY_OK && av[i]; i++)  {
		for (j = 0; flag_lst[j]; j++) {
			if (ft_strcmp(av[i], flag_lst[j]) == 0) {
				ret = flags_handler[j](settings, av[i + 1]);
				if (j < NB_OPT - 3)
					i++;
				break ;
			}
		}
		if (j == NB_OPT) {
			if (av[i][0] == '-') {
				ret = print_error(E_BADOPT, av[i]);
			}
			else {
				ret = print_error(E_BADARG, av[i]);
			}
		}
	}
	return (ret);
}

static void	default_settings(t_nmap_setting *settings)
{
	static uint8_t default_scans[SCAN_LIMIT] = {
		FLAG_S_NULL, FLAG_S_SYN, FLAG_S_ACK, FLAG_S_FIN, FLAG_S_XMAS, FLAG_S_UDP};
	
	if (settings->scan_nb == 0) {
		memcpy(settings->scans, default_scans, SCAN_LIMIT);
		settings->scan_nb = SCAN_LIMIT;
	}
	if (settings->ip_nb > IP_LIMIT) {
		settings->ip_nb = IP_LIMIT;
		dprintf(STDERR_FILENO, "Warning: only the first %d addresses will be scanned\n", IP_LIMIT);
	}
	if (settings->port_nb == 0) {
		copy_new_range(settings->ports, 0, 1, PORT_LIMIT);
		settings->port_nb = PORT_LIMIT;
	}
	if (!(settings->options & OPT_ALL_FILTER)) {
		settings->options |= OPT_ALL_FILTER;
	}
}

int parser(int ac, char **av, t_nmap_setting *settings)
{
	int		ret = PARSY_OK;

	if (ac == 1) {
		print_usage();
		ret = PARSY_KO;
	}
	else {
		init_nmap_settings(settings);
		ret = parse_options(av, settings);
		if (ret == PARSY_OK) {
			if (settings->ip_nb == 0) {
				ret = print_error(E_NOHOST, NULL);
			}
			else {
				if (settings->ports[0] != 0) {
					while (settings->port_nb < PORT_LIMIT
							&& settings->ports[settings->port_nb])
						++settings->port_nb;
				}
				default_settings(settings);
				if (getuid() != 0) {
					ret = print_error(E_NOPERM, NULL);
				}
			}
		}
	}
	return (ret);
}