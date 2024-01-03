/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:39:23 by gude-cas          #+#    #+#             */
/*   Updated: 2024/01/03 11:40:56 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	is_positive(char *str)
{
	if (str[0] == '-')
	{
		printf("Argument values must be positive.\n");
		return (0);
	}
	return (1);
}

int	is_int(char *str)
{
	int		i;
	long	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		n = (str[i] - '0') + (n * 10);
		i++;
	}
	if (n > INT_MAX)
	{
		printf("Argument values must be integers.\n");
		return (0);
	}
	return (1);
}

int	is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			printf("Invalid input. (args must contain only digits)\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_args(int ac, char **av)
{
	if (ac == 5 || ac == 6)
	{
		while (--ac > 0)
		{
			if (!is_positive(av[ac]) || !is_digit(av[ac]) || !is_int(av[ac]))
				return (0);
		}
		return (1);
	}
	else
	{
		printf("Invalid number of arguments.\n");
		return (0);
	}
}
