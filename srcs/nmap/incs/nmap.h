/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:37:26 by adbenoit          #+#    #+#             */
/*   Updated: 2022/08/25 18:39:16 by adbenoit         ###   ########.fr       */
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

int	scany(t_nmap_setting *settings, t_root *root);

#endif
