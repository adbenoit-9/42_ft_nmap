/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:10:52 by adbenoit          #+#    #+#             */
/*   Updated: 2022/08/16 00:41:41 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NMAP_H
# define FT_NMAP_H

# include <string.h>
# include "ft_nmap_parsing.h"
//# include "ft_nmap_sendy.h"
# include "ft_nmap_error.h"
# include "../libft/inc/libft.h"

void	clear_ip(void *ip);

# define FT_NMAP_NO_MORE	1
# define FT_NMAP_OK			0
# define FT_NMAP_ERROR		-1

#endif
