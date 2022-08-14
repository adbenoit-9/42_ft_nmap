/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:10:52 by adbenoit          #+#    #+#             */
/*   Updated: 2022/08/14 17:15:08 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NMAP_H
# define FT_NMAP_H

# include <string.h>
# include "ft_nmap_parsing.h"
# include "ft_nmap_ip.h"
# include "ft_nmap_tcp.h"
# include "ft_nmap_sendy.h"
# include "ft_nmap_error.h"
# include "../libft/inc/libft.h"

# define FT_NMAP_OK			0
# define FT_NMAP_ERROR		-1

void	clear_ip(void *ip);

#endif
