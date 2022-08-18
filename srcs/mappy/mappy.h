/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mappy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:52:55 by leon              #+#    #+#             */
/*   Updated: 2022/08/18 23:08:53 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_NMAP_MAPPY_H
# define FT_NMAP_MAPPY_H

// #include "ft_nmap.h" // TODO select header

#include <stdint.h>
#include "libft.h"

// #include "runny.h"
// #include "runny_data.h"

/*
 ** Mappy
 ** Multi-threaded execution
 ** Take a workbuffer in param with this value at compile time :
 */
/* PARAM */

#define set_params()

# define MAPPY_MAX_ST							128		/* Number of top of tree element supported */
# define MAPPY_MAX_ND							1024	/* Number of 2nd level of tree element supported */
# define MAPPY_MAX_RD							6		/* Number of 3rd level of tree element supported */
# define MAPPY_MAX_BUFFER_SIZE		64		/* Buffer size for each element */
# define MAPPY_SIZE							(MAPPY_MAX_ST * MAPPY_ST_SIZE)
# define MAPPY_ST_SIZE					(MAPPY_MAX_ND * MAPPY_ND_SIZE)
# define MAPPY_ND_SIZE					(MAPPY_MAX_RD * MAPPY_MAX_BUFFER_SIZE)

# define SETY_MAX_ST							16		/* Number of top of tree element supported */
# define SETY_ST_CONFIG_SIZE			64 // I can sizeof this
# define SETY_MAX_ND							1048	/* Number of 2nd level of tree element supported */
# define SETY_ND_CONFIG_SIZE			64
# define SETY_MAX_RD							6		/* Number of 3rd level of tree element supported */
# define SETY_RD_CONFIG_SIZE			64

#define SETY_MAX_BUFFER_SIZE		64 // TODO we could take different size of buffer for SETY
# define SETY_SIZE								(SETY_MAX_ST * SETY_ST_SIZE)
# define SETY_ST_SIZE							(SETY_MAX_ND * SETY_ND_SIZE)
# define SETY_ND_SIZE							(SETY_MAX_RD * SETY_MAX_BUFFER_SIZE)

#define SETY_MAX_EXECUTION_LIST				10
#define SETY_TASK_EXECUTION_TODO_MSK			0x80
#define SETY_MAX_EXECUTION_CMD		4
#define SETY_MAX_EXECUTION_HOOK		4

#define MAPPY_MAX_EXECUTION_LIST 8
#define MAPPY_MAX_EXECUTION_CMD				8
#define MAPPY_MAX_EXECUTION_HOOK				8


typedef struct		s_proto_tree {
	uint32_t 					map_index; // mappy memory lvl index
	uint32_t					conf_index; // config memory lvl index
	uint32_t					nb_elements; // Need to be filled by upper layer throud a sety_ call (not set in main function)
/* 1st one is for cmd : value contain cmd index */
/* 2nd one is for selected hook, value contain hook index */
	uint8_t						execution_target[SETY_MAX_EXECUTION_LIST];
	uint8_t						execution_task_list[SETY_MAX_EXECUTION_LIST];
	uint32_t					status;
}									t_proto_tree;

typedef struct		s_proto_elem {
	uint32_t					map_index; // Absolute index for mappy buffer of the element
	uint32_t					config_index; // Absolute index for config buffer of the element
	uint8_t						execution_target[MAPPY_MAX_EXECUTION_LIST]; 
	uint8_t						execution_task_list[MAPPY_MAX_EXECUTION_LIST];
	uint32_t					status;
}									t_proto_elem;

typedef struct 					t_proto_root {
	uint8_t							*config; // config ptr of SETY_SIZE
	uint8_t							*map;
	uint8_t						execution_target[MAPPY_MAX_EXECUTION_LIST]; 
	uint8_t						execution_task_list[MAPPY_MAX_EXECUTION_LIST];
	uint8_t 					main_flag;
	uint32_t					nb_elements; // Need to be filled by upper layer throud a sety_ call (not set in main function)
}												t_proto_root;

#define MAPPY_NO_MORE	1
#define MAPPY_OK			0
#define MAPPY_ERROR		-1

#define SETY_NO_MORE	1 // TODO LMA handle well this status byte : should sety have a different
// Where do i clean ??
#define SETY_OK			0
#define SETY_ERROR		-1

/* Exported functions */
int								mappy(t_proto_root *root);
int								sety_root(t_proto_root *root);
int								sety_st(t_proto_root *root, t_proto_tree *st);
int								sety_nd(t_proto_root *root, t_proto_tree *st, t_proto_tree *nd);

typedef int (*t_func_mappy)(uint8_t *, void *, void *, void *);
typedef int (*t_func_sety_nd)(t_proto_root *, t_proto_tree *, t_proto_tree *, void *);
typedef int (*t_func_sety_st)(t_proto_root *, t_proto_tree *, t_proto_tree *);
typedef int (*t_func_sety_root)(t_proto_root *, t_proto_tree *); // called from top, end of iteration of st

#define TASK_EXECUTION_TODO_MSK			0x80
#define MAX_EXECUTION_LIST				10




#endif

