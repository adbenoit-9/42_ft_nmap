/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_reporty.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 01:52:24 by leon              #+#    #+#             */
/*   Updated: 2022/09/14 13:49:31 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_REPORTY_H
# define EXPORT_REPORTY_H

# include <stdint.h>
# include "mapy.h"

/* Exported function */
int report(uint8_t *, T_CLIENT_ST *, T_CLIENT_ND *, T_CLIENT_RD *);

# define SELECT_HOOK_REPORTY(sockaddr, nd, hook) do { \
		hook = 0; \
} while (0)

#endif
