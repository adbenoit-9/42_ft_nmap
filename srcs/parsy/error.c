/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:11:37 by adbenoit          #+#    #+#             */
/*   Updated: 2022/08/21 20:27:11 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap_parsing.h"

#ifdef DEBUG

static void print_nmap_setting(t_nmap_setting opt)
{
	char	ip[INET6_ADDRSTRLEN];
	char	*scan_str[] = {"SYN", "NULL", "ACK", "FIN", "XMAS", "UDP"};
	char	scan_value[] = {S_SYN, S_NULL, S_ACK, S_FIN, S_XMAS, S_UDP};
	t_list	*tmp;
	
	printf("-- options --\n");
	printf("ips:");
	tmp = opt.ip_lst;
	while (tmp != NULL) {
		if (((t_ip *)(tmp->content))->sock.ss_family == AF_INET) {
			inet_ntop(AF_INET, &((struct sockaddr_in *)&(
						(t_ip *)(tmp->content)
					)->sock
				)->sin_addr, ip, INET_ADDRSTRLEN);
		}
		else {
			inet_ntop(AF_INET6, &((struct sockaddr_in6 *)&(
						(t_ip *)(tmp->content)
					)->sock
				)->sin6_addr, ip, INET6_ADDRSTRLEN);
		}
		printf(" %s", ip);
		tmp = tmp->next;
	}
	printf("\nports:");
	for (uint32_t i = 0; opt.ports[i] != 0 && i < PORT_LIMIT; i++)
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

void    fatal_error(int16_t error, char *arg)
{
	dprintf(STDERR_FILENO, "ft_nmap: ");
	switch (error)
	{
	case E_NOHOST:
		PRINT_ENOHOST;
		break;
	case E_BADHOST:
		PRINT_EBADHOST(arg);
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
	exit(EXIT_FAILURE);
}
