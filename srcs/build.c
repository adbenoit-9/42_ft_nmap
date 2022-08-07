/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:33:52 by leon              #+#    #+#             */
/*   Updated: 2022/08/07 22:28:52 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_nmap.h"

# include <netinet/ip.h>
# include <netinet/ip6.h>

# include <netinet/tcp.h>
# include <netinet/udp.h>

# include <stdlib.h>

int32_t			build_tcp_ip_raw(uint8_t **buffer)
{
	int32_t ret = FT_NMAP_OK;
	
	if (!buffer)
	{
		ret = FT_NMAP_ERROR;
	}
	else
	{
		/* Allocate everything we need, add 8 byte for MSS */
		*buffer = malloc(sizeof(struct iphdr) + sizeof(struct tcphdr) + 8);
		if (!buffer)
		{
			ret = FT_NMAP_ERROR;
		}
		if (!memset(*buffer, 0, sizeof(struct iphdr) + sizeof(struct tcphdr) + 8))
		{
			ret = FT_NMAP_ERROR;
		}
	}
	return (ret);
}

int32_t			build_udp_ip_raw(uint8_t **buffer)
{
	int32_t ret = FT_NMAP_OK;
	
	if (!buffer)
	{
		ret = FT_NMAP_ERROR;
	}
	else
	{
		/* Allocate everything we need */
		*buffer = malloc(sizeof(struct iphdr) + sizeof(struct udphdr));
		if (!buffer)
		{
			ret = FT_NMAP_ERROR;
		}
		if (!memset(*buffer, 0, sizeof(struct iphdr) + sizeof(struct udphdr)))
		{
			ret = FT_NMAP_ERROR;
		}
	}
	return (ret);
}

int32_t			build_udp_ip6_raw(uint8_t **buffer)
{
	int32_t ret = FT_NMAP_OK;
	
	if (!buffer)
	{
		ret = FT_NMAP_ERROR;
	}
	else
	{
		/* Allocate everything we need */
		*buffer = malloc(sizeof(struct ip6_hdr) + sizeof(struct udphdr));
		if (!buffer)
		{
			ret = FT_NMAP_ERROR;
		}
		if (!memset(*buffer, 0, sizeof(struct ip6_hdr) + sizeof(struct udphdr)))
		{
			ret = FT_NMAP_ERROR;
		}
	}
	return (ret);
}

int32_t			build_tcp_ip6_raw(uint8_t **buffer)
{
	int32_t ret = FT_NMAP_OK;
	
	if (!buffer)
	{
		ret = FT_NMAP_ERROR;
	}
	else
	{
		/* Allocate everything we need */
		*buffer = malloc(sizeof(struct ip6_hdr) + sizeof(struct tcphdr));
		if (!buffer)
		{
			ret = FT_NMAP_ERROR;
		}
		if (!memset(*buffer, 0, sizeof(struct ip6_hdr) + sizeof(struct tcphdr)))
		{
			ret = FT_NMAP_ERROR;
		}
	}
	return (ret);
}
