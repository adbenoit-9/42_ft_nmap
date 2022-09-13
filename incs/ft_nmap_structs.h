
#ifndef FT_NMAP_STRUCTS_H
# define FT_NMAP_STRUCTS_H

#include "mappy.h"

typedef struct			s_link {
	t_mappy_proto				cross;
	struct sockaddr_storage		sock;
}						t_link;

typedef struct			s_app {
	t_mappy_proto				cross;
	uint16_t 					port;
}						t_app;

typedef struct		s_scan {
	t_exec_proto				cross;
/* out value */
	uint32_t				result;
/* internal use */
	int					socket;
	uint32_t				packet_length;
/* in params */
	uint16_t				tcpflag;
}				t_scan;
#endif
