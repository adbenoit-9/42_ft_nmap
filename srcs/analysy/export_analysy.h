/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_analysy.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 01:52:24 by leon              #+#    #+#             */
/*   Updated: 2022/09/14 16:42:16 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_ANALYSY_H
# define EXPORT_ANALYSY_H

# include <stdint.h>
# include "mapy.h"

/* Exported function */
int analyse_ipv4_tcp(uint8_t *, T_CLIENT_ST *, T_CLIENT_ND *, T_CLIENT_RD *);

# define SELECT_HOOK_ANALYSY(sockaddr, nd, hook) do { \
		hook = 0; \
} while (0)

#endif
