
/* ND : t_func_iter_nd */
int					set_port(t_nmap_setting *root, t_nmap_link *link, t_nmap_app *app)
{
	(void)root;
	(void)link;
	app->port = 4242;
//	fprintf(stderr, "%s:%d\n", __func__, __LINE__);
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
