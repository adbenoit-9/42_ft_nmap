
#ifndef FT_NMAP_IP_H
# define FT_NMAP_IP_H

# include <netinet/ip.h>
# include <netinet/ip6.h> // TODO LMA

#define SET_IP4_VERSION(ip, value) do {((struct iphdr*)ip)->version =\
					(uint8_t)value & (uint8_t)0x0F;} while (0)
#define SET_IP4_IHL(ip, value) do {((struct iphdr*)ip)->ihl =\
					(uint8_t)value & (uint8_t)0x0F;} while (0)
#define SET_IP4_TOS(ip, value) do {((struct iphdr*)ip)->tos = (uint8_t)value;} while (0)
#define SET_IP4_TOT_LEN(ip, value) do {((struct iphdr*)ip)->tot_len =\
       					(uint16_t)value;} while (0)
#define SET_IP4_ID(ip, value) do {((struct iphdr*)ip)->id = (uint16_t)value;} while (0)
#define SET_IP4_FRAG_OFF(ip, value) do {((struct iphdr*)ip)->frag_off =\
       					(uint16_t)value;} while (0)
#define SET_IP4_TTL(ip, value) do {((struct iphdr*)ip)->ttl = (uint8_t)value;} while (0)
#define SET_IP4_PROTOCOL(ip, value) do {((struct iphdr*)ip)->protocol =\
       					(uint8_t)value;} while (0)
#define SET_IP4_CHECK(ip, value) do {((struct iphdr*)ip)->check = (uint16_t)value;} while (0)
#define SET_IP4_SADDR(ip, value) do {((struct iphdr*)ip)->saddr = (uint32_t)value;} while (0)
#define SET_IP4_DADDR(ip, value) do {((struct iphdr*)ip)->daddr = (uint32_t)value;} while (0)

#endif /* FT_NMAP_IP */
