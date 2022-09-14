
#include "mapy.h"
#include "recy.h"
#include "proty.h"

#define RECY_OK		0
#define RECY_ERROR	-1

void				nmap_pcap_handler(u_char *user, const struct pcap_pkthdr *h,
							const u_char *bytes)
{
	int		r		= RECY_OK;
	size_t		i		= 0;

	if (!user || !h || !bytes || h->len > MAP_BLCK_SIZE)
	{
		return ;
	}
	if (r == RECY_OK)
	{
		while (i < h->len && i < MAP_BLCK_SIZE - sizeof(t_nmap_blkhdr))
		{
			((uint8_t*)user)[i] = bytes[i];
			fprintf(stderr, "%02x:", user[i]);
			i++;
		}
		fprintf(stderr, "\n");
	}
}
