/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:39:16 by gude-cas          #+#    #+#             */
/*   Updated: 2024/01/03 12:23:08 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

t_data	*info(void)
{
	static t_data	info;

	return (&info);
}

void	write_message(t_philo *philo, char *str)
{
	printf("\033[1;2m%d\033[0m \033[1;3m%d\033[0m %s\n", 
		(get_time() - info()->start_time), philo->id, str);
}

int	main(int ac, char **av)
{
	if (check_args(ac, av))
	{
		init_data(av);
		philosophers();
		free(info()->philos->forks);
		free(info()->philos);
	}
}
