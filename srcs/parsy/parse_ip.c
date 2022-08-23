/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:57:13 by adbenoit          #+#    #+#             */
/*   Updated: 2022/08/23 11:03:29 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap_parsing.h"

static void	set_ip(char *host, t_nmap_setting *settings)
{
	if (settings->ip_nb < IP_LIMIT) {
		ft_strcpy(settings->ips[settings->ip_nb], host);
		++settings->ip_nb;
	}
}

void    set_ip_from_file(t_nmap_setting *settings, char *file)
{
	FILE		*stream;
	int32_t		fd;
	char		*host;
	int32_t		ret;
	
	if (file == NULL) {
		fatal_error(E_NOARG, "--file");
	}
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
		fatal_error(E_BADFILE, file);
	}
}

void    set_ip_from_arg(t_nmap_setting *settings, char *host)
{
	if (host == NULL) {
		fatal_error(E_NOARG, "--ip");
	}
	set_ip(host, settings);
}
