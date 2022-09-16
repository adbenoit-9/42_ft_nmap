/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:37:26 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/16 16:41:02 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NMAP_H
# define NMAP_H

# include <signal.h>
# include <sys/time.h>
# include <stdint.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <pcap/pcap.h>
# include <pthread.h>
# include "mapy.h"
# include "nmap_hooks.h"
# include "parsy_export.h"
# include "analysy.h"
# include "nmap_mapy_config.h"
# include "export_reporty.h"

# define NMAP_RUN 1
# define NMAP_STOP 0

typedef struct s_nmap_controller
{
	pthread_mutex_t	mutex;
	uint8_t			status;
	t_root			*root;	
}				t_nmap_controller;

int	    ft_nmap(t_nmap_controller *controller);
void	*scany(void *root);
void	display_config(t_nmap_setting *settings);
void    display_report(t_root *root, double scan_time);
void    handle_signal(int sig);
void    *handle_timeout(void *attr);
double  elapse_time(struct timeval *begin, struct timeval *end);

#endif
