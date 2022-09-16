/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:10:52 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/16 10:43:11 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NMAP_H
# define FT_NMAP_H

# include <string.h>
# include "parsy.h"
//# include "ft_nmap_sendy.h"
# include "parsy_error.h"
# include "../libft/inc/libft.h"

void	clear_ip(void *ip);

# define FT_NMAP_NO_MORE	1
# define FT_NMAP_OK			0
# define FT_NMAP_ERROR		-1

#endif
