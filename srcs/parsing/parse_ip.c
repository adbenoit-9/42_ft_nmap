/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:57:13 by adbenoit          #+#    #+#             */
/*   Updated: 2022/08/08 16:14:04 by adbenoit         ###   ########.fr       */
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
	if (content == NULL)
		fatal_error(-1, STR_ENOMEM, opt);
		
	ft_memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_flags = 0;
	ret = getaddrinfo(host, NULL, &hints, &res);
	if (ret != 0)
		fatal_error(E_BADHOST, host, 0);
	ft_memcpy(&content->sock, res->ai_addr, sizeof(struct sockaddr_storage));
	freeaddrinfo(res);

	ip = ft_lstnew(content);
	if (ip == NULL)
		fatal_error(-1, STR_ENOMEM, opt);
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
				set_ip(host, opt);
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
	set_ip(host, opt);
}
