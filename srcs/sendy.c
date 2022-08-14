/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sendy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 20:11:57 by leon              #+#    #+#             */
/*   Updated: 2022/08/14 15:42:24 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** In order to speedup we could allocate an array of [MAX_IP][MAX_PORT][MAX_PACKET_SIZE + A struct header with
**																			port, lock and result variable]
** If we have
** #define MAX_IP						128
** #define MAX_PRIVATE_HDR_IP			64
** #define MAX_PORT						1024
** #define MAX_PRIVATE_HDR_PORT			64
** #define MAX_PACKET_SIZE				64
** #define MAX_PRIVATE_HDR_PACKET_SIZE	64
** We have : (MAX_IP * MAX_PRIVATE_HDR_IP) * (MAX_PORT + MAX_PRIVATE_HDR_PORT) * (MAX_PACKET_SIZE + MAX_PRIVATE_PACKET_HDR_SIZE)
** bufSize = 33554432 bytes
** If we do this we could choose to allocate it dynamically or stack it at compile time
** If more IP than MAX_IP juste allocate dynamically
** Or add buffers in struct t_port so it'll be contigus memory and optimized in size if we declare this as an array
**
** If we want to multi-thread the scans inside a port scan we should add :
** #define MAX_SCAN_TYPE				64
** #define MAX_PRIVATE_HDR_SCAN_TYPE	64

** And it become :
** (MAX_IP * MAX_PRIVATE_HDR_IP) * (MAX_PORT + MAX_PRIVATE_HDR_PORT) * (MAX_SCAN_TYPE + MAX_PRIVATE_HDR_SCAN_TYPE) (MAX_PACKET_SIZE + MAX_PRIVATE_PACKET_HDR_SIZE)
** But to get REALLY fast we should multithread PRIVATE_HDR too :/
** So we could do without header in memory but with config in linked list with index on buffer aaaand that should work
** well.
** #define SCAN_TYPEINDEX_SYN	0
** #define SCAN_TYPEINDEX_NULL	0
** #define SCAN_TYPEINDEX_ACK	0
** #define SCAN_TYPEINDEX_FIN	0
** #define SCAN_TYPEINDEX_XMAS	0
** #define SCAN_TYPEINDEX_UDP	0
** All packet shall be written in a :
** int 				io_scans(uint8_t *buf, t_ip *ip, t_port *port, uint8_t scan_type)
** following by a func array call for each scans
** with the proto :
** int 				proto_scan(uint8_t *buf, t_ip *ip, t_port *port)
** or even
** int 				proto_scan(uint8_t *buf, void *conf_osi_ll, void *conf_osi_hl)
** with conf_osi cast to specific piece of osi (ip, tcp or eth, bt, etc)
** Its ok as long as buffer size not overload MAX_PACKET_SIZE
** config is passed through ptr in send.c so we could handle other config struct than t_ip and t_port
** Also, all config in list is read-only
** No config osi_ll or osi_hl must be read in send.c as it just dispatch the thread. It need to read the index
** of the differents struct though.
** For that i could just leave the uint32_t index at the start of struct
** So if i do index_ll = ((uint32_t*)osi_ll)[0] * MAX_OSI_LL; i'll access the index
**
** With that, it should work well.
**
** i can have a struct :
** typedef struct	s_nmap_proto {
** 	uint32_t 	index;
**	t_list		*hl;
**	t_list		*scans;
** }				t_nmap_proto;
** for cross protocol information.
** NOTE : MAX_SCAN_TYPE is a maximum of scan for an high_level proto, we could have +40 scans function for
** many protocols
** t_ft_scan shall contain space for result report that will be filled by scan
**
** typedef struct	s_ft_scan {
**	uint32_t	scan_id;
**	uint32_t	flag; // uint32 pour alignement
** }				t_ft_scan;
** 
** All structure definition shall start with
** 	t_nmap_proto		cross;
** for layer structure
** and
** 	t_ft_scan		cross;
** for scan structure
**
*/
#include "ft_nmap_sendy.h"
#include "ft_nmap_scany.h"

int	(*nmap_scans[])(uint8_t *, void *, void *, void *) = {
	scan_tcp_syn,
	scan_tcp_null,
	scan_tcp_ack,
	scan_tcp_fin,
	scan_tcp_xmas,
	scan_udp,
	NULL
};


int				sendy_scan(uint8_t *buf, void *ll, void *hl)
{
	int			r				= FT_NMAP_OK;
	uint64_t	index			= 0;
	int			j				= 0;
	t_list		*lst_scan		= NULL;

	if (!buf || !ll || !hl)
	{
		r = FT_NMAP_ERROR;
	}
	else
	{
		index = ((t_nmap_proto*)ll)->index * NMAP_LL_SIZE +
				((t_nmap_proto*)hl)->index * NMAP_HL_SIZE;
		if (index > NMAP_BUFFER_SIZE)
		{
			r = FT_NMAP_ERROR;
		}
		if (r == FT_NMAP_OK)
		{
			lst_scan = ((t_nmap_proto*)hl)->scans;
			//fprintf(stderr, "%s:%d\n", __func__, __LINE__);
			/* Process scan */
			while (r == FT_NMAP_OK && lst_scan != NULL)
			{
				if (((t_ft_scan*)lst_scan->content)->scan_id >
						NMAP_SCAN_NB || j >= MAX_SCAN_TYPE)
				{
					r = FT_NMAP_ERROR;
				}
				if (r == FT_NMAP_OK)
				{
					// open thread
					((t_ft_scan*)lst_scan->content)->lock = 1;
					r = (*nmap_scans[((t_ft_scan*)lst_scan->content)->scan_id])(&buf[index + j * MAX_PACKET_SIZE], ll, hl, lst_scan->content);
					// close thread
					j++;
					lst_scan = lst_scan->next;
				}
			}
		}
	}
	return (r);
}

int				sendy_ll(uint8_t *buf, void *ll)
{
	int			r		= FT_NMAP_OK;
	t_list		*lst_hl	= NULL;
	int			j		= 0;

	if (!buf || !ll)
	{
		r = FT_NMAP_ERROR;
	}
	else
	{
		lst_hl = ((t_nmap_proto*)ll)->hl;
		if (lst_hl == NULL)
		{
			r = FT_NMAP_ERROR;
		}
		if (r == FT_NMAP_OK)
		{
			while (r == FT_NMAP_OK && lst_hl != NULL)
			{
				if (j > MAX_HL)
				{
					r = FT_NMAP_ERROR;
				}
				else
				{
					r = sendy_scan(buf, ll, lst_hl->content);
					lst_hl = lst_hl->next;
					++j;
				}
			}
		}
	}
	return (r);
}

int				sendy(uint8_t *buf, t_list *lst_ll)
{
	int		r		= FT_NMAP_OK;
	t_list	*head	= NULL;
	t_list	*tmp	= NULL;

	if (!lst_ll)
	{
		r = FT_NMAP_ERROR;
	}
	else
	{
		head = lst_ll;
		while ((r == FT_NMAP_OK) && (head != NULL))
		{
			tmp = ((t_nmap_proto*)head->content)->hl;
			if (tmp == NULL)
			{
				r = FT_NMAP_ERROR;
			}
			if (r == FT_NMAP_OK)
			{
				r = sendy_ll(buf, head->content);
			}
			head = head->next;
		}
	}
	return (r);
}
