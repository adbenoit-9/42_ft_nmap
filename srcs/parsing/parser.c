/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:08:14 by adbenoit          #+#    #+#             */
/*   Updated: 2022/08/08 15:18:50 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap.h"

static void    init_opt(t_opt *opt)
{
    opt->ip_lst = NULL;
    ft_bzero(opt->ports, PORTS_SCAN_LIMIT * sizeof(uint16_t));
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
    printf("--ports <number/range>      ports to be scanned (default 1 to PORTS_SCAN_LIMIT)\n");
    printf("--scan <type>               type of scan to run (SYN, NULL, ACK, FIN, XMAS, UDP)\n");
    printf("--speedup <number>          number of threads (default 0), to make the scan faster\n");
    
}

static void    exit_help(t_opt *opt, char *value)
{
    (void)value;
    print_usage();
    ft_lstclear(&opt->ip_lst, free);
    exit(EXIT_SUCCESS);
}

t_opt parser(int ac, char **av)
{
    t_opt opt;
    void    (*flags_handler[])(t_opt *, char *) = {set_ip_from_file,
            exit_help, set_ip_from_arg, set_ports, set_scan, set_speedup};
    char  *flag_lst[] = {"--file", "--help", "--ip", "--ports",
            "--scan", "--speedup", NULL};
    int64_t i, j;

    if (ac == 1) {
        print_usage();
        exit(EXIT_FAILURE);
    }
    init_opt(&opt);
    for (i = 1; av[i]; i++)  {
        for (j = 0; flag_lst[j]; j++) {
            if (ft_strcmp(av[i], flag_lst[j]) == 0) {
                flags_handler[j](&opt, av[i + 1]);
                i++;
                break ;
            }
        }
        if (j == NFLAG) {
            if (av[i][0] == '-') {
                fatal_error(E_BADOPT, av[i], &opt);
            }
            else {
                fatal_error(E_BADARG, av[i], &opt);
            }
        }
    }
    if (opt.ip_lst == NULL) {
        fatal_error(E_NOIP, NULL, &opt);
    }
    if (opt.scans == NONE) {
        opt.scans = S_ACK | S_FIN | S_NULL | S_SYN | S_UDP | S_XMAS;
    }
    return (opt);
}
