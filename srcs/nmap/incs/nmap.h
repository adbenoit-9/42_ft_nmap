/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:37:26 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/15 15:20:54 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NMAP_H
# define NMAP_H

# include <stdint.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <pcap/pcap.h>
# include <pthread.h>
# include "mapy.h"
# include "nmap_hooks.h"
# include "ft_nmap_parsing.h"
# include "analysy.h"

int	    scany(t_nmap_setting *settings, t_root *root);
void	display_config(t_nmap_setting *settings);
void    display_report(t_root *root, double scan_time);
void    handle_signal(int sig);

#endif
