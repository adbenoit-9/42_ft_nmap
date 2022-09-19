/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:38:40 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/19 10:36:20 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmap.h"

double	elapse_time(struct timeval *begin, struct timeval *end)
{
	double begin_sec = begin->tv_sec + (double)begin->tv_usec / 1000000;
	double end_sec = end->tv_sec + (double)end->tv_usec / 1000000;

	return (end_sec - begin_sec);
}

static	int	launch_scans(int n, t_root *root)
{
	pthread_t		th[n];
	
	for(int i = 0; i < n; i++) {
		pthread_create(&th[i], NULL, scany, root);
	}
	scany(root);
	for(int i = 0; i < n; i++) {
		pthread_join(th[i], NULL);
	}
	return (0);
}

int	ft_nmap(t_nmap_controller *controller)
{
	struct timeval		begin, end;
	pthread_t			th_timeout;

	signal(SIGALRM, handle_signal);
	report_config(&controller->root->client);
	blky_init(((t_root *)controller->root)->map);
	alarm(1);
	pthread_create(&th_timeout, NULL, handle_timeout, controller);
	gettimeofday(&begin, NULL);
	launch_scans(controller->root->client.speedup, controller->root);
	pthread_mutex_lock(&controller->mutex);
	controller->status = NMAP_STOP;
	pthread_mutex_unlock(&controller->mutex);
	pthread_join(th_timeout, NULL);
	gettimeofday(&end, NULL);
	report_final(controller->root, elapse_time(&begin, &end));
	return (0);
}
