/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:39:46 by gude-cas          #+#    #+#             */
/*   Updated: 2023/12/29 18:29:34 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	ascii_to_int(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		n = (str[i] - '0') + (n * 10);
		i++;
	}
	return (n);
}

void	put_forks(t_philo *philo, int fork_id)
{
	while (!philo_starved(philo) && !check_death())
	{
		pthread_mutex_lock(&philo->forks[fork_id].fork_mutex);
		if (philo->forks[fork_id].fork_on_table == 0)
		{
			philo->forks[fork_id].fork_on_table = 1;
			pthread_mutex_unlock(&philo->forks[fork_id].fork_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->forks[fork_id].fork_mutex);
	}
}

void	take_fork(t_philo *philo, int fork_id)
{
	while (!philo_starved(philo) && !check_death())
	{
		pthread_mutex_lock(&philo->forks[fork_id].fork_mutex);
		if (philo->forks[fork_id].fork_on_table == 1)
		{
			philo->forks[fork_id].fork_on_table = 0;
			write_message(philo, "\033[1;36mhas taken a fork\033[0m");
			pthread_mutex_unlock(&philo->forks[fork_id].fork_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->forks[fork_id].fork_mutex);
	}
}

int	philo_starved(t_philo *philo)
{
	pthread_mutex_lock(&info()->death_mutex);
	if (get_time() - philo->last_meal >= info()->time_to_die)
	{
		if (info()->dead_flag == 0)
		{
			write_message(philo, "\033[1;31mdied\033[0m");
			info()->dead_flag = 1;
			pthread_mutex_unlock(&info()->death_mutex);
			return (1);
		}
	}
	pthread_mutex_unlock(&info()->death_mutex);
	return (0);
}

int	check_death(void)
{
	pthread_mutex_lock(&info()->death_mutex);
	if (info()->dead_flag)
	{
		pthread_mutex_unlock(&info()->death_mutex);
		return (1);
	}
	pthread_mutex_unlock(&info()->death_mutex);
	return (0);
}
