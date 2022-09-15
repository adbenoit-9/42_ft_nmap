/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmap_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:28:36 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/15 13:37:14 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

void    handle_signal(int sig)
{
    if (sig == SIGALRM) {
        write(STDOUT_FILENO, ".", 1);
        alarm(1);
    }
}
