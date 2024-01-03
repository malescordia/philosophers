/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:39:05 by gude-cas          #+#    #+#             */
/*   Updated: 2024/01/03 12:23:17 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	philosophers(void)
{
	int	i;

	i = 0;
	while (i < info()->number_of_philos)
	{
		pthread_create(&info()->philos[i].philo, NULL, &routine,
			&info()->philos[i]);
		i++;
	}
	i = 0;
	while (i < info()->number_of_philos)
	{
		pthread_join(info()->philos[i].philo, NULL);
		i++;
	}
}

t_fork	*init_forks(void)
{
	int		i;
	t_fork	*forks;

	i = 0;
	forks = malloc(sizeof(t_fork) * info()->number_of_philos);
	while (i < info()->number_of_philos)
	{
		forks[i].fork_on_table = 1;
		pthread_mutex_init(&forks[i].fork_mutex, NULL);
		i++;
	}
	return (forks);
}

void	init_philos(void)
{
	int		i;
	t_fork	*forks;

	i = 0;
	info()->philos = malloc(sizeof(t_philo) * info()->number_of_philos);
	forks = init_forks();
	while (i < info()->number_of_philos)
	{
		info()->philos[i].forks = forks;
		info()->philos[i].id = i + 1;
		info()->philos[i].number_of_meals = 0;
		info()->philos[i].last_meal = get_time();
		i++;
	}
}

void	init_data(char **av)
{
	info()->number_of_philos = ascii_to_int(av[1]);
	info()->time_to_die = ascii_to_int(av[2]);
	info()->time_to_eat = ascii_to_int(av[3]);
	info()->time_to_sleep = ascii_to_int(av[4]);
	if (av[5])
		info()->total_meals = ascii_to_int(av[5]);
	else
		info()->total_meals = INT_MAX;
	info()->start_time = get_time();
	info()->dead_flag = 0;
	pthread_mutex_init(&info()->death_mutex, NULL);
	init_philos();
}
