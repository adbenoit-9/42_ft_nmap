/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:38:11 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/14 13:27:10 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmap.h"

void	dump_config(uint8_t *buf, t_nmap_setting *settings)
{

	fprintf(stderr, "pcap_version=%s\n", pcap_lib_version());
	fprintf(stderr, "%s:%d configsize=%lx\n", __func__, __LINE__, sizeof(t_root));
	fprintf(stderr, "%s:%d bufferptr=%p\n", __func__, __LINE__, buf);
	fprintf(stderr, "%s:%d mapptr=%p\n", __func__, __LINE__, &buf[sizeof(t_root)]);
	fprintf(stderr, "%s:%d limit_buffer=%p\n", __func__, __LINE__, &buf[SIZE]);
	fprintf(stderr, "ft_nmapconfig:speedup = %d\n", settings->speedup);
	int i = 0;
	fprintf(stderr, "ft_nmapconfig:port = %x", settings->ports[i++]);
	while (i < PORT_LIMIT)
	{
		fprintf(stderr, ":%x", settings->ports[i++]);
	}
	fprintf(stderr, "\n");
	i = 0;
	fprintf(stderr, "ft_nmapconfig:scans = %x", settings->scans[i++]);
	while (i < SCAN_LIMIT)
	{
		fprintf(stderr, ":%x", settings->scans[i++]);
	}
	fprintf(stderr, "\n");
	fprintf(stderr, "ip_nb = %d\n", settings->ip_nb);
	fprintf(stderr, "port_nb = %d\n", settings->port_nb);
	fprintf(stderr, "scan_nb = %d\n", settings->scan_nb);

}

int main(int ac, char **av)
{
	int32_t 		r		= 0;
	uint8_t			*buf;
	t_root			*root;
	t_nmap_setting	*settings;
	
	buf = (uint8_t*)malloc(SIZE);
	if (buf == NULL) {
		r = -1;
	}
	if (r == 0) {
		root = (t_root*)buf;
		root->map = &buf[sizeof(t_root)];
		settings = &root->client;
		/* Parsing */
		r = parser(ac, av, settings);
		if (r == PARSY_OK) {
			dump_config(buf, settings);
			/* Update size of tree params */
			((t_root*)buf)->st_nb = settings->ip_nb;
			((t_root*)buf)->nd_nb = settings->port_nb;
			((t_root*)buf)->rd_nb = settings->scan_nb;
			/* Fill parameters in tree */
			if (set_iter_st(root, set_sockaddr))
				return (-1);
			if (set_iter_nd(root, iter_set_port))
				return (-1);
			if (set_iter_rd(root, iter_set_tcpflag))
				return (-1);
			//exey_ctrl(root, nmap_init_exey);
			scany(settings, root);
			//exey_ctrl(root, nmap_clean_exey);
		}
		else if (r == PARSY_STOP)
			r = PARSY_OK;
	}
	return (r);
}

