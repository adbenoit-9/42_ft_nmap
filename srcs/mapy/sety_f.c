
//#define DEBUG

#include "mapy.h"
#ifdef DEBUG
#include "stdio.h"
#endif

#define SETY_OK		0

int				sety_f(t_root *root, t_func_sety f)
{
	int			r = SETY_OK;
	int			i;
	int			j;
	int			k;

	//fprintf(stderr, "%s:%d %s\n",__func__, __LINE__, __FILE__);
	i = 0;
	while (r == SETY_OK && i < root->st_nb)
	{
		j = 0;
		while (r == SETY_OK && j < root->nd_nb)
		{
			k = 0;
			while (r == SETY_OK && k < root->rd_nb)
			{
#ifdef DEBUG
				fprintf(stderr, "%s:%8d %s root=%p st=%p nd=%p rd=%p i=%3d j=%3d k=%3d\n",__func__, __LINE__, __FILE__,
							(void *)&root->client,
							(void *)&root->st[i].client,
							(void *)&root->st[i].nd[j].client,
							(void *)&root->st[i].nd[j].rd[k].client, i, j, k);
#endif
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

int				set_nd(t_root *root, t_func_sety f)
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
						(T_CLIENT_ND *)&root->st[i].nd[j].client,
						0);
			j++;
		}
		++i;
	}
	return (r);
}

int				set_st(t_root *root, t_func_sety f)
{
	int			r = SETY_OK;
	int			i;

	i = 0;
	while (r == SETY_OK && i < root->st_nb)
	{
		r = (*f)((T_CLIENT_ROOT *)&root->client,
					(T_CLIENT_ST *)&root->st[i].client,
					0,
					0);
		++i;
	}
	return (r);
}

int				set_iter_rd(t_root *root, t_func_iter_rd f)
{
	int			r = SETY_OK;
	int			i;
	int			j;
	int			k;

	//fprintf(stderr, "%s:%d %s\n",__func__, __LINE__, __FILE__);
	i = 0;
	while (r == SETY_OK && i < root->st_nb)
	{
		j = 0;
		while (r == SETY_OK && j < root->nd_nb)
		{
			k = 0;
			while (r == SETY_OK && k < root->rd_nb)
			{
#ifdef DEBUG
				fprintf(stderr, "%s:%8d %s root=%p st=%p nd=%p rd=%p i=%3d j=%3d k=%3d\n",__func__, __LINE__, __FILE__,
							(void *)&root->client,
							(void *)&root->st[i].client,
							(void *)&root->st[i].nd[j].client,
							(void *)&root->st[i].nd[j].rd[k].client, i, j, k);
#endif
				r = (*f)((T_CLIENT_ROOT *)&root->client,
							(T_CLIENT_RD *)&root->st[i].nd[j].rd[k].client, k);
				k++;
			}
			j++;
		}
		++i;
	}
	return (r);
}

int				set_iter_nd(t_root *root, t_func_iter_nd f)
{
	int			r = SETY_OK;
	int			i = 0;
	int			j = 0;

	i = 0;
	while (r == SETY_OK && i < root->st_nb)
	{
		j = 0;
		while (r == SETY_OK && j < root->nd_nb)
		{
#ifdef DEBUG
			fprintf(stderr, "%s:%d i=%d j=%d root->st_nb=%d, root->nd_nb=%d", __func__, __LINE__, i, j,
						root->st_nb, root->nd_nb);
#endif
			r = (*f)((T_CLIENT_ROOT *)&root->client,
						(T_CLIENT_ND *)&root->st[i].nd[j].client, j);
			j++;
		}
		++i;
	}
	return (r);
}

int				set_iter_st(t_root *root, t_func_iter_st f)
{
	int			r = SETY_OK;
	int			i;

	i = 0;
	while (r == SETY_OK && i < root->st_nb)
	{
#ifdef DEBUG
		fprintf(stderr, "%s:%d i=%d", __func__, __LINE__, i);
#endif
		r = (*f)((T_CLIENT_ROOT *)&root->client,
						(T_CLIENT_ST *)&root->st[i].client, i);
		++i;
	}
	return (r);
}
