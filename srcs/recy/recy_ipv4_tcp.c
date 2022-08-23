/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recy_ipv4_tcp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 21:06:41 by leon              #+#    #+#             */
/*   Updated: 2022/08/23 11:29:00 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO LMA 
// We can avoid polling
//			- using select
//			- using pcap

#include "recy.h"
#include "proty.h"
#include "libft.h"
#include "nmap_mapy_config.h"
#include <stdio.h>
#include <string.h>


void				ft_pcap_handler(u_char *user, const struct pcap_pkthdr *h, const u_char *bytes)
{
	( void)user;
	uint32_t		i;
	i = 0;
	fprintf(stderr, "%s:%d h->len= %d\n", __func__, __LINE__, h->len);
	while (i < h->len)
	{
		fprintf(stderr, "%02x:", bytes[i]);
		i++;
	}
	fprintf(stderr, "\n");
}

//int				pcap_test(t_nmap_setting *settings)
//{
//	(void)settings;
//	pcap_t *pcap;
//	char	err[PCAP_ERRBUF_SIZE];
//	struct bpf_program				program;
//	pcap_if_t			*alldevs = NULL;
//	uint8_t				buf[512];
//	int r;
//
//	r = pcap_compile(pcap, &program, "port 42", 0, PCAP_NETMASK_UNKNOWN);
//	if (r == PCAP_ERROR)
//	{
//		pcap_perror(pcap, "compile:");
//		return -1;
//	}
//	r = pcap_setfilter(pcap, &program);
//	if (r == PCAP_ERROR)
//	{
//		pcap_perror(pcap, "setfilter:");
//		return -1;
//		//fprintf(stderr, "err={%s}", err);
//	}
//	//const uint8_t 	*res;
//	//uint32_t i = 0;
//	//while (1)
//	//{
//	//	i = 1;
//	//	res = pcap_next(pcap, &header);
//	//	fprintf(stderr, "Packet recv:%02x", res[0]);
//	//	while (i < header.len)
//	//	{
//	//		fprintf(stderr, ":%02x", res[i]);
//	//		++i;
//	//	}
//	//	fprintf(stderr, "\n");
//	//}
//	fprintf(stderr, "%s:%d\n", __func__, __LINE__);
//	r = pcap_dispatch(pcap, 250, ft_pcap_handler, buf);
//	return (r);
//}

static char pre_built_filter_icmp[] = "icmp[icmptype] == icmp-unreach";
static char pre_built_filter_rst[] = "(tcp[tcpflags] & tcp-rst) == tcp-rst";
static char pre_built_filter_synack[] = "(tcp[tcpflags] & (tcp-syn | tcp-ack)) == (tcp-syn | tcp-ack)";

int 				recv_ipv4_tcp(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec)
{
	int			r = RECY_OK;
	uint32_t	i = 0;
	char		filter[256] = {0};
	struct		bpf_program		bpf = {0};

	if (!buf || !conf_st || !conf_nd || !conf_exec)
	{
		r = RECY_ERROR;
	}
	else
	{
		(void)pre_built_filter_icmp;
		(void)pre_built_filter_rst;
		(void)pre_built_filter_synack;
		/* Precise src addr */
		memcpy(filter, "src host ", 9);
		i += 9;
		memcpy(&filter[i], ((t_nmap_link*)conf_st)->host, strlen(((t_nmap_link*)conf_st)->host));
		i += strlen(((t_nmap_link*)conf_st)->host);
		memcpy(&filter[i], " and ", 5);
		i += 5;
		filter[i++] = '(';
		/* ICMP unreachable error */
		memcpy(&filter[i], pre_built_filter_icmp, sizeof(pre_built_filter_icmp));
		i += sizeof(pre_built_filter_icmp) - 1;
		memcpy(&filter[i], " or ", 4);
		i += 4;
		filter[i++] = '(';
		/* Precise src port */
		memcpy(&filter[i], "src port ", 9);
		i += 9;
		char		*str_port = ft_itoa(((t_nmap_app*)conf_nd)->port);
		memcpy(&filter[i], str_port, ft_strlen(str_port));
		i += strlen(str_port);
		memcpy(&filter[i], " and ", 5);
		i += 5;
		filter[i++] = '(';
		/* TCP RST */
		memcpy(&filter[i], pre_built_filter_rst, sizeof(pre_built_filter_rst));
		i += sizeof(pre_built_filter_rst) - 1;
		/* TCP SYN/ACK */
		if (((t_nmap_scan*)conf_exec)->tcpflag == FLAG_S_SYN)
		{
			memcpy(&filter[i], " or ", 4);
			i += 4;
			memcpy(&filter[i], pre_built_filter_synack, sizeof(pre_built_filter_synack));
			i += sizeof(pre_built_filter_synack) - 1;
		}
		filter[i++] = ')';
		filter[i++] = ')';
		filter[i++] = ')';
		fprintf(stderr, "filter = {%s}\n", filter);
	}
	r = pcap_compile(((t_nmap_link*)conf_st)->pcap_handler, &bpf, filter, 0, PCAP_NETMASK_UNKNOWN);
	if (r == 0)
	{
		r = pcap_setfilter(((t_nmap_link*)conf_st)->pcap_handler, &bpf);
	}
	if (r == 0)
	{
		r = pcap_dispatch(((t_nmap_link*)conf_st)->pcap_handler, 6, ft_pcap_handler, buf);
	}
	if (r != 0)
	{
		pcap_perror(((t_nmap_link*)conf_st)->pcap_handler, "pcap_compile");
	}
	return (r);
}
//int 				recv_ipv4_tcp(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec)
//{
//	int				r = RECY_OK;
//	uint32_t		sockaddrlen = sizeof(struct sockaddr_in);
//	uint32_t		seq = 0;
//	uint32_t		seqverif = 0;
//	uint16_t		flag;
//
//	fprintf(stderr, "%s:%d\n", __func__, __LINE__);
//	if (!buf || !conf_st || !conf_nd || !conf_exec)
//	{
//		r = RECY_ERROR;
//	}
//	else
//	{
//		fprintf(stderr, "%s:%d\n", __func__, __LINE__);
//		GET_TCP_SEQ(&buf[sizeof(struct iphdr)], seq);
//		seq = htonl(seq);
//		seq += 1;
//		seqverif = seq;
//		while (seq != htonl(seqverif) && seq - 1 != htonl(seqverif))
//		{
//			r = recvfrom(((t_nmap_link*)conf_st)->socket, buf,
//							MAP_BLCK_SIZE, 0,
//				 (struct sockaddr*)&((t_nmap_link*)conf_st)->sock, &sockaddrlen);
//			GET_TCP_ACK(&buf[sizeof(struct iphdr)], seqverif);
//		}
//		if (r != -1)
//		{
//			//print_packet(buf, length);
//			GET_TCP_FLAGS(&buf[sizeof(struct iphdr)], flag);
//			((t_nmap_scan*)conf_exec)->result = flag;
//			r = RECY_OK;
//			fprintf(stderr, "flag received = %04x\n", flag);
//		}
//		else
//		{
//			perror("recv");
//		}
//	}
//	((t_nmap_scan*)conf_exec)->packet_length = MAP_BLCK_SIZE;
//	return (r);
//}
