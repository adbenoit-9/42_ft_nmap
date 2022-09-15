/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmap_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:18:27 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/15 19:14:44 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmap.h"
#include "nmap_mapy_config.h"

# define HEADER_FORMAT "%s\n%s%*s%*s%*s\n%.*s\n"
# define PORT_REPORT_FORMAT "%d%*s%*s%*s\n"
# define BORDER "-------------------------------------------------------------\
------------------------------------------------------------------------------"
# define SPACES "                                                             "
# define PRECISION(len_prec_val, len_prec_zone, val) (int)(len_prec_zone - len_prec_val + ft_strlen(val))
# define HDR_PRECISION(len_prec_val, len_prec_zone, len_val) (int)(len_prec_zone - len_prec_val + len_val)
# define PORT_ZONE_SIZE     10
# define SERV_ZONE_SIZE     30
# define RES_ZONE_SIZE      25
# define CONCL_ZONE_SIZE    35

void	display_config(t_nmap_setting *settings)
{
	char	ip_list[settings->ip_nb * INET6_ADDRSTRLEN + settings->ip_nb];
	char	scan_list[settings->scan_nb * 4 + settings->scan_nb];
	char	*scan_str[] = {"NULL", "SYN", "ACK", "FIN", "XMAS", "UDP"};
	char	scan_value[] = {FLAG_S_NULL, FLAG_S_SYN, FLAG_S_ACK, FLAG_S_FIN,
				FLAG_S_XMAS, FLAG_S_UDP};

	ip_list[0] = 0;
	scan_list[0] = 0;
	for (int i = 0; i < settings->ip_nb; i++) {
		strcat(ip_list, settings->ips[i]);
		strcat(ip_list, " ");
	}
	for (int i = 0; i < settings->scan_nb; i++) {
		for (int j = 0; j < 6; j++) {
			if (settings->scans[i] == scan_value[j]) {
				strcat(scan_list, scan_str[j]);
				break ;
			}
		}
		strcat(scan_list, " ");
	}
	printf("Scan Configurations\nTarget Ip-Address : %s\n\
No of Ports to scan : %d\n\
Scans to be performed : %s\n\
No of threads : %d\nScanning..\n",
		ip_list, settings->port_nb, scan_list, settings->speedup);
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
    
    for (scan_index = 0; scan_index < 6; scan_index++) {
        if (flag_scan == scan_value[scan_index]) {
            break ;
        }
    }
    for (int i = 0; i < 4; i++) {
        char        str[PORT_ZONE_SIZE + SERV_ZONE_SIZE + RES_ZONE_SIZE + 1];
        if (flag_result & status_value[i]) {
            nspaces = ft_strlen(result) > RES_ZONE_SIZE - 11 ? \
                PORT_ZONE_SIZE + SERV_ZONE_SIZE : 0;
            sprintf(str, "\n%.*s%s(%s) ", nspaces, SPACES,
                scan_str[scan_index], status_str[i]);
            ft_strcat(result, &str[nspaces > 0 ? 0 : 1]);
        }
    }
    
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
    int flag_index = ip_index;
    struct servent *service;
    int             ret = 0;
    int             port_len;
    u_int8_t        flag_concl;
    char            result[4096];
    char            conclusion[CONCL_ZONE_SIZE + 1];

    for (int i = 0; ret == 0 && i < root->nd_nb; i++) {
        flag_concl = 0;
        ft_bzero(result, 4096);
        for (int j = 0; ret == 0 && j < root->rd_nb; j++, flag_index++) {
            if (root->blk_flag[flag_index] & status) {
                flag_concl |= root->blk_flag[flag_index];
                str_flag_result(result, root->blk_flag[flag_index], root->rd[j].client.packet_flag);
                if (j == root->rd_nb - 1) {
                    str_flag_conclusion(conclusion, flag_concl);
                    service = getservbyport(root->nd[i].client.port, NULL);
                    port_len = 1;
                    if (root->nd[i].client.port > 10)
                        ++port_len;
                    if (root->nd[i].client.port > 100)
                        ++port_len;
                    if (root->nd[i].client.port > 1000)
                        ++port_len;
                    printf(PORT_REPORT_FORMAT,
                        root->nd[i].client.port,
                        PRECISION(port_len, PORT_ZONE_SIZE, service ? service->s_name : "Unassigned"),
                        service ? service->s_name : "Unassigned",
                        PRECISION(ft_strlen(service ? service->s_name : "Unassigned"), SERV_ZONE_SIZE, result),
                        result,
                        PRECISION(last_line_result_len(result), RES_ZONE_SIZE, conclusion),
                        conclusion);
                }
            }
        }
    }
    return (ret);
}

void    display_report(t_root *root, double scan_time)
{
    printf("\nScan took %f secs\n", scan_time);
    for (int i = 0; i < root->st_nb; i++) {
        printf("IP address: %s\n", root->client.ips[i]);
        
        printf(HEADER_FORMAT, "Open ports:",
            "Port",
            HDR_PRECISION(4, PORT_ZONE_SIZE, 28),
            "Service Name (if applicable)",
            HDR_PRECISION(28, SERV_ZONE_SIZE, 7),
            "Results",
            HDR_PRECISION(7, RES_ZONE_SIZE, 10),
            "Conclusion",
            PORT_ZONE_SIZE + SERV_ZONE_SIZE + RES_ZONE_SIZE + CONCL_ZONE_SIZE,
            BORDER);
        print_ports_report(root, i, PORT_S_OPEN);
        
        printf(HEADER_FORMAT, "Closed/Filtered/Unfiltered ports:",
            "Port",
            HDR_PRECISION(4, PORT_ZONE_SIZE, 28),
            "Service Name (if applicable)",
            HDR_PRECISION(28, SERV_ZONE_SIZE, 7),
            "Results",
            HDR_PRECISION(7, RES_ZONE_SIZE, 10),
            "Conclusion",
            PORT_ZONE_SIZE + SERV_ZONE_SIZE + RES_ZONE_SIZE + CONCL_ZONE_SIZE,
            BORDER);
        print_ports_report(root, i, ~PORT_S_OPEN);
    }
}
