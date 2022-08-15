/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mappy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 20:11:57 by leon              #+#    #+#             */
/*   Updated: 2022/08/16 01:00:27 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** mappy
*/

#include <stdint.h>
#include "mappy.h"
#include "ft_nmap_mappy.h"

int				mappy_loop();

int				mappy_exec(uint8_t *buf, void *st, void *nd)
{
	int			r				= FT_NMAP_OK;
	uint64_t	index			= 0;
	int			j				= 0;
	int			i				= 0;
	t_list		*lst_rd			= NULL;
	uint8_t		b				= 0;

	if (!buf || !st || !nd)
	{
		r = FT_NMAP_ERROR;
	}
	else
	{
		index = ((t_mappy_proto*)st)->index * MAPPY_ST_SIZE +
				((t_mappy_proto*)nd)->index * MAPPY_ND_SIZE;
		if (index > MAPPY_SIZE)
		{
			r = FT_NMAP_ERROR;
		}
		if (r == FT_NMAP_OK)
		{
			while (r == FT_NMAP_OK && b == 0)
			{
				b = 1;
				j = 0;
				lst_rd = ((t_mappy_proto*)nd)->rd;
				/* Process rd */
				while (r == FT_NMAP_OK && lst_rd != NULL && j < MAX_RD)
				{
					i = 0;
					while (((((t_exec_proto*)lst_rd->content)->execution_task_list[i] & TASK_EXECUTION_TODO_MSK) == 0) &&
								i < MAX_EXECUTION_LIST)
					{
						++i;
					}
					if (i != MAX_EXECUTION_LIST)
					{
						((t_exec_proto*)lst_rd->content)->execution_task_list[i] &= ~TASK_EXECUTION_TODO_MSK;
						if (((t_exec_proto*)lst_rd->content)->execution_task_list[i] > MAX_EXECUTION_CMD - 1 ||
								((t_exec_proto*)lst_rd->content)->execution_target[i] > MAX_EXECUTION_HOOK - 1)
						{
							r = FT_NMAP_ERROR;
						}
						else
						{
							b = 0;
#ifdef MAPPY_DEBUG
							fprintf(stderr, "%s:%d j=%d r=%d i=%d task=%d hook=%d \n", __func__, __LINE__, j, r, i,
								((t_exec_proto*)lst_rd->content)->execution_task_list[i] ,
                                	((t_exec_proto*)lst_rd->content)->execution_target[i]);
#endif /* MAPPY_DEBUG */
							r = (*_exec[((t_exec_proto*)lst_rd->content)->execution_task_list[i]]
																	[((t_exec_proto*)lst_rd->content)->execution_target[i]])
												(&buf[index + j * MAX_PACKET_SIZE],
													 st,
													 nd,
													 lst_rd->content);
						}
					}
#ifdef MAPPY_DEBUG
					fprintf(stderr, "%s:%d j=%d r=%d X=%d Y=%d pox=%08lx\n", __func__, __LINE__, r, 
								((t_mappy_proto*)st)->index,
								((t_mappy_proto*)nd)->index,
								j,
								(uint64_t)(index + j * MAX_PACKET_SIZE));
#endif /* MAPPY_DEBUG */
					j++;
					lst_rd = lst_rd->next;
				}
			}
		}
	}
	if (r == FT_NMAP_OK && b == 1)
	{
		((t_mappy_proto*)nd)->status = FT_NMAP_NO_MORE;
	}
	return (r);
}

int				mappy_st(uint8_t *buf, void *st)
{
	int			r		= FT_NMAP_OK;
	t_list		*lst_nd	= NULL;
	int			j		= 0;
	int			b		= 0;

	if (!buf || !st)
	{
		r = FT_NMAP_ERROR;
	}
	else
	{
		lst_nd = ((t_mappy_proto*)st)->nd;
		if (lst_nd == NULL)
		{
			r = FT_NMAP_ERROR;
		}
		if (r == FT_NMAP_OK)
		{
			while (r == FT_NMAP_OK && lst_nd != NULL)
			{
				if (j > MAX_HL)
				{
					r = FT_NMAP_ERROR;
				}
				else
				{
					if (((t_mappy_proto*)st)->status != FT_NMAP_NO_MORE)
					{
						b = 1;
						r = mappy_exec(buf, st, lst_nd->content);
#ifdef MAPPY_DEBUG
						fprintf(stderr, "%s:%d j=%d\n", __func__, __LINE__, j);
#endif /* MAPPY_DEBUG */
					}
					++j;
					lst_nd = lst_nd->next;
				}
			}
		}
	}
	if (r == FT_NMAP_OK && b == 0)
	{
		((t_mappy_proto*)st)->status = FT_NMAP_NO_MORE;
	}
	return (r);
}

int				mappy(uint8_t *buf, t_list *lst_st)
{
	int		r		= FT_NMAP_OK;
	t_list	*head	= NULL;
	int		j		= 0;
	int		b		= 1;

	if (!lst_st)
	{
		r = FT_NMAP_ERROR;
	}
	else
	{
		head = lst_st;
		while ((r == FT_NMAP_OK) && (head != NULL) && b == 1)
		{
			b = 0;
			if (((t_mappy_proto*)head->content)->nd == NULL)
			{
				r = FT_NMAP_ERROR;
			}
			if (r == FT_NMAP_OK)
			{
				if (((t_mappy_proto*)head->content)->status != FT_NMAP_NO_MORE)
				{
					b = 1;
					r = mappy_st(buf, head->content);
#ifdef MAPPY_DEBUG
					fprintf(stderr, "%s:%d j=%d\n", __func__, __LINE__, j);
#endif /* MAPPY_DEBUG */
				}
				j++;
			}
			head = head->next;
		}
		if (b == 0)
		{
#ifdef MAPPY_DEBUG
			fprintf(stderr, "%s:%d job done\n", __func__, __LINE__);
#endif /* MAPPY_DEBUG */
		}
	}
	return (r);
}
