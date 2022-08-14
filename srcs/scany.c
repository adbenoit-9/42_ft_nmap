/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scany.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 13:42:55 by leon              #+#    #+#             */
/*   Updated: 2022/08/14 18:03:45 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap.h"
#include "ft_nmap_utils.h"
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>

// Must write all the header here
// All proto with tcp can have shared function with ipv4, ipv6, tcp
// int 				proto_scan(uint8_t *buf, void *conf_ll, void *conf_hl, void *conf_scan)

static int			set_scan_tcp(uint8_t *tcp_buf, uint16_t ipproto)
{
	int			r				= FT_NMAP_OK;
	int32_t		length			= 0;
	uint16_t	tcpId			= 0;
	uint32_t	tcpSeq			= 0;
	uint8_t		ttl				= 0;
	uint16_t	sport			= 0;

	if (!tcp_buf)
	{
		r = FT_NMAP_ERROR;
	}
	else
	{
		if (ipproto == AF_INET)
		{
			r = get_urandom((uint8_t*)&tcpId, 2);
			if (r == FT_NMAP_OK)
			{
				r = get_urandom((uint8_t*)&tcpSeq, 4);
			}
			while ((r == FT_NMAP_OK) && ttl < 30)
			{
				r = get_urandom(&ttl, 1);
			}
			while ((r == FT_NMAP_OK) && sport < 1024)
			{
				r = get_urandom((uint8_t*)&sport, 2);
			}
			if (r == FT_NMAP_OK)
			{
				SET_IP4_VERSION(tcp_buf, 0x04);
				SET_IP4_IHL(tcp_buf, 0x05);
				SET_IP4_TOS(tcp_buf, 0x00);
				SET_IP4_PROTOCOL(tcp_buf, 0x06);

				uint32_t	dip; // DEBUG
				inet_pton(AF_INET, "127.0.0.1", &dip); // DEBUG
				SET_IP4_DADDR(tcp_buf, dip); // DEBUG
				SET_IP4_SADDR(tcp_buf, dip); // DEBUG

				SET_IP4_FRAG_OFF(tcp_buf, 0x0000);
				SET_IP4_ID(tcp_buf, tcpId);
				SET_IP4_TTL(tcp_buf, 0x01); //ttl);


				SET_TCP_SEQ(&tcp_buf[sizeof(struct iphdr)], tcpSeq);
				SET_TCP_SPORT(&tcp_buf[sizeof(struct iphdr)], sport);
				SET_TCP_WIN(&tcp_buf[sizeof(struct iphdr)], 0x0004);
				SET_TCP_URP(&tcp_buf[sizeof(struct iphdr)], 0x0000);
				length = sizeof(struct iphdr) + sizeof(struct tcphdr);
				SET_TCP_OFF(&tcp_buf[sizeof(struct iphdr)], 5);
				SET_IP4_TOT_LEN(tcp_buf, htons(length));
				SET_IP4_CHECK(tcp_buf, ipv4_checksum((uint16_t*)tcp_buf,
						sizeof(struct iphdr)));
			}
		}
		else
		{
			// TODO ipv6
		}
	}
	return (r);
}

static void			print_packet(uint8_t *buf, uint32_t length)
{
	uint32_t j = 0;
	printf("PACKET : ");
	while (j < length - 1)
	{
		printf("%02x%02x ", buf[j], buf[j+1]);
		j += 2;
	}
	printf("\n");
(void)buf;
(void)length;
}

int 				scan_tcp_syn(uint8_t *buf, void *conf_ll, void *conf_hl, void *conf_scan)
{
	int		r		= FT_NMAP_OK;
	t_ip	*ip;
	t_port	*port;
	t_scan	*scan;
	int32_t		length			= 0;

	ip = (t_ip*)conf_ll;
	port = (t_port*)conf_hl;
	scan = (t_scan*)conf_scan;
	if (!ip || !port || !scan || !buf)
	{
		r = FT_NMAP_ERROR;
	}
	else
	{
		/* First build header */
		memset(buf, 0, MAX_PACKET_SIZE);
		/* Set common tcp scan */
		r = set_scan_tcp(buf, ip->sock.ss_family);
		if (r == FT_NMAP_OK)
		{
			/* SYN : add MSS + add flag*/
			length = sizeof(struct iphdr) + sizeof(struct tcphdr);
	   		length += 4;
	   		SET_TCP_DATA(&buf[sizeof(struct iphdr)], syn_mss, 4);


	   		SET_TCP_OFF(&buf[sizeof(struct iphdr)], 6);
			SET_IP4_TOT_LEN(buf, htons(length));
			SET_TCP_FLAGS(&buf[sizeof(struct iphdr)], FLAG_S_SYN);
			SET_TCP_DPORT(&buf[sizeof(struct iphdr)], htons(port->port));

			SET_TCP_SUM(&buf[sizeof(struct iphdr)], tcp_ipv4_checksum(buf, length - sizeof(struct iphdr)));
		}
		int sock;
		if (r == FT_NMAP_OK)
		{

			/* Request a socket */
			sock = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
			if (sock< 0)
			{
				fprintf(stderr, "%s:%d socket call failed, are you root ?\n", __func__, __LINE__);
				r = FT_NMAP_ERROR;
			}
		}
		if (r == FT_NMAP_OK)
		{
			/* Send this scan */
			r = sendto(sock, buf, length, 0, (const struct sockaddr*)&((t_ip*)conf_ll)->sock, sizeof(struct sockaddr_in));
			if (r < 0)
				perror("sendto");
		}
	}
	print_packet(buf, length);
	return (r);
}
int 				scan_tcp_null(uint8_t *buf, void *conf_ll, void *conf_hl, void *conf_scan)
{
	int		r		= FT_NMAP_OK;
	t_ip	*ip;
	t_port	*port;
	t_scan	*scan;
	int32_t		length			= 0;

	ip = (t_ip*)conf_ll;
	port = (t_port*)conf_hl;
	scan = (t_scan*)conf_scan;
	if (!ip || !port || !scan || !buf)
	{
		r = FT_NMAP_ERROR;
	}
	else
	{
		memset(buf, 0, MAX_PACKET_SIZE);
		/* Set common tcp scan */
		r = set_scan_tcp(buf, ip->sock.ss_family);
		if (r == FT_NMAP_OK)
		{
			/* SYN : add MSS + add flag*/
			length = sizeof(struct iphdr) + sizeof(struct tcphdr);
			SET_TCP_FLAGS(&buf[sizeof(struct iphdr)], FLAG_S_NULL);
			SET_TCP_DPORT(&buf[sizeof(struct iphdr)], htons(port->port));
			SET_TCP_SUM(&buf[sizeof(struct iphdr)], tcp_ipv4_checksum(buf, length - sizeof(struct iphdr)));
		}
	print_packet(buf, length);
	}
	return (r);
}

int 				scan_tcp_ack(uint8_t *buf, void *conf_ll, void *conf_hl, void *conf_scan)
{
	int		r		= FT_NMAP_OK;
	t_ip	*ip;
	t_port	*port;
	t_scan	*scan;
	int32_t		length			= 0;

	ip = (t_ip*)conf_ll;
	port = (t_port*)conf_hl;
	scan = (t_scan*)conf_scan;
	if (!ip || !port || !scan || !buf)
	{
		r = FT_NMAP_ERROR;
	}
	else
	{
		memset(buf, 0, MAX_PACKET_SIZE);
		/* Set common tcp scan */
		r = set_scan_tcp(buf, ip->sock.ss_family);
		if (r == FT_NMAP_OK)
		{
			/* SYN : add MSS + add flag*/
			length = sizeof(struct iphdr) + sizeof(struct tcphdr);
			SET_TCP_FLAGS(&buf[sizeof(struct iphdr)], FLAG_S_ACK);
			SET_TCP_DPORT(&buf[sizeof(struct iphdr)], htons(port->port));
			SET_TCP_SUM(&buf[sizeof(struct iphdr)], tcp_ipv4_checksum(buf, length - sizeof(struct iphdr)));
		}
	print_packet(buf, length);
	}
	return (r);
}

int 				scan_tcp_fin(uint8_t *buf, void *conf_ll, void *conf_hl, void *conf_scan)
{
	int		r		= FT_NMAP_OK;
	t_ip	*ip;
	t_port	*port;
	t_scan	*scan;
	int32_t		length			= 0;

	ip = (t_ip*)conf_ll;
	port = (t_port*)conf_hl;
	scan = (t_scan*)conf_scan;
	if (!ip || !port || !scan || !buf)
	{
		r = FT_NMAP_ERROR;
	}
	else
	{
		memset(buf, 0, MAX_PACKET_SIZE);
		/* Set common tcp scan */
		r = set_scan_tcp(buf, ip->sock.ss_family);
		if (r == FT_NMAP_OK)
		{
			/* SYN : add MSS + add flag*/
			length = sizeof(struct iphdr) + sizeof(struct tcphdr);
			SET_TCP_FLAGS(&buf[sizeof(struct iphdr)], FLAG_S_FIN);
			SET_TCP_DPORT(&buf[sizeof(struct iphdr)], htons(port->port));
			SET_TCP_SUM(&buf[sizeof(struct iphdr)], tcp_ipv4_checksum(buf, length - sizeof(struct iphdr)));
		}
	print_packet(buf, length);
	}
	return (r);
}

int 				scan_tcp_xmas(uint8_t *buf, void *conf_ll, void *conf_hl, void *conf_scan)
{
	int		r		= FT_NMAP_OK;
	t_ip	*ip;
	t_port	*port;
	t_scan	*scan;
	int32_t		length			= 0;

	ip = (t_ip*)conf_ll;
	port = (t_port*)conf_hl;
	scan = (t_scan*)conf_scan;
	if (!ip || !port || !scan || !buf)
	{
		r = FT_NMAP_ERROR;
	}
	else
	{
		memset(buf, 0, MAX_PACKET_SIZE);
		/* Set common tcp scan */
		r = set_scan_tcp(buf, ip->sock.ss_family);
		if (r == FT_NMAP_OK)
		{
			/* SYN : add MSS + add flag*/
			length = sizeof(struct iphdr) + sizeof(struct tcphdr);
			SET_TCP_FLAGS(&buf[sizeof(struct iphdr)], FLAG_S_XMAS);
			SET_TCP_DPORT(&buf[sizeof(struct iphdr)], htons(port->port));
			SET_TCP_SUM(&buf[sizeof(struct iphdr)], tcp_ipv4_checksum(buf, length - sizeof(struct iphdr)));
		}
	print_packet(buf, length);
	}
	return (r);
}


int 				scan_udp(uint8_t *buf, void *conf_ll, void *conf_hl, void *conf_scan)
{
	int		r		= FT_NMAP_OK;
	t_ip	*ip;
	t_port	*port;
	t_scan	*scan;
//	int32_t		length			= 0;

	ip = (t_ip*)conf_ll;
	port = (t_port*)conf_hl;
	scan = (t_scan*)conf_scan;
	if (!ip || !port || !scan || !buf)
	{
		r = FT_NMAP_ERROR;
	}
	else
	{
		(void)buf;
		(void)conf_ll;
		(void)conf_hl;
		(void)conf_scan;
	}
	return (r);
}
