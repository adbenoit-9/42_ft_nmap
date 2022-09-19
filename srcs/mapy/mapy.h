/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapy.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:30:23 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/19 15:04:18 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPPY_H
# define MAPPY_H

#include <stdint.h>
#include <stdbool.h>
#include "nmap_mapy_config.h"

#define BLKY_OK 		0
#define BLKY_ERROR 		-1

#define BUILDY_INDEX	0
#define REPORTY_INDEX	1
#define SETUPY_INDEX	2
#define SENDY_INDEX		3
#define RECY_INDEX		4
#define CLEANY_INDEX	5
#define ANALYSY_INDEX	6


#define MAPY_ERR	-1
#define MAPY_OK		0
#define MAPY_IDLE	1
#define MAPY_BUSY	2
#define MAPY_RUN	3

#define BLK_TODO 0x0
#define BLK_DONE 0x1
#define BLK_BUSY 0x2
#define BLK_IDLE 0x3
#define BLK_ERROR -1

typedef struct					s_exe {
	int				hook[EXEC_LST_SIZE]; 
	int				tasks[EXEC_LST_SIZE];
}						t_exe;

/* Header block structure : can be use for controlling access to blocks */
typedef	struct						s_blk {
	t_exe			exe;
	T_CLIENT_ROOT	*root;
    T_CLIENT_ST		*st;
    T_CLIENT_ND		*nd;
	T_CLIENT_RD		*rd;
	uint32_t		flag;
	uint8_t			map[MAP_BLCK_SIZE];
}							t_blk;

typedef struct					s_rd {
	T_CLIENT_RD		client;
	bool			flag;
}						t_rd;

typedef struct					s_nd {
	T_CLIENT_ND		client;
}						t_nd;

typedef struct					s_st {
	T_CLIENT_ST		client;
}						t_st;

typedef struct					s_root {
	t_rd			rd[RD_MAX];
	t_nd			nd[ND_MAX];
	t_st			st[ST_MAX];
	T_CLIENT_ROOT	client;
	uint8_t			blk_flag[RD_MAX * ND_MAX * ST_MAX];
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

int			blky_branch_task_hooks(t_blk *blk);
int			blky(t_blk *blk);
int			blky_init(uint8_t *buf);


#endif
