/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:21:16 by adbenoit          #+#    #+#             */
/*   Updated: 2022/08/07 19:24:11 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap.h"

void    set_ip_from_file(t_param *param, char *file)
{
	FILE	*stream;
	int32_t	fd;
	char	*ip;
	int32_t	i;
	int32_t	ret;
	
	stream = fopen(file, "r");
	if (stream)
	{
		fd = fileno(stream);
		i = 0;
		do
		{
			param->ip = (char **)ft_realloc((void *)param->ip, (i + 2) * sizeof(char *));
			if (!param->ip)
				break ;
			ret = get_next_line(fd, &ip);
			param->ip[i] = ip;
			++i;
		} while (ret > 0);
		if (param->ip)
			param->ip[i] = NULL;
		close(fd);
		fclose(stream);
	}
	perror(file);
}

void    set_ip_from_arg(t_param *param, char *ip)
{
	param->ip = (char **)malloc(sizeof(char *) * 2);
	if (param->ip)
	{
		param->ip[0] = ft_strdup(ip);
		param->ip[1] = NULL;
	}
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
	param->ports[0] = ft_atoi(value);
	if (isrange)
	{
		param->ports[1] = ft_atoi(value + i + 1);
	}
	else
	{
		param->ports[1] = param->ports[0];
 	}		

}
void    set_scan(t_param *param, char *value)
{
	char	*scan_list[] = {"SYN", "NULL", "ACK", "FIN", "XMAS", "UDP"};
	int8_t	value_list[] = {S_SYN, S_NULL, S_ACK, S_FIN, S_XMAS, S_UDP};

	for (int32_t i = 0; i < 6; i++)
	{
		if (ft_strcmp(value, scan_list[i]) == 0)
		{
			param->scan = value_list[i];
			break ;
		}
	}	
}

void    set_speedup(t_param *param, char *value)
{
	param->speedup = ft_atoi(value);
}
