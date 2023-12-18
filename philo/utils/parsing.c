/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcapa-pe <gcapa-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:23:22 by gcapa-pe          #+#    #+#             */
/*   Updated: 2023/12/05 13:21:11 by gcapa-pe         ###   ########.fr       */
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
			printf("Write fucking digit bitch.\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	parsing(char *args[], int nb_args)
{
	while (--nb_args > 0)
	{
		if (!is_positive(args[nb_args]) || !is_digit(args[nb_args])
			|| !is_integer(args[nb_args]))
			return (0);
	}
	return (1);
}