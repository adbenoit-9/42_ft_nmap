
void				ft_pcap_handler(u_char *user, const struct pcap_pkthdr *h, const u_char *bytes)
{
	( void)user;
	uint32_t		i;
	i = 0;
	fprintf(stderr, "%s:%d h->len= %d\n", __func__, __LINE__, h->len);
	while (i < h->len)
	{
		fprintf(stderr, "%02x:", bytes[i]);
		i++;
	}
	fprintf(stderr, "\n");
}

static char pre_built_filter_icmp[] = "icmp[icmptype] == icmp-unreach";
static char pre_built_filter_rst[] = "(tcp[tcpflags] & tcp-rst) == tcp-rst";
static char pre_built_filter_synack[] = "(tcp[tcpflags] & (tcp-syn | tcp-ack)) == (tcp-syn | tcp-ack)";

int 				pcap_init_set_filter(t_root *root)
{
	int			r 							= RECY_OK;
//	uint32_t	i							= 0;
	char					filter[256]		= {0};
	struct	bpf_program		bpf 			= {0};

	if (root)
	{
		r = RECY_ERROR;
	}
	else
	{
		/* Precise src addr */
		snprintf(filter, sizeof(filter), "src host %s and (%s or (src port %d and (%s or %s)))",
							root->host,
							pre_built_filter_icmp,
							root>port,
							pre_built_filter_rst,
							pre_built_filter_synack);
		fprintf(stderr, "filter = {%s}\n", filter);
	}
	r = pcap_compile(root->pcap_handler, &bpf, filter, 0, PCAP_NETMASK_UNKNOWN);
	if (r == 0)
	{
		r = pcap_setfilter(root->pcap_handler, &bpf);
	}
	if (r == 0)
	{
		r = pcap_dispatch(root->pcap_handler, 1, ft_pcap_handler, buf);
	}
	if (r != 0)
	{
		pcap_perror(root->pcap_handler, "pcap_compile");
	}
	return (r);
}
