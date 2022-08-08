/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:11:37 by adbenoit          #+#    #+#             */
/*   Updated: 2022/08/08 15:29:10 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap.h"

#ifdef DEBUG

static void print_option(t_opt opt)
{
	char	*scan_str[] = {"SYN", "NULL", "ACK", "FIN", "XMAS", "UDP"};
	char	scan_value[] = {S_SYN, S_NULL, S_ACK, S_FIN, S_XMAS, S_UDP};
	
	printf("-- options --\n");
	printf("ip:\n");
	printf("ports:");
	for (uint32_t i = 0; opt.ports[i] != 0 && i < PORTS_SCAN_LIMIT; i++)
		printf(" %d", opt.ports[i]);
	printf("\nscans:");
	for (int16_t i = 0; i < 6; i++) {
		if (opt.scans & scan_value[i]) {
			printf(" %s", scan_str[i]);
		}
	}
	printf("\nspeedup: %d\n", opt.speedup);
}

#endif

void    fatal_error(int16_t error, char *arg, t_opt *opt)
{
#ifdef DEBUG
	print_option(*opt);
#endif
	dprintf(STDERR_FILENO, "ft_nmap: ");
	switch (error)
	{
	case E_NOIP:
		PRINT_ENOIP;
		break;
	case E_BADIP:
		PRINT_EBADIP(arg);
		break;
	case E_BADFILE:
		PRINT_EBADFILE(arg);
		break;
	case E_BADPORT:
		PRINT_EBADPORT(arg);
		break;
	case E_BADRANGE:
		PRINT_EBADRANGE(arg);
		break;
	case E_BADSCAN:
		PRINT_EBADSCAN(arg);
		break;
	case E_BADSPEEDUP:
		PRINT_EBADSPEEDUP(arg);
		break;
	case E_BADARG:
		PRINT_EBADARG(arg);
		break;
	case E_NOARG:
		PRINT_ENOARG(arg);
		break;
	case E_BADOPT:
		PRINT_EBADOPT(arg);
		break;
	case E_LIMIT_EXCEED:
		PRINT_ELIMEXC;
		break;
	default:
		dprintf(STDERR_FILENO, "%s\n", arg);
		break;
	}
	ft_lstclear(&opt->ip_lst, free);
	exit(EXIT_FAILURE);
}
