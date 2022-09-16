/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsy_export.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:05:00 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/16 11:10:03 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSY_EXPORT_H
# define PARSY_EXPORT_H

# include "nmap_structs.h"

# define PARSY_OK   0
# define PARSY_KO   -1
# define PARSY_STOP	1

int		parser(int ac, char **av, t_nmap_setting *settings);

#endif
