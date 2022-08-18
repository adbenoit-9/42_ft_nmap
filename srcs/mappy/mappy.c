#include "mappy.h"

#include <stdbool.h>

#include "mappy_data.h"

int				mappy_nd(t_proto_root *root, t_proto_tree *st, t_proto_tree *nd)
{
	int				r		= MAPPY_OK;
	uint8_t		*head	= NULL;
	uint32_t				i		= 0;
	int				j		= 0;
	bool			b		= 1;

	if (!root || !root->config || !st || !nd)
	{
		r = MAPPY_ERROR;
	}
	else
	{
		while (i < SETY_RD_CONFIG_SIZE && (i / SETY_RD_CONFIG_SIZE) < nd->nb_elements)
		{
			head = &(root->config[i]);
			i = 0;
			while (((((t_proto_elem*)head)->execution_task_list[i] & TASK_EXECUTION_TODO_MSK) == 0) &&
						i < MAX_EXECUTION_LIST)
			{
				++i;
			}
			if (i != MAX_EXECUTION_LIST)
			{
				((t_proto_elem*)head)->execution_task_list[i] &= ~TASK_EXECUTION_TODO_MSK;
				if (((t_proto_elem*)head)->execution_task_list[i] > MAPPY_MAX_EXECUTION_CMD - 1 ||
						((t_proto_elem*)head)->execution_target[i] > MAPPY_MAX_EXECUTION_HOOK - 1)
				{
					r = MAPPY_ERROR;
				}
				else
				{
					b = 0;
#ifdef MAPPY_DEBUG
					fprintf(stderr, "%s:%d j=%d r=%d i=%d task=%d hook=%d \n", __func__, __LINE__, j, r, i,
								((t_proto_elem*)head)->execution_task_list[i] ,
                                	((headst_rd->content)->execution_target[i]);
#endif /* MAPPY_DEBUG */
					r = (*_exec[((t_proto_elem*)head)->execution_task_list[i]]
										[((t_proto_elem*)head)->execution_target[i]])
										(&(root->map)[((t_proto_elem*)head)->map_index],
										st,
										nd,
										head);
				}
			}
#ifdef MAPPY_DEBUG
			fprintf(stderr, "%s:%d j=%d r=%d X=%d Y=%d pox=%08lx\n", __func__, __LINE__, r, 
								((t_proto_tree*)st)->index,
								((t_proto_tree*)nd)->index,
								j,
								(uint64_t)(index + j * MAX_PACKET_SIZE));
#endif
			i += SETY_RD_CONFIG_SIZE;
			++j;
		}
	}
	if (r == MAPPY_OK && b == 1)
	{
		((t_proto_tree*)nd)->status = MAPPY_NO_MORE;
	}
	return (r);
}

int				mappy_st(t_proto_root *root, t_proto_tree *st)
{
	int				r		= MAPPY_OK;
	uint8_t		*head	= NULL;
	uint32_t				i		= 0;
	int				j		= 0;
	bool			b		=	0;

	if (!root || !root->config || !st)
	{
		r = MAPPY_OK;
	}
	else
	{
		while (i < SETY_ND_SIZE && (i / SETY_ND_CONFIG_SIZE) < st->nb_elements)
		{
			head = (&root->config[st->conf_index + i]);
			if (((t_proto_tree*)head)->status != MAPPY_NO_MORE)
			{
				b = 1;
				r = mappy_nd(root, st, (t_proto_tree*)head);
			}
#ifdef SETY_DEBUG
			fprintf(stderr, "%s:%d j=%d\n", __func__, __LINE__, j);
#endif /* SETY_DEBUG */
			i += SETY_ND_CONFIG_SIZE;
			++j;
		}
	}
	if (r == MAPPY_OK && b == 0)
	{
		((t_proto_tree*)st)->status = MAPPY_NO_MORE;
	}
	return (r);
}

int				mappy(t_proto_root *root)
{
	int				r		= MAPPY_OK;
	uint8_t		*head	= NULL;
	uint32_t				i		= 0;
	int				j		= 0;
	bool			b		= 0;

	if (!root || !root->config)
	{
		r = MAPPY_ERROR;
	}
	else
	{
		while (i < SETY_ST_SIZE && (i / SETY_ST_CONFIG_SIZE) < root->nb_elements)
		{
			head = (&root->config[i]);
			if (((t_proto_tree*)head)->status != MAPPY_NO_MORE)
			{
				r = mappy_st(root, (t_proto_tree*)head);
			}
#ifdef SETY_DEBUG
			fprintf(stderr, "%s:%d j=%d\n", __func__, __LINE__, j);
#endif /* SETY_DEBUG */
			i += SETY_ST_CONFIG_SIZE;
			++j;
		}
		if (r == MAPPY_OK && b == 0)
		{
			fprintf(stderr, "Job Done !\n");
		}
	}
	return (r);
}
