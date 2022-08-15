/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mappy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:52:55 by leon              #+#    #+#             */
/*   Updated: 2022/08/16 00:44:29 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_NMAP_MAPPY_H
# define FT_NMAP_MAPPY_H

#include "ft_nmap.h" // TODO select header

#include <stdint.h>

/*
** Mappy
** Multi-threaded execution
** Take a workbuffer in param with this value at compile time :
** User must pass a buffer of MAPPY_SIZE (compile time) to mappy
*/

# define MAX_ST							128 /* Number of top of tree element supported */
# define MAX_ND							1024 /* Number of 2nd level of tree element supported */
# define MAX_RD							6 /* Number of 3rd level of tree element supported */
# define MAX_BUFFER_SIZE				64 /* Buffer size for each element */

# define MAPPY_SIZE						(MAX_ST * MAPPY_ST_SIZE)
# define MAPPY_ST_SIZE					(MAX_ND * MAPPY_ND_SIZE)
# define MAPPY_ND_SIZE					(MAX_RD * MAX_BUFFER_SIZE)


/*
** Prototype of function allowed by mappy :
** int 				proto_exec(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec)
**
** Where conf_st is configuration from top of tree
** Where conf_nd is configuration from 2nd level of tree
** Where conf_exec is configuration from 3rd level of tree (uniq for each element)
** Where buf target the dedicated element portion buffer. Hook are not allowed to write > MAX_BUFFER_SIZE.
**
** At the execution mappy will check in execution_task_list of t_exec_proto of third level
** tree. If != 0 it will lock this value to 0 and mappy will call
* (*_exec[execution_task_list[i]][execution_target[i]])
*/

#define MAX_EXECUTION_LIST				10
#define TASK_EXECUTION_TODO_MSK			0x80
#define MAX_EXECUTION_CMD		8
#define MAX_EXECUTION_HOOK		8

/*
** Cross layer structures
** TODO only one ptr is required
*/
typedef struct		s_mappy_proto {
	uint32_t 					index;
	t_list						*st;
	t_list						*nd;
	t_list						*rd;
 	uint32_t					status;
}					t_mappy_proto;

typedef struct		s_exec_proto {
// uint8_t						*buf;
 uint8_t						execution_target[MAX_EXECUTION_LIST]; // This one is for selected hook, value contain hook index
 uint8_t						execution_task_list[MAX_EXECUTION_LIST]; // This one is for cmd : value contain cmd index
 uint32_t						status;
}					t_exec_proto;

/* Exported functions */
int32_t					mappy(uint8_t *buf, t_list *lst_ll);

/*
Example of use :

typedef struct		s_st {
	t_mappy_proto				cross;
	uint8_t 					st_flag;
}					t_st;

typedef struct		s_nd {
	t_mappy_proto				cross;
	uint8_t 					nd_flag;
}					t_nd;

typedef struct		s_result {
	t_exec_proto				cross;
	uint8_t						exec_flag;
}					t_result;
int 				add_sample_1(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec)
{
	int j = 0;

	while (j < MAX_BUFFER_SIZE)
	{
		buf[j] += ((t_st*)conf_st)->st_flag;
		buf[j] += ((t_nd*)conf_nd)->nd_flag;
		buf[j] += ((t_exec*)conf_exec)->exec_flag;
		j++;
	}
	return (0);
}
int 				sub_sample_1(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec)
{
	int j = 0;

	while (j < MAX_BUFFER_SIZE)
	{
		buf[j] -= ((t_st*)conf_st)->st_flag;
		buf[j] -= ((t_nd*)conf_nd)->nd_flag;
		buf[j] -= ((t_exec*)conf_exec)->exec_flag;
		j++;
	}
	return (0);
}
int 				mul_sample_1(uint8_t *buf, void *conf_st, void *conf_nd, void *conf_exec)
{
	int j = 0;

	while (j < MAX_BUFFER_SIZE)
	{
		buf[j] *= ((t_st*)conf_st)->st_flag;
		buf[j] *= ((t_nd*)conf_nd)->nd_flag;
		buf[j] *= ((t_exec*)conf_exec)->exec_flag;
		j++;
	}
	return (0);
}
int	(*_exec[MAX_EXECUTION_CMD][MAX_EXECUTION_HOOK])(uint8_t *, void *, void *, void *) = {
	{ // Cmd table
		{ // Hook table
			add_sample_1,
			NULL,
		}
	},
	{
		{
			sub_sample_1,
			NULL,
		}
	},
	{
		{
			mul_sample_1,
			NULL,
		}
	},
	NULL
};
#define MAPPYHOOKINDEX_ADD_SAMPLE_1		0
#define MAPPYHOOKINDEX_SUB_SAMPLE_1		0
#define MAPPYHOOKINDEX_MUL_SAMPLE_1		0

*/
#endif

