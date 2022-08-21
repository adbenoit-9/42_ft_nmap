/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hooks.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:58:34 by leon              #+#    #+#             */
/*   Updated: 2022/08/21 14:59:10 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TEST_HOOKS_H
# define TEST_HOOKS_H

#include "nmap_structs.h"

int					print_st(t_nmap_setting *root, t_nmap_link *link);
int					print_nd(t_nmap_setting *root, t_nmap_link *link, t_nmap_app *app);
int					print_rd(t_nmap_setting *root, t_nmap_link *link, t_nmap_app *app, t_nmap_scan *scan);

#endif
