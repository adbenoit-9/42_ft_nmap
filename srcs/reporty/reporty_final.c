/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reporty_final.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:18:27 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/20 09:27:51 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reporty.h"

static char *ft_getservbyport(int port, char *protocol)
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

static void str_flag_result(char *result, uint8_t flag_result, uint8_t flag_scan)
{
	static char	*status_str[] = {"Open", "Closed", "Filtered", "Unfiltered"};
	static char	status_value[] = {PORT_S_OPEN, PORT_S_CLOSED, \
									PORT_S_FILTERED, PORT_S_UNFILTERED};
	static char	*scan_str[] = {"NULL", "SYN", "ACK", "FIN", "XMAS", "UDP", NULL};
	static char	scan_value[] = {FLAG_S_NULL, FLAG_S_SYN, FLAG_S_ACK, FLAG_S_FIN,
				FLAG_S_XMAS, FLAG_S_UDP};
	int         nspaces, scan_index;
	char        str[PORT_ZONE_SIZE + SERV_ZONE_SIZE + RES_ZONE_SIZE + 20];
	char        status[20];
	
	for (scan_index = 0; scan_index < 6; scan_index++) {
		if (flag_scan == scan_value[scan_index]) {
			break ;
		}
	}
	status[0] = 0;
	for (int i = 0; i < 4; i++) {
		if (flag_result & status_value[i]) {
			if (status[0]) {
				ft_strcat(status, "|");
			}
			ft_strcat(status, status_str[i]);
		}
	}
	nspaces = ft_strlen(result) > RES_ZONE_SIZE - 11 ? \
		PORT_ZONE_SIZE + SERV_ZONE_SIZE : 0;
	sprintf(str, "\n%.*s%s(%s) ", nspaces, SPACES,
		scan_str[scan_index], status);
	ft_strcat(result, &str[nspaces > 0 ? 0 : 1]);
	
}

static void str_flag_conclusion(char *dest, uint8_t flag_concl)
{
	if (flag_concl & PORT_S_CLOSED)
		ft_strcpy(dest, "Closed");
	else if (flag_concl & PORT_S_OPEN)
		ft_strcpy(dest, "Open");
	else if (flag_concl & PORT_S_UNFILTERED)
		ft_strcpy(dest, "Unfiltered");
	else if (flag_concl & PORT_S_FILTERED)
		ft_strcpy(dest, "Filtered");
}

static int  last_line_result_len(char *result)
{
	int i = 0;
	int len = 0;
	
	while (result[i]) {
		++i;
		++len;
		if (result[i] == '\n') {
			i += PORT_ZONE_SIZE + SERV_ZONE_SIZE + 1;
			len = 0;
		}
	}
	return (len);
}

static int print_ports_report(t_root *root, int ip_index, uint8_t status)
{
	int			flag_index = ip_index;
	char		*service;
	int			ret = REPORTY_OK;
	int			port_len;
	u_int8_t	flag_concl;
	char		result[4096];
	char		conclusion[CONCL_ZONE_SIZE + 1];

	for (int i = 0; ret == REPORTY_OK && i < root->nd_nb; i++) {
		flag_concl = 0;
		ft_bzero(result, 4096);
		for (int j = 0; ret == REPORTY_OK && j < root->rd_nb; j++, flag_index++) {
			if (root->blk_flag[flag_index] & status &&
					(status == PORT_S_OPEN || !(root->blk_flag[flag_index] & ~status))) {
				flag_concl |= root->blk_flag[flag_index];
				str_flag_result(result, root->blk_flag[flag_index], root->rd[j].client.packet_flag);
				if (j == root->rd_nb - 1) {
					str_flag_conclusion(conclusion, flag_concl);
					service = ft_getservbyport(root->nd[i].client.port, NULL);
					port_len = num_len(root->nd[i].client.port);
					printf(PORT_REPORT_FORMAT,
						root->nd[i].client.port,
						PRECISION(port_len, PORT_ZONE_SIZE, service ? service : "Unassigned"),
						service ? service : "Unassigned",
						PRECISION(ft_strlen(service ? service : "Unassigned"), SERV_ZONE_SIZE, result),
						result,
						PRECISION(last_line_result_len(result), RES_ZONE_SIZE, conclusion),
						conclusion);
				}
			}
		}
	}
	return (ret);
}

void    report_final(t_root *root, double scan_time)
{
	printf("\nScan took %f secs\n", scan_time);
	for (int i = 0; i < root->st_nb; i++) {
		printf("IP address: %s\n", root->client.ips[i]);
		
		printf(HEADER_FORMAT,
			"Open ports:",
			"Port",
			HDR_PRECISION(4, PORT_ZONE_SIZE, 28),
			"Service Name (if applicable)",
			HDR_PRECISION(28, SERV_ZONE_SIZE, 7),
			"Results",
			HDR_PRECISION(7, RES_ZONE_SIZE, 10),
			"Conclusion",
			PORT_ZONE_SIZE + SERV_ZONE_SIZE + RES_ZONE_SIZE + CONCL_ZONE_SIZE,
			BORDER1);
		print_ports_report(root, i, PORT_S_OPEN);
		
		printf(HEADER_FORMAT,
			"\nClosed/Filtered/Unfiltered ports:",
			"Port",
			HDR_PRECISION(4, PORT_ZONE_SIZE, 28),
			"Service Name (if applicable)",
			HDR_PRECISION(28, SERV_ZONE_SIZE, 7),
			"Results",
			HDR_PRECISION(7, RES_ZONE_SIZE, 10),
			"Conclusion",
			PORT_ZONE_SIZE + SERV_ZONE_SIZE + RES_ZONE_SIZE + CONCL_ZONE_SIZE,
			BORDER1);
		print_ports_report(root, i, ~PORT_S_OPEN);
	}
}
