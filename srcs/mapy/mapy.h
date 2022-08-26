/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapy.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:30:23 by adbenoit          #+#    #+#             */
/*   Updated: 2022/08/26 11:01:49 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPPY_H
# define MAPPY_H

#include <stdint.h>
#include <stdbool.h>
#include "nmap_mapy_config.h"

#define MAPY_ERR	-1
#define MAPY_OK		0
#define MAPY_IDLE	1
#define MAPY_BUSY	2
#define MAPY_RUN	3

typedef struct			s_exe {
	
	int				hook[EXEC_LST_SIZE]; 
	int				tasks[EXEC_LST_SIZE];
	bool			init;
	int				flag;
	uint32_t		id;
	pthread_mutex_t	mutex;
}						t_exe;

/* Header block structure : can be use for controlling access to blocks */
typedef	struct				s_blk {
	pthread_mutex_t	mutex;
	uint32_t		id;
}							t_blk;

typedef struct			s_rd {
	T_EXE				exe;
	T_CLIENT_RD		client;
}						t_rd;

typedef struct			s_nd {
	t_rd			rd[RD_MAX];
	T_CLIENT_ND		client;
}						t_nd;

typedef struct			s_st {
	t_nd			nd[ND_MAX];
	T_CLIENT_ST		client;
}						t_st;

typedef struct			s_root {
	t_st			st[ST_MAX];
	T_CLIENT_ROOT	client;
	int				st_nb;
	int				nd_nb;
	int				rd_nb;
	uint8_t			*map;
}						t_root;


/* Mappy hook access to the map with all client config struct */
typedef int (*t_func_mapy)(uint8_t *, T_CLIENT_ST *, T_CLIENT_ND *, T_CLIENT_RD *);

/* Sety hook is made for access a client config with all upper config */
typedef int (*t_func_sety)(T_CLIENT_ROOT *, T_CLIENT_ST *, T_CLIENT_ND *, T_CLIENT_RD *);

/* Iter hook is made for access a client config with its index in his lvl of the tree */
typedef int (*t_func_iter_rd)(T_CLIENT_ROOT *, T_CLIENT_RD *, uint32_t index);
typedef int (*t_func_iter_nd)(T_CLIENT_ROOT *, T_CLIENT_ND *, uint32_t index);
typedef int (*t_func_iter_st)(T_CLIENT_ROOT *, T_CLIENT_ST *, uint32_t index);

/* Iter hook is made for access a client config with its index in his lvl of the tree */
typedef int (*t_func_iter_rd)(T_CLIENT_ROOT *, T_CLIENT_RD *, uint32_t index);
typedef int (*t_func_iter_nd)(T_CLIENT_ROOT *, T_CLIENT_ND *, uint32_t index);
typedef int (*t_func_iter_st)(T_CLIENT_ROOT *, T_CLIENT_ST *, uint32_t index);

/* exey access to exe and blk control structure in third lvl of tree */
typedef int (*t_func_exey)(T_CLIENT_ROOT *, T_EXE *, T_BLK *);

/* Exported functions */
int								mapy(t_root *root);
int								mapy_f(t_root *root, t_func_mapy f);

int								set_rd(t_root *root, t_func_sety f);
int								set_nd(t_root *root, t_func_sety f);
int								set_st(t_root *root, t_func_sety f);

int								exey(t_root *root, t_func_exey f);
int								exey_rd(t_root *root, t_func_exey f);
int								exey_ctrl(t_root *root, t_func_exey f);

int								set_iter_st(t_root *root, t_func_iter_st f);
int								set_iter_nd(t_root *root, t_func_iter_nd f);
int								set_iter_rd(t_root *root, t_func_iter_rd f);

#endif
