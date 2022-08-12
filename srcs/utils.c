/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 19:25:21 by leon              #+#    #+#             */
/*   Updated: 2022/08/12 20:19:31 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int				get_urandom(uint8_t *buf, int length)
{
	int			randomfd;
	int			r = 0;
	uint8_t		tmp[512];
	int			offset = 0;

	if (!buf)
	{
		r = -1;
	}
	else
	{
		randomfd = open("/dev/urandom", O_RDONLY);
		if (randomfd < 0)
		{
			r = -1;
		}
		if (r == 0)
		{
			while ((r == 0) && offset < length)
			{
				if (read(randomfd, tmp, 512) < 0)
				{
					r = -1;
				}
				if (offset + 512 > length)
				{
					memcpy(&buf[offset], tmp, length % 512);
				}
				else
				{
					memcpy(&buf[offset], tmp, 512);
				}
				offset += 512;
			}
		}
		if (r == 0)
		{
			close(randomfd);
		}
	}
	return (r);
}

uint16_t			ipv4_checksum(uint16_t *addr, int len)
{
	int							nleft;
	int							sum;
	uint16_t					*w;
	uint16_t					answer;

	answer = 0;
	w = addr;
	sum = 0;
	nleft = len;
	while (nleft > 1)
	{
		sum += *w++;
		nleft -= sizeof(uint16_t);
	}
	if (nleft == 1)
	{
		*(uint16_t*)(&answer) = *(uint16_t*)w;
		sum += answer;
	}
	sum = (sum >> 16) + (sum & 0xFFFF);
	sum += (sum >> 16);
	answer = ~sum;
	return (answer);
}
