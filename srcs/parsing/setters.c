/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:21:16 by adbenoit          #+#    #+#             */
/*   Updated: 2022/08/07 18:06:44 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap.h"

void    set_ip_from_file(t_param *param, char *value)
{
}

void    set_ip_from_arg(t_param *param, char *value)
{
}

void    set_ports(t_param *param, char *value)
{
	bool	isrange;
	int32_t	i;

	isrange = false;
	while (value[i] && value[i] != '-')
		++i;
	if (value[i] == '-')
	{
		isrange = true;
	}
	value[i] = 0;
	param->ports[0] = atoi(value);
	if (isrange)
	{
		param->ports[1] = atoi(value + i + 1);
	}
	else
	{
		param->ports[1] = param->ports[0];
 	}		

}
void    set_scan(t_param *param, char *value)
{
	int8_t	*scan_list[] = {"SYN", "NULL", "ACK", "FIN", "XMAS", "UDP"};
	int8_t	*value_list[] = {S_SYN, S_NULL, S_ACK, S_FIN, S_XMAS, S_UDP};

	for (int32_t i = 0; i < 6; i++)
	{
		if (strcmp(value, scan_list[i]) == 0)
		{
			param->scan = value_list[i];
			break ;
		}
	}	
}

void    set_speedup(t_param *param, char *value)
{
	param->speedup = atoi(value);
}
