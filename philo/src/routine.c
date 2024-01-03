/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:39:33 by gude-cas          #+#    #+#             */
/*   Updated: 2024/01/03 12:04:30 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	philo_eat(t_philo *philo)
{
	int	left_fork;
	int	right_fork;

	left_fork = philo->id - 1;
	right_fork = (philo->id) % info()->number_of_philos;
	take_fork(philo, left_fork);
	take_fork(philo, right_fork);
	if (check_death())
		return ;
	philo->last_meal = get_time();
	write_message(philo, "\033[1;32mis eating\033[0m");
	sleeper(philo, info()->time_to_eat);
	philo->number_of_meals++;
	put_forks(philo, right_fork);
	put_forks(philo, left_fork);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 != 0 && philo->number_of_meals != info()->total_meals)
	{
		write_message(philo, "\033[1;34mis thinking\033[0m");
		sleeper(philo, 10);
	}
	while (!philo_starved(philo)
		&& philo->number_of_meals != info()->total_meals)
	{
		philo_eat(philo);
		if (check_death())
			break ;
		write_message(philo, "\033[1;33mis sleeping\033[0m");
		sleeper(philo, info()->time_to_sleep);
		if (check_death())
			break ;
		write_message(philo, "\033[1;34mis thinking\033[0m");
	}
	return (NULL);
}
