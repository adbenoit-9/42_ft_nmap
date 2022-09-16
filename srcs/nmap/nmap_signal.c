/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmap_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:28:36 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/16 10:37:13 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

void    handle_signal(int sig)
{
    if (sig == SIGALRM) {
#ifndef DEBUG
        write(STDOUT_FILENO, ".", 1);
#endif
        alarm(1);
    }
}
