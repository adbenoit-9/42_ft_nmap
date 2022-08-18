/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nmap_mappy.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:20:57 by leon              #+#    #+#             */
/*   Updated: 2022/08/17 00:33:55 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NMAP_MAPPY
# define FT_NMAP_MAPPY

#include "buildy.h"
#include "sendy.h"
#include "recvy.h"
#include "setupy.h"
#include "cleany.h"

#define HOOK_INDEX_ND_MAX
#define HOOK_INDEX_ST_MAX
#define HOOK_TARGET(index_st, index nd) ((index_st * HOOK_INDEX_ND_MAX) + index_nd)

typedef int (*t_func_mappy)(uint8_t *, void *, void *, void *);

#define BUILDY_HOOK_INDEX0 0

#ifdef NMAP_CMD_INDEX
# define BUILDY_CMD_INDEX NMAP_CMD_INDEX
#endif

// TODO
// cmocka test
// the buffer[MAX_BUFFER_SIZE] is checked entirely before and after
// can return a dump of the buffer somewhere (to dumpy ?)
t_func_mappy _exec[MAX_EXECUTION_CMD][MAX_EXECUTION_HOOK] = {
	{
			/* build */
			build_ipv4_tcp,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
	},
	{
			/* setup */
			setup_ipv4_tcp,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
	},
	{
			/* send */
			send_ip,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
	},
			/* recv */
	{
			recv_ipv4_tcp,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
	},
	{
			/* clean */
			clean_net,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
	},
};

#endif
