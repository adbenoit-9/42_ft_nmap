#ifndef MAPPY_H
# define MAPPY_H

#include <stdint.h>
#include "mapy_config.h"

#define MAPY_ERR	-1
#define MAPY_OK		0
#define MAPY_BUSY	1
#define MAPY_IDLE	2

typedef struct			s_rd {
	int				status;
	uint32_t		id;						// Id used to reserve a block
	int				hook[EXEC_LST_SIZE]; 
	int				tasks[EXEC_LST_SIZE];
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
	int				st_nb;
	int				nd_nb;
	int				rd_nb;
	uint8_t			*map;
	T_CLIENT_ROOT	client;
}						t_root;


/* Mappy hook access to the map with all client config struct */
typedef int (*t_func_mapy)(uint8_t *, T_CLIENT_ROOT *, T_CLIENT_ST *, T_CLIENT_ND *, T_CLIENT_RD *);

/* Sety hook is made for access client config with all upper config */
typedef int (*t_func_sety_rd)(T_CLIENT_ROOT *, T_CLIENT_ST *, T_CLIENT_ND *, T_CLIENT_RD *);
typedef int (*t_func_sety_nd)(T_CLIENT_ROOT *, T_CLIENT_ST *, T_CLIENT_ND *);
typedef int (*t_func_sety_st)(T_CLIENT_ROOT *, T_CLIENT_ST *);

/* Exported functions */
int								mappy(t_root *root);

int								set_rd(t_root *root, t_func_sety_rd f);



int								set_nd(t_root *root, t_func_sety_nd f);
int								set_st(t_root *root, t_func_sety_st f);

#endif
