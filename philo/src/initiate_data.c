/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capa <capa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:36:24 by capa              #+#    #+#             */
/*   Updated: 2023/12/29 16:12:36 by capa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_threads(t_global_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nb)
	{
		pthread_create(&data->all_philosophers[i].phil_thread, NULL,
			&dinner_start, &data->all_philosophers[i]);
		i++;
	}
	i = 0;
	while (i < data->philo_nb)
	{
		pthread_join(data->all_philosophers[i].phil_thread, NULL);
		i++;
	}
}

t_fork	*init_forks(t_global_data *data)
{
	int		i;
	t_fork	*forks;

	i = 0;
	forks = malloc(sizeof(t_fork) * data->philo_nb);
	while (i < data->philo_nb)
	{
		forks[i].is_in_table = 1;
		pthread_mutex_init(&forks[i].fork_mutex, NULL);
		i++;
	}
	return (forks);
}

int	philo_init(t_global_data *data)
{
	int		i;
	t_fork	*forks;

	i = -1;
	data->all_philosophers = malloc(sizeof(t_philo) * data->philo_nb);
	forks = init_forks(data);
	while (++i < data->philo_nb)
	{
		data->all_philosophers[i].phil_id = i + 1;
		data->all_philosophers[i].philo_full = false;
		data->all_philosophers[i].is_dead = false;
		data->all_philosophers[i].forks = forks;
		data->all_philosophers[i].meals_consumed = 0;
		data->all_philosophers[i].data = data;
		data->all_philosophers[i].last_meal = get_time();
	}
	return (0);
}

int	data_init(t_global_data *data, char *av[], int ac)
{
	(void)ac;
	pthread_mutex_init(&data->death_mutex, NULL);
	pthread_mutex_init(&data->write_mutex, NULL);
	data->end_program = false;
	data->philo_nb = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->t_start_of_program = get_time();
	if (data->all_philosophers == NULL)
		return (2);
	if (av[5])
		data->limit_of_meals = ft_atoi(av[5]);
	else
		data->limit_of_meals = INT_MAX;
	return (0);
}
