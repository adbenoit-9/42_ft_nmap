/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmap_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:28:22 by leon              #+#    #+#             */
/*   Updated: 2022/08/24 11:52:10 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapy.h"
#include <stdio.h>

int					print_all(uint8_t *buf, t_nmap_link *link, t_nmap_app *app, t_nmap_scan *scan)
{
	int			i = 0;

	(void)link;
	(void)app;
	(void)scan;
	fprintf(stderr, "%s:%d buf=%p\n\n", __func__, __LINE__, buf);
	while (i < scan->packet_length)
	{
		if (i % 32 == 0)
		{
			fprintf(stderr, "\n");
		}
		fprintf(stderr, "%02x.",buf[i++]);
	}
	fprintf(stderr, "\n\n");
	return (0);
}

int					print_report(uint8_t *buf, t_nmap_link *link, t_nmap_app *app, t_nmap_scan *scan)
{
	(void)buf;
	(void)link;
	fprintf(stderr, "localhost: port:%d : scan:%d -> result:%d\n",
						app->port, scan->packet_flag, scan->result);
	return (0);
}
