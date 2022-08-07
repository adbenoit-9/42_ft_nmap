/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:08:14 by adbenoit          #+#    #+#             */
/*   Updated: 2022/08/07 21:33:56 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap.h"

static void    init_param(t_param *param)
{
    param->ip = NULL;
    param->ports[0] = 1;    
    param->ports[1] = 1024;  
    param->scan = S_ACK | S_FIN | S_NULL | S_SYN | S_UDP | S_XMAS;
    param->speedup = 0;  
}

static void    print_usage(void)
{
    printf("Usage:\n");
    printf("  ft_nmap --ip <host> [Options]\n or\n");
    printf("  ft_nmap --file <path> [Options]\n");
    printf("\nOptions:\n");
    printf("--ip <host>                 host to scan\n");
    printf("--file <path>               read an IP list to scan from a file\n");
    printf("--ports <number/range>      ports to be scanned (default 1 to 1024)\n");
    printf("--scan <type>               type of scan to run (SYN, NULL, ACK, FIN, XMAS, UDP)\n");
    printf("--speedup <number>          number of threads (default 0), to make the scan faster\n");
    
}

static void    clean(t_param *param)
{
    if (param->ip != NULL) {
        for (int32_t i = 0; param->ip[i]; i++) {
            free(param->ip[i]);
        }
        free(param->ip);
    }    
}

static void    exit_help(t_param *param, char *value)
{
    (void)value;
    print_usage();
    clean(param);
    exit(FT_NMAP_OK);
}

t_param parser(int ac, char **av)
{
    t_param param;
    void    (*setters[NFLAG])(t_param *, char *) = {set_ip_from_file,
            exit_help, set_ip_from_arg, set_ports, set_scan, set_speedup};
    char  *flag_lst[] = {"--file", "--help", "--ip", "--ports", "--scan", "--speedup"};
    
    if (ac == 1) {
        print_usage();
    }
    init_param(&param);
    for (int32_t i = 1; av[i]; i++)  {
        int32_t j;
        for (j = 0; j < NFLAG; j++) {
            if (ft_strcmp(av[i], flag_lst[j]) == 0) {
                setters[j](&param, av[i + 1]);
                i++;
                break ;
            }
        }
        if (j == NFLAG) {
            exit(EXIT_FAILURE);
        }    
    }
    if (param.ip == NULL) {
        exit(EXIT_FAILURE);
    }
    return (param);
}
