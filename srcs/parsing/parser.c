/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:08:14 by adbenoit          #+#    #+#             */
/*   Updated: 2022/08/07 19:40:03 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap.h"

void    init_param(t_param *param)
{
    param->ip = NULL;
    param->ports[0] = 1;    
    param->ports[1] = 1024;  
    param->scan = S_ACK | S_FIN | S_NULL | S_SYN | S_UDP | S_XMAS;
    param->speedup = 0;  
}

void    print_usage(void)
{
    printf("ft_nmap [--help] [--ports [NOMBRE/PLAGE]] --ip ADRESSE IP [--speedup [NOMBRE]] [--scan [TYPE]]\n");
    printf("ft_nmap [--help] [--ports [NOMBRE/PLAGE]] --file FICHIER [--speedup [NOMBRE]] [--scan [TYPE]]\n");
}

void    clean(t_param *param)
{
    if (param->ip)
    {
        for (int32_t i = 0; param->ip[i]; i++)
        {
            free(param->ip[i]);
        }
        free(param->ip);
    }    
}

void    exit_help(t_param *param, char *value)
{
    (void)value;
    print_usage();
    clean(param);
    exit(FT_NMAP_OK);
}

t_param parser(int ac, char **av)
{
    t_param param;
    void    (*setters[NFLAG])(t_param *param, char *value) = {set_ip_from_file,
            exit_help, set_ip_from_arg, set_ports, set_scan, set_speedup};
    char  *flag_lst[] = {"--file", "--help", "--ip", "--ports", "--scan", "--speedup"};
    
    if (ac == 1)
        print_usage();
    init_param(&param);
    for (int32_t i = 1; av[i]; i++)
    {
        for (int32_t j = 0; j < NFLAG; j++)
        {
            if (ft_strcmp(av[i], flag_lst[j]) == 0)
                setters[j](&param, av[i + 1]);
        }
                
    }
    return (param);
}
