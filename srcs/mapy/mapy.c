#include "mapy.h"

#include <string.h>
#include <stdbool.h>

#include "mapy_func.h"

static int	mapy_exec(t_root *root, t_st *st, t_nd *nd, t_rd *rd, uint64_t index)
{
	int			r			= MAPY_OK;
	int			i			= 0;
	uint32_t	map_id		= 0;
	bool		b			= 1;

	i = 0;
	memcpy(&map_id, &(root->map)[index], sizeof(map_id)); // TODO chech if map_id == 0 
	/* Find the 1st task to do */
	while (i < EXEC_LST_SIZE && ((rd->tasks[i] & EXEC_TODO_MSK) == 0))
	{
		++i;
	}
	if (i == EXEC_LST_SIZE)
	{
		/* Nothing to do, exit */
		r = MAPY_IDLE;
		if (map_id == rd->id)
		{
			/* If this process own the block, release it */
			memset(&(root->map)[index], 0, sizeof(map_id));
		}
	}
	if (r == MAPY_OK)
	{
		/* Check value */
		if (rd->tasks[i] > EXEC_MAX_CMD - 1 ||
				rd->hook[i] > EXEC_MAX_HOOK - 1)
		{
			r = MAPY_ERR;
		}
	}
	if (r == MAPY_OK)
	{
		/* Check if the map is in use */
		if (map_id != 0)
		{
			/* This process is not the owner of the block ? */
			if (map_id != rd->id)
			{
				r = MAPY_BUSY;
			}
		}
		else
		{
			/* This block is free, reserve it */
			memcpy(&rd->id, &(root->map)[index], sizeof(map_id));
		}
	}
	if (r == MAPY_OK)
	{
		/* Clear exec flag */
		rd->tasks[i] &= ~EXEC_TODO_MSK;
#ifdef MAPY_DEBUG
			fprintf(stderr, "%s:%d r=%d i=%d index=%08x task=%d hook=%d \n", __func__, __LINE__, r, i, index,
						(rd->tasks[i] ,
                              	rd->hook[i]);
#endif /* MAPY_DEBUG */
		r = (*_exec[rd->tasks[i]]
								[rd->hook[i]])
								(&(root->map)[index + sizeof(map_id)],
								(T_CLIENT_ROOT*)&root->client,
								(T_CLIENT_ST*)&st->client,
								(T_CLIENT_ND*)&nd->client,
								(T_CLIENT_RD*)&rd->client);
	}
	return (r);
}

int			mapy(t_root *root)
{
	int		r = MAPY_OK;
	int		i = 0;
	int		j = 0;
	int		k = 0;
	int		index;
	
	if (!root)
	{
		r = MAPY_ERR;
	}
	else
	{
		while (i < root->st_nb)
		{
			j = 0;
			while (j < root->nd_nb)
			{
				k = 0;
				while (k < root->rd_nb)
				{
					index = (((i * root->st_nb) * (j * root->nd_nb) * (k * root->rd_nb) +
												(j * root->nd_nb) * (k * root->rd_nb) +
												k) % BLCK_NB) * MAP_BLCK_SIZE;
					r = mapy_exec(root, &root->st[i], &root->st[i].nd[j], &root->st[i].nd[j].rd[k], index);
					k++;
				}
				j++;
			}
			i++;
		}
	}
	return (MAPY_ERR);
}
