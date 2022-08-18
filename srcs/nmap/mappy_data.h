/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mappy_data.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:20:57 by leon              #+#    #+#             */
/*   Updated: 2022/08/18 21:42:09 by leon             ###   ########.fr       */
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


// TODO
// cmocka test
// the buffer[MAX_BUFFER_SIZE] is checked entirely before and after
// can return a dump of the buffer somewhere (to dumpy ?)

#endif
