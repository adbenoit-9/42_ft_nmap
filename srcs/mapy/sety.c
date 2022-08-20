#include "mapy.h"

#define SETY_OK		0

int				set_rd(t_root *root, t_func_sety_rd f)
{
	int			r = SETY_OK;
	int			i;
	int			j;
	int			k;

	i = 0;
	while (r == SETY_OK && i < root->st_nb)
	{
		j = 0;
		while (r == SETY_OK && j < root->nd_nb)
		{
			k = 0;
			while (r == SETY_OK && k < root->rd_nb)
			{
				r = (*f)((T_CLIENT_ROOT *)&root->client,
							(T_CLIENT_ST *)&root->st[i].client,
							(T_CLIENT_ND *)&root->st[i].nd[j].client,
							(T_CLIENT_RD *)&root->st[i].nd[j].rd[k].client);
				k++;
			}
			j++;
		}
		++i;
	}
	return (r);
}

int				set_nd(t_root *root, t_func_sety_nd f)
{
	int			r = SETY_OK;
	int			i;
	int			j;

	i = 0;
	while (r == SETY_OK && i < root->st_nb)
	{
		j = 0;
		while (r == SETY_OK && j < root->nd_nb)
		{
			r = (*f)((T_CLIENT_ROOT *)&root->client,
						(T_CLIENT_ST *)&root->st[i].client,
						(T_CLIENT_ND *)&root->st[i].nd[j].client);
			j++;
		}
		++i;
	}
	return (r);
}

int				set_st(t_root *root, t_func_sety_st f)
{
	int			r = SETY_OK;
	int			i;

	i = 0;
	while (r == SETY_OK && i < root->st_nb)
	{
		r = (*f)((T_CLIENT_ROOT *)&root->client,
						(T_CLIENT_ST *)&root->st[i].client);
		++i;
	}
	return (r);
}
