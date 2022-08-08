/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nmap_error.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 10:45:24 by adbenoit          #+#    #+#             */
/*   Updated: 2022/08/08 12:01:37 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NMAP_ERROR_H
# define FT_NMAP_ERROR_H

# define E_NOIP 1
# define E_BADIP 2
# define E_BADFILE 3
# define E_BADPORT 4
# define E_BADRANGE 5
# define E_BADSCAN 6
# define E_BADSPEEDUP 7
# define E_BADARG 8
# define E_NOARG 9
# define E_BADOPT 10

# define PRINT_ENOIP do {dprintf(STDERR_FILENO,\
            "usage error: IP address required\n");}  while(0)
# define PRINT_EBADIP(str) do {dprintf(STDERR_FILENO,\
            "%s: Name or service not known\n", str);} while(0)
# define PRINT_EBADFILE(str) do {dprintf(STDERR_FILENO,\
            "%s: No such file or directory\n", str);} while(0)
# define PRINT_EBADPORT(str) do {dprintf(STDERR_FILENO,\
            "invalid port: '%s': 1 <= value <= 65536\n", str);} while(0)
# define PRINT_EBADRANGE(str) do {dprintf(STDERR_FILENO,\
            "invalid ports range: '%s'\n", str);} while(0)
# define PRINT_EBADSCAN(str) do {dprintf(STDERR_FILENO,\
            "invalid scan: '%s'\n", str);} while(0)
# define PRINT_EBADSPEEDUP(str) do {dprintf(STDERR_FILENO,\
            "invalid speedup: '%s': 0 <= value <= 250\n", str);} while(0)
# define PRINT_EBADARG(str) do {dprintf(STDERR_FILENO,\
            "invalid agument: '%s'\n", str);} while(0)
# define PRINT_ENOARG(str) do {dprintf(STDERR_FILENO,\
            "option '%s' requires an argument\n", str);} while(0)
# define PRINT_EPERM(str) do {dprintf(STDERR_FILENO,\
            "Operation not permitted", str);} while(0)
# define PRINT_EBADOPT(str) do {dprintf(STDERR_FILENO,\
            "invalid option '%s'\n", str);} while(0)

# define STR_ENOMEM "Out of memory"

void    fatal_error(int16_t error, char *arg, t_opt *opt);

#endif