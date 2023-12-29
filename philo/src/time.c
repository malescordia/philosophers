/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:44:01 by gude-cas          #+#    #+#             */
/*   Updated: 2023/12/29 17:08:23 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	sleeper(t_philo *philo, int time)
{
	int	start;

	start = get_time();
	(void)philo;
	while ((get_time() - start) < time)
	{
		if (philo_starved(philo))
			return ;
		usleep(500);
	}
}
