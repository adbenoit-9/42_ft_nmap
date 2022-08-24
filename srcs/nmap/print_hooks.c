#include "mapy.h"
#include <stdio.h>

/* ST : t_func_sety_st */
int					print_st(t_nmap_setting *root, t_nmap_link *link)
{
	(void)root;
	fprintf(stderr, "%s:%d link->sock.ss_family = %08x\n", __func__, __LINE__,
					link->sock.ss_family);
	fprintf(stderr, "%s:%d link->socket = %08x\n", __func__, __LINE__,
					link->socket);
	return (0);
}

/* ND : t_func_sety_nd */
int					print_nd(t_nmap_setting *root, t_nmap_link *link, t_nmap_app *app)
{
	(void)root;
	(void)link;
	fprintf(stderr, "%s:%d link->port = %04x\n", __func__, __LINE__,
					app->port);
	return (0);
}

/* RD : t_func_sety_rd */
int					print_rd(t_nmap_setting *root, t_nmap_link *link, t_nmap_app *app, t_nmap_scan *scan)
{
	(void)root;
	(void)link;
	(void)app;
	fprintf(stderr, "%s:%d link->tcpflag = %02x\n", __func__, __LINE__,
					scan->tcpflag);
	return (0);
}
