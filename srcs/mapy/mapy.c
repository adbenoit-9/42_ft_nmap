/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:57:21 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/19 12:27:18 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapy.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <signal.h>
#include <pthread.h>

#define EXEY_ERR	-1
#define EXEY_OK		0
#define EXEY_IDLE	1
#define EXEY_BUSY	2
#define EXEY_RUN	3

int			mapy(t_root *root)
{
	int			r = EXEY_RUN;
	uint64_t		count;
	uint64_t		index;
	t_blk			*blk;
	
	if (!root) {
		r = MAPY_ERR;
	}
	while (r == EXEY_RUN  || r == EXEY_BUSY)
	{
		count = 0;
		r = EXEY_RUN;
		for (int i = 0; (r == EXEY_RUN  || r == EXEY_BUSY) && i < root->st_nb; i++) {
			for (int j = 0; (r == EXEY_RUN  || r == EXEY_BUSY || r == EXEY_IDLE) && j < root->nd_nb; j++) {
				for (int k = 0; (r == EXEY_RUN  || r == EXEY_BUSY || r == EXEY_IDLE)
											&& k < root->rd_nb; k++) {
					index = (count % BLCK_NB) * sizeof(t_blk);
					blk = (t_blk*)&root->map[index];
					pthread_mutex_lock(&((t_nmap_blkhdr *)(blk->map))->mutex);
					if (root->blk_flag[count] == BLK_TODO) {
						if (blk->flag == BLK_BUSY) {
							r = EXEY_BUSY;
						}
						else {
							blk->flag = BLK_BUSY;
							pthread_mutex_unlock(&((t_nmap_blkhdr *)(blk->map))->mutex);
							blk->root = &root->client;
							blk->st = &root->st[i].client;
							blk->nd = &root->nd[j].client;
							blk->rd = &root->rd[k].client;
							blky_branch_task_hooks(blk);
							r = blky(blk);
							pthread_mutex_lock(&((t_nmap_blkhdr *)(blk->map))->mutex);
							if (r == BLKY_OK) {
								root->blk_flag[count] = ((t_nmap_blkhdr *)blk->map)->result;
								r = EXEY_RUN;
							}
							else {
								root->blk_flag[count] = 0;
								r = EXEY_ERR;
							}
							blk->flag = BLK_IDLE;
						}
					}
					else {
						r = EXEY_IDLE;
					}
					pthread_mutex_unlock(&((t_nmap_blkhdr *)(blk->map))->mutex);
					count++;

				}
			}
		}
	}
	return (r);
}
