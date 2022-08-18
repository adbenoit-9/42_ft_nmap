#include "mappy.h"
#include <stdbool.h>

#include "sety_data.h"

int				sety_nd(t_proto_root *root, t_proto_tree *st, t_proto_tree *nd)
{
	int				r		= SETY_ERROR;
	uint8_t		*head	= NULL;
	uint32_t				i		= 0;
	int				j		= 0;
	bool			b=1;

	if (!root || !root->config)
	{
		r = SETY_ERROR;
	}
	else
	{
		i = nd->conf_index;
		j = nd->map_index;
		while (i < SETY_MAX_BUFFER_SIZE + nd->conf_index && (i / SETY_RD_CONFIG_SIZE) < nd->nb_elements)
		{
			head = (&root->config[i]);
			((t_proto_tree*)head)->conf_index = i;
			((t_proto_tree*)head)->map_index = j;
			while (((((t_proto_elem*)head)->execution_task_list[i] & TASK_EXECUTION_TODO_MSK) == 0) &&
						i < MAX_EXECUTION_LIST)
			{
				++i;
			}
			if (i != MAX_EXECUTION_LIST)
			{
				((t_proto_elem*)head)->execution_task_list[i] &= ~SETY_TASK_EXECUTION_TODO_MSK;
				if (((t_proto_elem*)head)->execution_task_list[i] > SETY_MAX_EXECUTION_CMD - 1 ||
						((t_proto_elem*)head)->execution_target[i] > SETY_MAX_EXECUTION_HOOK - 1)
				{
					r = SETY_ERROR;
				}
				else
				{
					b = 0;
#ifdef SETY_DEBUG
					fprintf(stderr, "%s:%d j=%d r=%d i=%d task=%d hook=%d \n", __func__, __LINE__, j, r, i,
								((t_proto_elem*)head)->execution_task_list[i] ,
                                	((headst_rd->content)->execution_target[i]);
#endif /* SETY_DEBUG */
					r = (*_sety_nd[((t_proto_elem*)head)->execution_task_list[i]]
										[((t_proto_elem*)head)->execution_target[i]])
										((t_proto_root *)root,
										st,
										nd,
										head);
				}
			}
#ifdef SETY_DEBUG
			fprintf(stderr, "%s:%d j=%d r=%d X=%d Y=%d pox=%08lx\n", __func__, __LINE__, r, 
								((t_proto_tree*)st)->index,
								((t_proto_tree*)nd)->index,
								j,
								(uint64_t)(index + j * MAX_PACKET_SIZE));
#endif
#ifdef SETY_DEBUG
			fprintf(stderr, "%s:%d j=%d\n", __func__, __LINE__, j);
#endif /* SETY_DEBUG */
			i += SETY_MAX_BUFFER_SIZE;
			j += SETY_ND_CONFIG_SIZE;
		}
		if (r == SETY_OK && b == 1)
		{
			((t_proto_tree*)nd)->status = SETY_NO_MORE;
		}
	}
	return (r);
}

int				sety_st(t_proto_root *root, t_proto_tree *st)
{
	int				r		= SETY_OK;
	uint8_t		*head	= NULL;
	uint32_t				i		= 0;
	int				j		= 0;
	bool			b		= 1;

	if (!root || !root->config)
	{
		r = SETY_ERROR;
	}
	else
	{
		i = st->conf_index;
		j = st->map_index;
		while (i < SETY_ND_SIZE + st->conf_index && (i / SETY_ND_CONFIG_SIZE) < st->nb_elements)
		{
			head = (&root->config[i]);
			((t_proto_tree*)head)->conf_index = i;
			((t_proto_tree*)head)->map_index = j;

			while (((((t_proto_elem*)head)->execution_task_list[i] & TASK_EXECUTION_TODO_MSK) == 0) &&
						i < MAX_EXECUTION_LIST)
			{
				++i;
			}
			if (i != MAX_EXECUTION_LIST)
			{
				((t_proto_elem*)head)->execution_task_list[i] &= ~SETY_TASK_EXECUTION_TODO_MSK;
				if (((t_proto_elem*)head)->execution_task_list[i] > SETY_MAX_EXECUTION_CMD - 1 ||
						((t_proto_elem*)head)->execution_target[i] > SETY_MAX_EXECUTION_HOOK - 1)
				{
					r = SETY_ERROR;
				}
				else
				{
					b = 0;
#ifdef SETY_DEBUG
					fprintf(stderr, "%s:%d j=%d r=%d i=%d task=%d hook=%d \n", __func__, __LINE__, j, r, i,
								((t_proto_elem*)head)->execution_task_list[i] ,
                                	((headst_rd->content)->execution_target[i]);
#endif /* SETY_DEBUG */
					r = (*_sety_st[((t_proto_tree*)head)->execution_task_list[i]]
										[((t_proto_tree*)head)->execution_target[i]])
										(root,
										st,
										(t_proto_tree*)head);
				}
			}
#ifdef SETY_DEBUG
			fprintf(stderr, "%s:%d j=%d r=%d X=%d Y=%d pox=%08lx\n", __func__, __LINE__, r, 
								((t_proto_tree*)st)->index,
								((t_proto_tree*)nd)->index,
								j,
								(uint64_t)(index + j * MAX_PACKET_SIZE));
#endif
#ifdef SETY_DEBUG
			fprintf(stderr, "%s:%d j=%d\n", __func__, __LINE__, j);
#endif /* SETY_DEBUG */

#ifdef SETY_DEBUG
			fprintf(stderr, "%s:%d j=%d\n", __func__, __LINE__, j);
#endif /* SETY_DEBUG */
			i += SETY_ND_CONFIG_SIZE;
			j += MAPPY_ND_SIZE;
		}
		if (r == SETY_OK && b == 1)
		{
			((t_proto_tree*)st)->status = SETY_NO_MORE;
		}
	}
	return (r);
}

int				sety_root(t_proto_root *root)
{
	int				r		= SETY_OK;
	uint8_t		*head	= NULL;
	uint32_t				i		= 0;
	int				j		= 0;

	if (!root || !root->config)
	{
		r = SETY_ERROR;
	}
	else
	{
		while (i < SETY_ST_SIZE && (i / SETY_ST_CONFIG_SIZE) < root->nb_elements)
		{
			head = (&root->config[i]);
			((t_proto_tree*)head)->conf_index = i;
			((t_proto_tree*)head)->map_index = j;
			r = (*_sety_root[((t_proto_root*)head)->execution_task_list[i]]
										[((t_proto_root*)head)->execution_target[i]])
										(root,
										(t_proto_tree*)head);
#ifdef SETY_DEBUG
			fprintf(stderr, "%s:%d j=%d\n", __func__, __LINE__, j);
#endif /* SETY_DEBUG */
			i += SETY_ST_CONFIG_SIZE;
			j += MAPPY_ST_SIZE;
		}
	}
	return (r);
}

