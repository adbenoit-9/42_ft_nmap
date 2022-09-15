/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_analysy.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 01:52:24 by leon              #+#    #+#             */
/*   Updated: 2022/09/15 19:02:43 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_ANALYSY_H
# define EXPORT_ANALYSY_H

# include <stdint.h>
# include "mapy.h"

/* Exported function */
int analyse_synscan_ipv4(uint8_t *, T_CLIENT_ST *, T_CLIENT_ND *, T_CLIENT_RD *);
int analyse_synscan_ipv6(uint8_t *, T_CLIENT_ST *, T_CLIENT_ND *, T_CLIENT_RD *);
int analyse_udpscan_ipv4(uint8_t *, T_CLIENT_ST *, T_CLIENT_ND *, T_CLIENT_RD *);
int analyse_udpscan_ipv6(uint8_t *, T_CLIENT_ST *, T_CLIENT_ND *, T_CLIENT_RD *);
int analyse_ackscan_ipv4(uint8_t *, T_CLIENT_ST *, T_CLIENT_ND *, T_CLIENT_RD *);
int analyse_ackscan_ipv6(uint8_t *, T_CLIENT_ST *, T_CLIENT_ND *, T_CLIENT_RD *);
int analyse_fnxscan_ipv4(uint8_t *, T_CLIENT_ST *, T_CLIENT_ND *, T_CLIENT_RD *);
int analyse_fnxscan_ipv6(uint8_t *, T_CLIENT_ST *, T_CLIENT_ND *, T_CLIENT_RD *);

# define SELECT_HOOK_ANALYSY(sockaddr, nd, hook) do {\
	if (nd == FLAG_S_SYN) {\
		hook = 0;\
	}\
	else if (nd == FLAG_S_ACK){\
		hook = 2;\
	}\
	else if (nd == FLAG_S_UDP){\
		hook = 6;\
	}\
	else {\
		hook = 4;\
	}\
	if (((struct sockaddr_storage *)sockaddr)->ss_family == AF_INET6) {\
		++hook;\
	}\
} while (0)

#endif
