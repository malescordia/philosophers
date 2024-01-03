/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:38:38 by gude-cas          #+#    #+#             */
/*   Updated: 2024/01/03 12:23:24 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_fork
{
	int				fork_on_table;
	pthread_mutex_t	fork_mutex;
}					t_fork;

typedef struct s_philo
{
	int				id;
	int				last_meal;
	int				number_of_meals;
	pthread_t		philo;
	t_fork			*forks;
}					t_philo;

typedef struct s_data
{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				total_meals;
	int				start_time;
	int				dead_flag;
	pthread_mutex_t	death_mutex;
	t_philo			*philos;
}					t_data;

t_data				*info(void);
void				write_message(t_philo *philo, char *str);
int					check_args(int ac, char **av);
void				init_data(char **av);
void				philosophers(void);
void				*routine(void *arg);
int					philo_starved(t_philo *philo);
int					check_death(void);
int					ascii_to_int(char *str);
void				put_forks(t_philo *philo, int fork_id);
void				take_fork(t_philo *philo, int fork_id);
int					get_time(void);
void				sleeper(t_philo *philo, int time);

#endif
