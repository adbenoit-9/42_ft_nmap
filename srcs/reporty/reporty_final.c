/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reporty_final.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:18:27 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/20 15:27:57 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reporty.h"
					
static void add_flag_result(char *result, uint8_t flag_result, uint8_t flag_scan)
{
	int         nspaces, len;
	char        str[PORT_ZONE_SIZE + SERV_ZONE_SIZE + RES_ZONE_SIZE + 20];
	char        status[20];
	char        scan[5];

	scan[0] = 0;
	scan_to_str(scan, flag_scan);
	status_to_str(status, flag_result, "|");
	len = ft_strlen(result);
	nspaces = len > RES_ZONE_SIZE - len ? \
		PORT_ZONE_SIZE + SERV_ZONE_SIZE : 0;
	sprintf(str, "\n%.*s%s(%s) ", nspaces, SPACES, scan, status);
	ft_strcat(result, &str[nspaces > 0 ? 0 : 1]);
}

static uint8_t get_conclusion(uint8_t flag_concl)
{
	uint8_t	concl = 0;
	
	if (flag_concl & PORT_S_CLOSED)
		concl = PORT_S_CLOSED;
	else if (flag_concl & PORT_S_OPEN)
		concl = PORT_S_OPEN;
	else if (flag_concl & PORT_S_UNFILTERED)
		concl = PORT_S_UNFILTERED;
	else if (flag_concl & PORT_S_FILTERED)
		concl = PORT_S_FILTERED;
	return (concl);
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
			flag_concl |= root->blk_flag[flag_index];
			add_flag_result(result, root->blk_flag[flag_index], root->rd[j].client.packet_flag);
		}
		if (flag_concl & root->client.options) {
			flag_concl = get_conclusion(flag_concl);
			status_to_str(conclusion, flag_concl, 0);
			if (flag_concl & status) {
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
	return (ret);
}

static void	print_header(char *status)
{
	printf(HEADER_FORMAT,
		status,
		"Port",
		HDR_PRECISION(4, PORT_ZONE_SIZE, 28),
		"Service Name (if applicable)",
		HDR_PRECISION(28, SERV_ZONE_SIZE, 7),
		"Results",
		HDR_PRECISION(7, RES_ZONE_SIZE, 10),
		"Conclusion",
		PORT_ZONE_SIZE + SERV_ZONE_SIZE + RES_ZONE_SIZE + CONCL_ZONE_SIZE,
		BORDER1);
}

void    report_final(t_root *root, double scan_time)
{
	char	ipaddr[INET6_ADDRSTRLEN];
	char	host_name[100];
	char	status[29];
	
	printf("\nScan took %f secs\n", scan_time);
	for (int i = 0; i < root->st_nb; i++) {
		dns_resolution(&root->st->client.sock, root->client.ips[i], host_name);
		dns(&root->st->client.sock, root->client.ips[i], ipaddr);
		printf("IP address: %s (%s)\n", host_name, ipaddr);
		if (root->client.options & PORT_S_OPEN) {
			print_header("Open");
			print_ports_report(root, i, PORT_S_OPEN);
		}
		if (root->client.options & (PORT_S_CLOSED | PORT_S_FILTERED | PORT_S_UNFILTERED)) {
			status[0] = '\n';
			status_to_str(&status[1], root->client.options & ~PORT_S_OPEN, "/");
			print_header(status);
			print_ports_report(root, i, ~PORT_S_OPEN);
		}
	}
}
