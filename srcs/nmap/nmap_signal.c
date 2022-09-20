/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmap_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:28:36 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/20 16:06:54 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void    handle_sigaction(int signum, siginfo_t *siginfo, void *param)
{
    (void)param;
    (void)siginfo;
    if (signum == SIGALRM) {
#ifndef DEBUG
        write(STDOUT_FILENO, ".", 1);
#endif
        alarm(1);
    }
}
