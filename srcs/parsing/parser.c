/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:08:14 by adbenoit          #+#    #+#             */
/*   Updated: 2022/08/21 19:37:30 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_nmap.h"
#include "nmap_structs.h"
#include "ft_nmap_error.h"

static void    init_nmap_setting(t_nmap_setting *opt)
{
	opt->ip_lst = NULL;
	ft_bzero(opt->ports, PORT_LIMIT * sizeof(uint16_t));
	opt->scans = NONE;
	opt->speedup = 0;
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
	print_usage();
	ft_lstclear(&opt->ip_lst, free);
	exit(EXIT_SUCCESS);
}

// TODO LMA take input
static void init_scan_by_port(t_nmap_setting *opt, t_nmap_app *ip)
{

	(void)opt;
	(void)ip;
}

static void init_port_by_ip(t_nmap_setting *opt)
{
	t_list  *newport, *it;
	void    *content;

	it = opt->ip_lst;
	while (it) {
		for (uint16_t i = 0; i < PORT_LIMIT && opt->ports[i] != 0; i++) {
			content = calloc(1, sizeof(t_nmap_app));
			if (content == NULL) {
				fatal_error(-1, STR_ENOMEM, opt);
			}
			ft_memcpy(&((t_nmap_app*)content)->port,&opt->ports[i], sizeof(uint16_t));
			newport = ft_lstnew(content);
			if (newport == NULL) {
				fatal_error(-1, STR_ENOMEM, opt);
			}
		}
		init_scan_by_port(opt, (t_nmap_app *)it->content);
		it = it->next;
	}
}

t_nmap_setting parser(int ac, char **av)
{
	t_nmap_setting	settings;
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
	init_nmap_setting(&settings);
	for (i = 1; av[i]; i++)  {
		for (j = 0; flag_lst[j]; j++) {
			if (ft_strcmp(av[i], flag_lst[j]) == 0) {
				flags_handler[j](&settings, av[i + 1]);
				i++;
				break ;
			}
		}
		if (j == NFLAG) {
			if (av[i][0] == '-') {
				fatal_error(E_BADOPT, av[i], &settings);
			}
			else {
				fatal_error(E_BADARG, av[i], &settings);
			}
		}
	}
	if (settings.ip_lst == NULL) {
		fatal_error(E_NOHOST, NULL, &settings);
	}
	if (settings.scans == NONE) {
		settings.scans = S_ACK | S_FIN | S_NULL | S_SYN | S_UDP | S_XMAS;
	}
	if (settings.ports[0] == NONE) {
		copy_new_range(settings.ports, 0, 1, PORT_LIMIT);
	}
	// init_port_by_ip(&settings);
	return (settings);
}
