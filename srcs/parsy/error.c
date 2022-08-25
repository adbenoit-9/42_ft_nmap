/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:11:37 by adbenoit          #+#    #+#             */
/*   Updated: 2022/08/25 18:53:27 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap_parsing.h"

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
