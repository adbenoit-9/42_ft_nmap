/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_setupy.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 23:30:20 by leon              #+#    #+#             */
/*   Updated: 2022/09/13 17:24:21 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUPY_EXPORT
# define SETUPY_EXPORT

#include "mapy.h"

#ifdef MAP_CMD_INDEX
# define SETUPY_CMD_INDEX MAP_CMD_INDEX
#endif


/* Exported functions */
int 				setup_ipv4_tcp(uint8_t *buf, T_CLIENT_ST *conf_st, T_CLIENT_ND *conf_nd, T_CLIENT_RD *conf_exec);
int 				setup_ipv4_udp(uint8_t *buf, T_CLIENT_ST *conf_st, T_CLIENT_ND *conf_nd, T_CLIENT_RD *conf_exec);
int 				setup_ipv6_tcp(uint8_t *buf, T_CLIENT_ST *conf_st, T_CLIENT_ND *conf_nd, T_CLIENT_RD *conf_exec);
int 				setup_ipv6_udp(uint8_t *buf, T_CLIENT_ST *conf_st, T_CLIENT_ND *conf_nd, T_CLIENT_RD *conf_exec);

#endif
