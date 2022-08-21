/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:08:14 by adbenoit          #+#    #+#             */
/*   Updated: 2022/08/21 17:42:08 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_nmap.h"
#include "nmap_structs.h"
#include "ft_nmap_error.h"

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

// TODO LMA take input
static void init_scan_by_port(t_opt *opt, t_nmap_app *ip)
{
//    t_list  *newscan, *it;
//    void    *content;

	(void)opt;
	(void)ip;
	// TODO 			integrate this with sety
//    it = ip->cross.nd;
//    while (it) {
//		while (opt->scans != 0)
//		{
//			if ((opt->scans & S_SYN) != 0)
//			{
//				opt->scans &= ~S_SYN;
//            	content = calloc(1, sizeof(t_scan));
//            	if (content == NULL)
//				{
//            	    fatal_error(-1, STR_ENOMEM, opt);
//            	}
//				memset(((t_scan*)content)->cross.execution_target, 0, MAX_EXECUTION_LIST);
//				memset(((t_scan*)content)->cross.execution_task_list, 0, MAX_EXECUTION_LIST);
//				((t_scan*)content)->cross.execution_task_list[0] = 0 | TASK_EXECUTION_TODO_MSK;
//				((t_scan*)content)->cross.execution_task_list[1] = 1 | TASK_EXECUTION_TODO_MSK;
//				((t_scan*)content)->cross.execution_task_list[2] = 2 | TASK_EXECUTION_TODO_MSK;
//				((t_scan*)content)->cross.execution_task_list[3] = 3 | TASK_EXECUTION_TODO_MSK;
//				((t_scan*)content)->cross.execution_task_list[4] = 4 | TASK_EXECUTION_TODO_MSK;
//				// TODO set tcpflag here
////				((t_scan*)content)->cross.lock = 0;
//            	newscan = ft_lstnew(content);
//            	if (newscan == NULL) {
//            	    fatal_error(-1, STR_ENOMEM, opt);
//            	}
//            	if (((t_app *)it->content)->cross.rd == NULL) {
//            	    ((t_app *)it->content)->cross.rd = newscan;
//            	}
//            	else {
//            	    ft_lstadd_back(&((t_app *)it->content)->cross.rd, newscan);
//            	}
//			}
//			else
//			{
//				opt->scans = 0;
//			}
//		}
//        for (uint16_t i = 0; i < MAX_SCAN_TYPE; i++) {
//            content = calloc(1, sizeof(t_scan));
//            if (content == NULL) {
//                fatal_error(-1, STR_ENOMEM, opt);
//            }
////			((t_scan*)content)->cross.scan_id = i;
//			memset(((t_scan*)content)->cross.execution_target, 0, MAX_EXECUTION_LIST); // TODO DEBUG
//			memset(((t_scan*)content)->cross.execution_task_list, 0, MAX_EXECUTION_LIST); // TODO DEBUG
//			((t_scan*)content)->cross.execution_task_list[0] = 0 | TASK_EXECUTION_TODO_MSK;
//			((t_scan*)content)->cross.execution_task_list[1] = 1 | TASK_EXECUTION_TODO_MSK;
//			((t_scan*)content)->cross.execution_task_list[2] = 2 | TASK_EXECUTION_TODO_MSK;
//			((t_scan*)content)->cross.execution_task_list[3] = 3 | TASK_EXECUTION_TODO_MSK;
//			((t_scan*)content)->cross.execution_task_list[4] = 4 | TASK_EXECUTION_TODO_MSK;
//			// TODO set tcpflag here
////			((t_scan*)content)->cross.lock = 0;
//            newscan = ft_lstnew(content);
//            if (newscan == NULL) {
//                fatal_error(-1, STR_ENOMEM, opt);
//            }
//            if (((t_app *)it->content)->cross.rd == NULL) {
//                ((t_app *)it->content)->cross.rd = newscan;
//            }
//            else {
//                ft_lstadd_back(&((t_app *)it->content)->cross.rd, newscan);
//            }
//        }
//        it = it->next;
//    }
}

static void init_port_by_ip(t_opt *opt)
{
    t_list  *newport, *it;
    void    *content;

    it = opt->ip_lst;
    while (it) {
        for (uint16_t i = 0; i < PORTS_SCAN_LIMIT && opt->ports[i] != 0; i++) {
            content = calloc(1, sizeof(t_nmap_app));
            if (content == NULL) {
                fatal_error(-1, STR_ENOMEM, opt);
            }
            ft_memcpy(&((t_nmap_app*)content)->port,&opt->ports[i], sizeof(uint16_t));
            newport = ft_lstnew(content);
            if (newport == NULL) {
                fatal_error(-1, STR_ENOMEM, opt);
            }
//            if (((t_nmap_app *)it->content)->cross.nd == NULL) {
//                ((t_nmap_app *)it->content)->cross.nd = newport;
//            }
//            else {
//                ft_lstadd_back(&((t_nmap_app *)it->content)->cross.nd, newport);
//            }
        }
		init_scan_by_port(opt, (t_nmap_app *)it->content);
        it = it->next;
    }
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
        fatal_error(E_NOHOST, NULL, &opt);
    }
    if (opt.scans == NONE) {
        opt.scans = S_ACK | S_FIN | S_NULL | S_SYN | S_UDP | S_XMAS;
    }
    if (opt.ports[0] == NONE) {
        copy_new_range(opt.ports, 0, 1, PORTS_SCAN_LIMIT);
    }
    init_port_by_ip(&opt);
    return (opt);
}
