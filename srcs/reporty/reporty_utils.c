/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reporty_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:53:30 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/20 11:40:08 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reporty.h"

int num_len(int num)
{
	int len = 1;

	while (num >= 10) {
		num /= 10;
		++len;
	}
	return len;
}

int	dns(void *sockaddr, char *ipstr, char *dest)
{
	int	sf = ((struct sockaddr_storage *)sockaddr)->ss_family;
	int	ret = REPORTY_OK;
	
	if (sf == AF_INET6) {
		ret = inet_ntop(sf, &((struct sockaddr_in6 *)sockaddr)->sin6_addr,
			dest, INET6_ADDRSTRLEN);
	}
	else {
		ret = inet_ntop(sf, &((struct sockaddr_in *)sockaddr)->sin_addr,
			dest, INET_ADDRSTRLEN);
	}
	if (ret != REPORTY_OK) {
		ft_strcpy(dest, ipstr);
		perror("inet_ntop");
		ret = REPORTY_ERROR;
	}
	return (ret);
}

void    dns_resolution(void *sockaddr, char *ipstr, char *dest)
{
	struct hostent	*host;
	int				len = INET_ADDRSTRLEN;
	int				sf = ((struct sockaddr_storage *)sockaddr)->ss_family;

	if (sf == AF_INET6) {
		len = INET6_ADDRSTRLEN;
	}
	host = gethostbyaddr(sockaddr, len, sf);
	if (host && host->h_name) {
		ft_strcpy(dest, host->h_name);
	}
	else if (ft_strcmp(ipstr, "::1") == 0 ||
			ft_strcmp(ipstr, "127.0.0.1") == 0) {
		ft_strcpy(dest, "localhost");
	}
	else {
		ft_strcpy(dest, ipstr);
	}
}
