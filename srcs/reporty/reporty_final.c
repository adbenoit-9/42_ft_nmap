/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reporty_final.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:18:27 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/21 17:10:05 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reporty.h"
					
static void add_flag_result(char *result, uint8_t flag_result, uint8_t flag_scan)
{
	int         nspaces, len;
	char        str[PORT_ZONE_SIZE + SERV_ZONE_SIZE + RES_ZONE_SIZE + 32];
	char        status[32];
	char        scan[5];

	scan[0] = 0;
	scan_to_str(scan, flag_scan);
	status_to_str(status, flag_result, "|");
	len = ft_strlen(result);
	nspaces = len > RES_ZONE_SIZE - len ? \
		PORT_ZONE_SIZE + SERV_ZONE_SIZE : 0;
	snprintf(str, PORT_ZONE_SIZE + SERV_ZONE_SIZE + RES_ZONE_SIZE + 32,
		"\n%.*s%s(%s) ", nspaces, SPACES, scan, status);
	ft_strcat(result, &str[nspaces > 0 ? 0 : 1]);
}

static uint8_t get_conclusion(uint8_t concl_flag)
{
	uint8_t	concl = concl_flag;

	if (concl_flag & PORT_S_UNFILTERED && concl_flag & PORT_S_FILTERED) {
		concl = concl_flag & ~PORT_S_UNFILTERED;
	}
	if (concl_flag & PORT_S_CLOSED && concl_flag & PORT_S_OPEN) {
		concl = concl_flag & ~PORT_S_CLOSED;
	}
	return (concl);
}

static uint8_t set_conclusion(uint8_t old_flag, uint8_t new_flag)
{
	uint8_t	concl = 0;
	
	if (old_flag == 0) {
		concl = new_flag;
	}
	else if (new_flag == PORT_S_OPEN || old_flag == PORT_S_OPEN) {
		concl = PORT_S_OPEN;
	}
	else if (new_flag == PORT_S_CLOSED || old_flag == PORT_S_CLOSED) {
		concl = PORT_S_CLOSED;
	}
	else {
		concl = new_flag | old_flag;
	}
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

static int print_ports_report(t_root *root, int index, uint8_t status)
{
	char		*service;
	int			ret = REPORTY_OK;
	int			port_len, not_shown;
	u_int8_t	flag_concl;
	char		result[4096];
	char		conclusion[CONCL_ZONE_SIZE + 1];

	for (int i = 0; ret == REPORTY_OK && i < root->nd_nb; i++) {
		flag_concl = 0;
		ft_bzero(result, 4096);
		for (int j = 0; ret == REPORTY_OK && j < root->rd_nb; j++, index++) {
			flag_concl = set_conclusion(flag_concl, root->blk_flag[index]);
			add_flag_result(result, root->blk_flag[index], root->rd[j].client.packet_flag);
		}
		if (flag_concl & root->client.options) {
			flag_concl = get_conclusion(flag_concl);
			status_to_str(conclusion, flag_concl, "|");
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
		else {
			++not_shown;
		}
	}
	return (not_shown);
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

static void	print_not_shown(t_root *root, int index)
{
	u_int8_t	flag_concl;
	char		result[400];
	char		status_info[96];
	char		status[16];
	int			ret = REPORTY_OK;
	int			nb_res[SCAN_LIMIT] = {0};

	ft_bzero(result, 400);
	for (int i = 0; ret == REPORTY_OK && i < root->nd_nb; i++) {
		flag_concl = 0;
		for (int j = 0; ret == REPORTY_OK && j < root->rd_nb; j++, index++) {
			flag_concl = set_conclusion(flag_concl, root->blk_flag[index]);
		}
		flag_concl = get_conclusion(flag_concl);
		if (!(flag_concl & root->client.options)) {
			++nb_res[flag_concl / 2 - 1];
		}
	}
	for (int i = 0; i < SCAN_LIMIT; i++) {
		if (nb_res[i] > 0) {
			ft_bzero(status_info, 96);
			ft_bzero(status, 16);
			status_to_str(status, (i + 1) * 2, "|");
			sprintf(status_info, "\n%.*s%d %s ports", result[0] ? 11 : 0, SPACES, nb_res[i], status);
			if (result[0]) {
				ft_strcat(result, status_info);
			}
			else {
				ft_strcat(result, &status_info[1]);
			}
		}
	}
	if (result[0]) {
		printf("Not shown: %s\n", result);
	}
}

static void	print_address_info(void *sock, char *ip)
{
	char	ipaddr[INET6_ADDRSTRLEN];
	char	rdns[100];
	
	ft_bzero(ipaddr, INET6_ADDRSTRLEN);
	ft_bzero(rdns, 100);
	dns(sock, ip, ipaddr);
	if (ft_strcmp(ip, "127.0.0.1") == 0) {
		printf("\nIP address: %s (%s)\n", "localhost", ipaddr);
	}
	else if (ft_strcmp(ip, "::1") == 0) {
		printf("\nIP address: %s (%s)\n", "ip6-localhost", ipaddr);
	}
	else {
		printf("\nIP address: %s (%s)\n", ip, ipaddr);
	}
	if (dns_resolution(sock, rdns)) {
		printf("rDNS record for %s: %s\n", ipaddr, rdns);
	}
}

void    report_final(t_root *root, double scan_time)
{
	char	status[29];

	printf("\nScan took %f secs\n", scan_time);
	for (int i = 0; i < root->st_nb; i++) {
		ft_bzero(status, 29);
		print_address_info(&root->st[i].client.sock, root->client.ips[i]);
		if (root->client.options & PORT_S_OPEN) {
			print_header("Open");
			print_ports_report(root, i * root->nd_nb * root->rd_nb, PORT_S_OPEN);
		}
		if (root->client.options & (PORT_S_CLOSED | PORT_S_FILTERED | PORT_S_UNFILTERED)) {
			status[0] = '\n';
			status_to_str(&status[0], root->client.options & ~PORT_S_OPEN, "/");
			print_header(status);
			print_ports_report(root, i * root->nd_nb * root->rd_nb, ~PORT_S_OPEN);
		}
		print_not_shown(root, i * root->nd_nb * root->rd_nb);
	}
}
