/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsy_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 10:45:24 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/20 12:29:37 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSY_ERROR_H
# define PARSY_ERROR_H

# define E_NOHOST 1
# define E_BADHOST 2
# define E_BADFILE 3
# define E_BADPORT 4
# define E_BADRANGE 5
# define E_BADSCAN 6
# define E_BADSPEEDUP 7
# define E_BADARG 8
# define E_NOARG 9
# define E_BADOPT 10
# define E_LIMIT_EXCEED 11
# define E_NOPERM 12
# define E_BADFILTER 13

# define PRINT_ENOHOST do {dprintf(STDERR_FILENO,\
            "usage error: IP address required\n");}  while(0)
# define PRINT_EBADHOST(str) do {dprintf(STDERR_FILENO,\
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
# define PRINT_ELIMEXC do {dprintf(STDERR_FILENO,\
            "maximum limit of the number of ports scanned cannot exceed 1024\n");\
            } while(0)
# define PRINT_ENOPERM do {dprintf(STDERR_FILENO,\
            "You requested a scan type which requires root privileges.\nQUITTING!\n");\
            } while(0)
# define PRINT_EBADFILTER(str) do {dprintf(STDERR_FILENO,\
            "invalid filter: '%s'\n", str);\
            } while(0)
# define STR_ENOMEM "Out of memory"

int    print_error(int16_t error, char *arg);

#endif
