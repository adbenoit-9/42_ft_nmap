/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsy_ip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:57:13 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/21 11:04:51 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsy.h"

static void	set_ip(char *host, t_nmap_setting *settings)
{
	if (settings->ip_nb < IP_LIMIT) {
		settings->ips[settings->ip_nb] = host;
	}
	++settings->ip_nb;
}

int    set_ip_from_file(t_nmap_setting *settings, char *file)
{
	FILE		*stream;
	int32_t		fd;
	char		*host;
	int			ret = PARSY_OK;
	
	if (file == NULL) {
		ret = print_error(E_NOARG, "--file");
	}
	else {
		stream = fopen(file, "r");
		if (stream != NULL) {
			fd = fileno(stream);
			do {
				ret = get_next_line(fd, &host);
				if (ret > 0) {
					set_ip(host, settings);
				}
			} while (ret > 0);
			close(fd);
			fclose(stream);
		}
		else {
			ret = print_error(E_BADFILE, file);
		}
	}
	return (ret);
}

int    set_ip_from_arg(t_nmap_setting *settings, char *host)
{
	int ret = PARSY_OK;
	
	if (host == NULL) {
		ret = print_error(E_NOARG, "--ip");
	}
	else {
		set_ip(ft_strdup(host), settings);
	}
	return (ret);
}
