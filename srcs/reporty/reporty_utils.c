/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reporty_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:53:30 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/21 09:47:51 by adbenoit         ###   ########.fr       */
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
		if (!inet_ntop(sf, &((struct sockaddr_in6 *)sockaddr)->sin6_addr,
				dest, INET6_ADDRSTRLEN)) {
			ret = REPORTY_ERROR;
		}
	}
	else if (!inet_ntop(sf, &((struct sockaddr_in *)sockaddr)->sin_addr,
			dest, INET_ADDRSTRLEN)) {
		ret = REPORTY_ERROR;
	}
	if (ret != REPORTY_OK) {
		ft_strcpy(dest, ipstr);
		perror("inet_ntop");
	}
	return (ret);
}

char    *dns_resolution(void *sockaddr, char *dest)
{
	struct hostent	*host;
	int				sf = ((struct sockaddr_storage *)sockaddr)->ss_family;
	char			*rdns = NULL;

	if (sf == AF_INET6) {
		host = gethostbyaddr(&((struct sockaddr_in6 *)sockaddr)->sin6_addr,
			INET6_ADDRSTRLEN, sf);
	}
	else {
		host = gethostbyaddr(&((struct sockaddr_in *)sockaddr)->sin_addr,
			INET_ADDRSTRLEN, sf);
	}
	if (host && host->h_name && host->h_name[0]) {
		ft_strcpy(dest, host->h_name);
		rdns = dest;
	}
	return (rdns);
}

void	status_to_str(char *dest, uint8_t status, char *delim)
{
	static char	*status_str[] = {"Open", "Closed", "Filtered", "Unfiltered"};
	static char	status_value[] = {PORT_S_OPEN, PORT_S_CLOSED, \
									PORT_S_FILTERED, PORT_S_UNFILTERED};
									
	dest[0] = 0;
	for (int i = 0; i < 4; i++) {
		if (status & status_value[i]) {
			if (dest[0]) {
				ft_strcat(dest, delim);
			}
			ft_strcat(dest, status_str[i]);
		}
	}
}

void	scan_to_str(char *dest, uint8_t scan)
{
	static char	*scan_str[] = {"NULL", "SYN", "ACK", "FIN", "XMAS", "UDP"};
	static char	scan_value[] = {FLAG_S_NULL, FLAG_S_SYN, FLAG_S_ACK,
									FLAG_S_FIN, FLAG_S_XMAS, FLAG_S_UDP};
									
	for (int i = 0; i < SCAN_LIMIT; i++) {
		if (scan == scan_value[i]) {
			ft_strcat(dest, scan_str[i]);
			break ;
		}
	}
}

char	*ft_getservbyport(int port, char *protocol)
{
	static int  tcp_port[] = TCP_PORTS;
	static int  udp_port[] = UDP_PORTS;
	static char *tcp_serv[] = TCP_SERVICES;
	static char *udp_serv[] = UDP_SERVICES;
	char *service = NULL;

	if (!protocol || ft_strcmp(protocol, "TCP")) {
		for (int i = 0; tcp_serv[i]; i++) {
			if (tcp_port[i] == port) {
				service = tcp_serv[i];
				break ;
			}
		}
	}
	if (!service && (!protocol || ft_strcmp(protocol, "UDP"))) {
		for (int i = 0; tcp_serv[i]; i++) {
			if (udp_port[i] == port) {
				service = udp_serv[i];
				break ;
			}
		}
	}
	return (service);
}
