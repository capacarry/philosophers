/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capa <capa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:38:11 by capa              #+#    #+#             */
/*   Updated: 2024/01/04 16:22:45 by capa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/philo.h"

int	is_integer(char *str)
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
		printf("Argument must be an int.\n");
		return (0);
	}
	return (1);
}

int	is_positive(char *str)
{
	if (str[0] == '-')
	{
		printf("Argument must be a positive.\n");
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
			printf("Invalid Digit.\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_args(char *args[], int nb_args)
{
	while (--nb_args > 0)
	{
		if (args[1][0] == '0')
			return (0);
		if(args[2][0] == '0')
		{
			printf("\033[1;31m 1 1 died\033[0m\n");
			return(0);
		}
		if (!is_positive(args[nb_args]) || !is_digit(args[nb_args])
			|| !is_integer(args[nb_args]))
			return (0);
	}
	return (1);
}
