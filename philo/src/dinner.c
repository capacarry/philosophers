/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcapa-pe <gcapa-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:23:18 by capa              #+#    #+#             */
/*   Updated: 2024/01/06 17:37:55 by gcapa-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	int	left_fork;
	int	right_fork;

	left_fork = philo->phil_id - 1;
	right_fork = (philo->phil_id) % philo->data->philo_nb;
	take_fork(philo, left_fork);
	take_fork(philo, right_fork);
	if (is_dead(philo))
		return ;
	philo->last_meal = get_time();
	write_status(EATING, philo);
	ft_usleep(philo->data->time_to_eat, philo);
	philo->meals_consumed++;
	drop_forks(philo, right_fork);
	drop_forks(philo, left_fork);
}

int	grim_reaper(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->death_mutex);
	if (get_time() - philo->last_meal >= philo->data->time_to_die)
	{
		if (philo->is_dead == false)
		{
			write_status(DIED, philo);
			philo->is_dead = true;
			pthread_mutex_unlock(&philo->data->death_mutex);
			return (1);
		}
	}
	pthread_mutex_unlock(&philo->data->death_mutex);
	return (0);
}

void	*dinner_start(void *philo)
{
	t_philo	*thinker;

	thinker = (t_philo *)philo;
	if (thinker->phil_id % 2 == 0 
		&& thinker->data->limit_of_meals != thinker->meals_consumed)
	{
		write_status(THINKING, thinker);
		ft_usleep(10, thinker);
	}
	while (!grim_reaper(thinker)
		&& (thinker->meals_consumed != thinker->data->limit_of_meals)
		&& !thinker->data->end_program)
	{
		eat(thinker);
		if (is_dead(thinker))
			break ;
		write_status(SLEEPING, thinker);
		ft_usleep(thinker->data->time_to_sleep, thinker);
		if (is_dead(thinker))
			break ;
		write_status(THINKING, thinker);
		ft_usleep(ft_abs(thinker->data->time_to_eat
				- thinker->data->time_to_sleep), thinker);
	}
	return (NULL);
}
