/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmap_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:28:22 by leon              #+#    #+#             */
/*   Updated: 2022/09/16 17:41:16 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapy.h"
#include <stdio.h>

int					print_report(uint8_t *buf, t_nmap_link *link, t_nmap_app *app, t_nmap_scan *scan)
{
	(void)buf;
	(void)link;
	fprintf(stderr, "localhost: port:%d : scan:%d -> result:%d\n",
						app->port, scan->packet_flag, scan->result);
	return (0);
}
