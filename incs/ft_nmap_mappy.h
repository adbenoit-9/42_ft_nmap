/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nmap_mappy.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:20:57 by leon              #+#    #+#             */
/*   Updated: 2022/08/16 00:00:54 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NMAP_MAPPY
# define FT_NMAP_MAPPY

#include "buildy.h"
#include "sendy.h"
#include "recvy.h"
#include "setupy.h"
#include "cleany.h"

typedef int (*t_func_mappy)(uint8_t *, void *, void *, void *);

// TODO LMA there is a bug here, 
// I may use a struct array filled with ptr
//int	(*_exec[MAX_EXECUTION_CMD][MAX_EXECUTION_HOOK])(uint8_t *, void *, void *, void *) = {
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
			setup_net,
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
