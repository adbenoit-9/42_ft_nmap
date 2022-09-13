/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleany.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 23:58:41 by leon              #+#    #+#             */
/*   Updated: 2022/08/25 18:47:52 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEANY_H
# define CLEANY_H

#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

/* Project Header */
#include "nmap_structs.h"

#define CLEANY_OK	0
#define CLEANY_ERROR	-1

# define SELECT_HOOK_CLEANY(sockaddr, nd, hook) do { \
		hook = 0; \
} while (0)

#endif
