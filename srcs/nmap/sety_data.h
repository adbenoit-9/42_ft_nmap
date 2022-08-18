/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sety_data.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:20:57 by leon              #+#    #+#             */
/*   Updated: 2022/08/18 21:42:23 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NMAP_MAPPY
# define FT_NMAP_MAPPY

#define SETY_MAX_EXECUTION_CMD_ROOT		8
#define SETY_MAX_EXECUTION_CMD_ST		4
#define SETY_MAX_EXECUTION_CMD_ND		4

static t_func_sety_root			*_sety_root[SETY_MAX_EXECUTION_CMD_ROOT] = {
	NULL,
};
static t_func_sety_st			*_sety_st[SETY_MAX_EXECUTION_CMD_ST] = {
	NULL,
};
static t_func_sety_nd			*_sety_nd[SETY_MAX_EXECUTION_CMD_ND] = {
	NULL,
};

// TODO
// cmocka test
// the buffer[MAX_BUFFER_SIZE] is checked entirely before and after
// can return a dump of the buffer somewhere (to dumpy ?)

#endif
