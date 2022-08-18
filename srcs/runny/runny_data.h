/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runny_data.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:20:57 by leon              #+#    #+#             */
/*   Updated: 2022/08/18 21:37:40 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NMAP_MAPPY
# define FT_NMAP_MAPPY

#include "export_buildy.h"
#include "export_sendy.h"
#include "export_recy.h"
#include "export_setupy.h"
#include "export_cleany.h"

typedef int (*t_func_mappy)(uint8_t *, void *, void *, void *);

static t_func_mappy *_exec[MAPPY_MAX_EXECUTION_CMD] = {
	_buildy_exec,
	_setupy_exec,
	_sendy_exec,
	_recy_exec,
	_cleany_exec,
};

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
