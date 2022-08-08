/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:21:16 by adbenoit          #+#    #+#             */
/*   Updated: 2022/08/08 02:13:10 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap.h"

t_list	*get_ip(char *host) {
	t_ip	*content;

	(void)host;
	content = malloc(sizeof(t_ip));
	if (content == NULL)
		exit(EXIT_FAILURE);
	// getaddrinfo(host) => sockaddr_storage
	return (ft_lstnew(content));
}

void    set_ip_from_file(t_opt *opt, char *file)
{
	FILE		*stream;
	int32_t		fd;
	char		*host;
	t_list		*ip;
	uint32_t	i;
	int32_t		ret;
	
	if (file == NULL) {
		exit(EXIT_FAILURE);
	}
	stream = fopen(file, "r");
	if (stream != NULL) {
		fd = fileno(stream);
		i = 0;
		do {
			if (opt->ip_lst == NULL) {
				break ;
			}
			ret = get_next_line(fd, &host);
			if (ret != -1) {
				ip = get_ip(host);
				ft_lstadd_back(&opt->ip_lst, ip);
			}
			++i;
		} while (ret > 0);
		close(fd);
		fclose(stream);
	}
}

void    set_ip_from_arg(t_opt *opt, char *host)
{
	if (host == NULL) {
		exit(EXIT_FAILURE);
	}
	opt->ip_lst = get_ip(host);
}

void    set_ports(t_opt *opt, char *value)
{
	bool	isrange;
	int32_t	i, start, end;

	if (value == NULL) {
		exit(EXIT_FAILURE);
	}
	isrange = false;
	i = 0;
	while (value[i] != 0 && value[i] != '-') {
		++i;
	}
	if (value[i] == '-') {
		isrange = true;
	}
	value[i] = 0;
	start = ft_atoi(value);
	if (isrange) {
		end = ft_atoi(value + i + 1);
	}
	else {
		end = start;
	}
	if (end - start < 0 || end - start > 1024) {
		exit(EXIT_FAILURE);
	}
	for (int32_t i = start; i <= end; i++) {
		opt->ports[i - start] = i;
	}

}
void    set_scan(t_opt *opt, char *value)
{
	char	*scan_list[] = {"SYN", "NULL", "ACK", "FIN", "XMAS", "UDP"};
	char	value_list[] = {S_SYN, S_NULL, S_ACK, S_FIN, S_XMAS, S_UDP};

	if (value == NULL) {
		exit(EXIT_FAILURE);
	}
	for (int32_t i = 0; i < 6; i++) {
		if (ft_strcmp(value, scan_list[i]) == 0) {
			opt->scans = value_list[i];
			return ;
		}
	}
	exit(EXIT_FAILURE);
}

void    set_speedup(t_opt *opt, char *value)
{
	int32_t	nb;

	if (value == NULL) {
		exit(EXIT_FAILURE);
	}
	nb = ft_atoi(value);
	if (nb < 0 || nb > 250) {
		exit(EXIT_FAILURE);
	}
	opt->speedup = (uint8_t)nb;
}
