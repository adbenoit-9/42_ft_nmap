/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:32:08 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/21 17:32:13 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ND : t_func_iter_nd */
int					set_port(t_nmap_setting *root, t_nmap_link *link, t_nmap_app *app)
{
	(void)root;
	(void)link;
	app->port = 4242;
	return (NMAP_OK);
}

int					set_tcpflag(t_nmap_setting *root, t_nmap_link *link, t_nmap_app *app, t_nmap_scan *scan)
{
	(void)root;
	(void)link;
	(void)app;
	scan->tcpflag = FLAG_S_SYN;
	return (NMAP_OK);
}
