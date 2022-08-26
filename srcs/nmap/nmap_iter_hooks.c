/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmap_iter_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 23:04:51 by leon              #+#    #+#             */
/*   Updated: 2022/08/24 11:51:57 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmap_structs.h"

#include "proty.h"

#define NMAP_OK			0
#define NMAP_ERROR		-1

/* ND : t_func_iter_nd */
int					iter_set_port(t_nmap_setting *root, t_nmap_app *app, uint32_t index)
{
	app->port = root->ports[index];
	return (NMAP_OK);
}

int					iter_set_tcpflag(t_nmap_setting *root, t_nmap_scan *scan, uint32_t index)
{
	scan->tcpflag = root->scans[index];
	return (NMAP_OK);
}
