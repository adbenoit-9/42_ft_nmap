/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:21:16 by adbenoit          #+#    #+#             */
/*   Updated: 2022/08/08 12:02:58 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap.h"

bool	ft_isnumber(char *str)
{
	for (int64_t i = 0; str[i]; i++) {
		if (ft_isdigit(str[i]) == false) {
			return (false);
		}
	}
	return (true);
}

t_list	*get_ip(char *host, t_opt *opt) {
	t_ip	*content;

	(void)host;
	content = malloc(sizeof(t_ip));
	if (content == NULL)
		fatal_error(-1, STR_ENOMEM, opt);
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
		fatal_error(E_NOARG, "--file", opt);
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
				ip = get_ip(host, opt);
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
		fatal_error(E_NOARG, "--ip", opt);
	}
	opt->ip_lst = get_ip(host, opt);
}

void    set_ports(t_opt *opt, char *value)
{
	bool	isrange;
	int32_t	i, start, end;

	if (value == NULL) {
		fatal_error(E_NOARG, "--ports", opt);
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
	if (ft_isnumber(value) == false ||
			ft_isnumber(value + i + 1) == false) {
		if (isrange == true) {
			value[i] = '-';
		}
		fatal_error(E_BADPORT, value, opt);
	}
	else if (end - start < 0 || end - start > 1024) {
		fatal_error(E_BADRANGE, value, opt);
	}
	else if (start < 0 || start > 65536) {
		fatal_error(E_BADPORT, value, opt);
	}
	else if (end < 0 || end > 65536) {
		fatal_error(E_BADPORT, value + i + 1, opt);
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
		fatal_error(E_NOARG, "--scan", opt);
	}
	for (int32_t i = 0; i < 6; i++) {
		if (ft_strcmp(value, scan_list[i]) == 0) {
			opt->scans = value_list[i];
			return ;
		}
	}
	fatal_error(E_BADSCAN, value, opt);
}

void    set_speedup(t_opt *opt, char *value)
{
	int32_t	nb;

	if (value == NULL) {
		fatal_error(E_NOARG, "--speedup", opt);
	}
	nb = ft_atoi(value);
	if (ft_isnumber(value) == false || nb < 0 || nb > 250) {
		fatal_error(E_BADSPEEDUP, value, opt);
	}
	opt->speedup = (uint8_t)nb;
}
