/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:11:37 by adbenoit          #+#    #+#             */
/*   Updated: 2022/08/08 12:02:32 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap.h"

void    fatal_error(int16_t error, char *arg, t_opt *opt)
{
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
        PRINT_EBADSCAN(arg);
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
    default:
        dprintf(STDERR_FILENO, "%s\n", arg);
        break;
    }
    ft_lstclear(&opt->ip_lst, free);
	exit(EXIT_FAILURE);
}
