/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:57:13 by adbenoit          #+#    #+#             */
/*   Updated: 2022/08/08 16:53:53 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap.h"

static void	set_ip(char *host, t_opt *opt) {
	t_ip			*content;
	t_list			*ip;
	struct addrinfo	hints;
	struct addrinfo	*res;
	int				ret;

	content = ft_calloc(1, sizeof(t_ip));
	if (content == NULL) {
		fatal_error(-1, STR_ENOMEM, opt);
	}
		
	ft_memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_flags = 0;
	ret = getaddrinfo(host, NULL, &hints, &res);
	if (ret != 0)
		fatal_error(E_BADHOST, host, opt);
	ft_memcpy(&content->sock, res->ai_addr, sizeof(struct sockaddr_storage));
	freeaddrinfo(res);

	ip = ft_lstnew(content);
	if (ip == NULL) {
		fatal_error(-1, STR_ENOMEM, opt);
	}
	if (opt->ip_lst == NULL) {
		opt->ip_lst = ip;
	}
	else {
		ft_lstadd_back(&opt->ip_lst, ip);
	}
}

void    set_ip_from_file(t_opt *opt, char *file)
{
	FILE		*stream;
	int32_t		fd;
	char		*host;
	int32_t		ret;
	
	if (file == NULL) {
		fatal_error(E_NOARG, "--file", opt);
	}
	stream = fopen(file, "r");
	if (stream != NULL) {
		fd = fileno(stream);
		do {
			ret = get_next_line(fd, &host);
			if (ret > 0) {
				set_ip(host, opt);
			}
		} while (ret > 0);
		close(fd);
		fclose(stream);
	}
	else {
		fatal_error(E_BADFILE, file, opt);
	}
}

void    set_ip_from_arg(t_opt *opt, char *host)
{
	if (host == NULL) {
		fatal_error(E_NOARG, "--ip", opt);
	}
	set_ip(host, opt);
}
