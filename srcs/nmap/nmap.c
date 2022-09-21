/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:38:40 by adbenoit          #+#    #+#             */
/*   Updated: 2022/09/21 13:47:07 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmap.h"
#include <errno.h>

double	elapse_time(struct timeval *begin, struct timeval *end)
{
	double begin_sec = begin->tv_sec + (double)begin->tv_usec / 1000000;
	double end_sec = end->tv_sec + (double)end->tv_usec / 1000000;

	return (end_sec - begin_sec);
}

static	int	launch_scans(int n, t_root *root)
{
	pthread_t		th[n];
	int64_t			ret = NMAP_OK;
	void			*tmp = NULL;
	int				i;

	for(i = 0; ret == NMAP_OK && i < n; i++) {
		ret = pthread_create(&th[i], NULL, scany, root);
	}
	n = i;
	scany(root);
	ret = NMAP_OK;
	for(i = 0; i < n; i++) {
		pthread_join(th[i], &tmp);
		if ((int64_t)tmp != NMAP_OK) {
			ret = (int64_t)tmp;
		}
	}
	return ((int)ret);
}

int	ft_nmap(t_nmap_controller *controller)
{
	int					ret = NMAP_OK;
	struct timeval		begin, end;
	pthread_t			th_timeout = {0};
	struct sigaction	act;

	act.sa_sigaction = &handle_sigaction;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGALRM, &act, NULL);
	report_config(&controller->root->client);
	blky_init(((t_root *)controller->root)->map);
	if (!(controller->root->client.options & OPT_VERBOSE)) {
		alarm(1);
	}
	ret = pthread_create(&th_timeout, NULL, handle_timeout, controller);
	if (gettimeofday(&begin, NULL) < 0) {
		ret = NMAP_ERROR;
	}
	if (ret == NMAP_OK) {
		errno = 0;
		controller->root->client.time = begin;
		ret = launch_scans(controller->root->client.speedup, controller->root);
		pthread_mutex_lock(&controller->mutex);
		controller->status = NMAP_STOP;
		pthread_mutex_unlock(&controller->mutex);
		if ((char *)th_timeout) {
			pthread_join(th_timeout, NULL);
		}
		alarm(0);
	}
	if (ret != NMAP_OK) {
		dprintf(STDERR_FILENO, "\n");
		perror(NULL);
	}
	else {
		gettimeofday(&end, NULL);
		report_final(controller->root, elapse_time(&begin, &end));
	}
	return (ret);
}
