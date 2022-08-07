
# include "ft_nmap.h"
# include <stdlib.h>

int32_t			build_tcp_ip_raw(uint8_t **buffer)
{
	int32_t ret = FT_NMAP_OK;
	
	if (!buffer)
	{
		ret = FT_NMAP_ERROR;
	}
	else
	{
		/* Allocate evrything we need, add 8 byte for MSS */
		*buffer = malloc(sizeof(struct iphdr) + sizeof(struct tcphdr) + 8);
		if (!buffer)
		{
			ret = FT_NMAP_ERROR;
		}
		if (!memset(*buffer, 0, sizeof(struct iphdr) + sizeof(struct tcphdr) + 8))
		{
			ret = FT_NMAP_ERROR;
		}
	}
	return (ret);
}
