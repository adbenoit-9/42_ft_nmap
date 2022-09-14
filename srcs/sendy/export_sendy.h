/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_sendy.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 01:52:24 by leon              #+#    #+#             */
/*   Updated: 2022/08/23 23:25:44 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_SENDY_H
# define EXPORT_SENDY_H

#include "mapy.h"

/* Exported function */
int send_udp(uint8_t *buf, T_CLIENT_ST *conf_st, T_CLIENT_ND *conf_nd, T_CLIENT_RD *conf_exec);
int send_tcp(uint8_t *buf, T_CLIENT_ST *conf_st, T_CLIENT_ND *conf_nd, T_CLIENT_RD *conf_exec);


# define SELECT_HOOK_SENDY(sockaddr, nd, hook) do { \
if (((struct sockaddr_storage *)sockaddr)->ss_family == AF_INET) { \
	if (nd == FLAG_S_UDP) { \
		hook = 1; \
}	else { \
		hook = 0; \
}} else { \
	if (nd == FLAG_S_UDP){ \
		hook = 3; \
}	else { \
		hook = 2; \
	} \
} \
} while (0)

#endif
