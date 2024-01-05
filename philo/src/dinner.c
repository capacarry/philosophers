/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capa <capa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:23:18 by capa              #+#    #+#             */
/*   Updated: 2024/01/05 15:58:01 by capa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*In this file, we enter the working function for the "phthread_create()"
(dinner_start()) , that is linked to our threads of philosophers.
We proceed by making the philosophers eat, sleep and think. Dividing the
time in wich they do each task by if they are even or odd numbers.
The function "grim_reaper()" serves, has the name implies, to kill our
philospher if the time to day has been surpassed or if he has eaten "limit_of_meals.
While the func "grim_reaper(), hasnt found a dead philo, we proceed with the
"eat()"" routine by locking our forks(mutex), eating using "ft_usleep()", and
then unlocking the forks when the variable "time_to_eat" has been reached.*/
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
	if (thinker->phil_id % 2 == 0)
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
