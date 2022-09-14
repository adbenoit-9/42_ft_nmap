/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_analysy.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 01:52:24 by leon              #+#    #+#             */
/*   Updated: 2022/09/14 18:11:57 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_ANALYSY_H
# define EXPORT_ANALYSY_H

# include <stdint.h>
# include "mapy.h"

/* Exported function */
int analyse_synscan_ipv4(uint8_t *, T_CLIENT_ST *, T_CLIENT_ND *, T_CLIENT_RD *);
int analyse_synscan_ipv6(uint8_t *, T_CLIENT_ST *, T_CLIENT_ND *, T_CLIENT_RD *);

# define SELECT_HOOK_ANALYSY(sockaddr, nd, hook) do { \
		hook = 0; \
} while (0)

#endif
