/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmap_exey_hooks.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:10:49 by leon              #+#    #+#             */
/*   Updated: 2022/08/25 14:31:26 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEY_HOOKS_H
# define EXEY_HOOKS_H

/* For using exey_ctrl */
int					nmap_init_exey(T_CLIENT_ROOT *root, t_exe *exe , t_blk *blk);
int					nmap_clean_exey(T_CLIENT_ROOT *root, t_exe *exe , t_blk *blk);

#endif
