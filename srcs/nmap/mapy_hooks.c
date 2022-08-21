/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapy_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:28:22 by leon              #+#    #+#             */
/*   Updated: 2022/08/21 15:33:07 by leon             ###   ########.fr       */
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
	while (i < MAP_BLCK_SIZE)
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
