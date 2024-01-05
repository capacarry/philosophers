/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_and_mutex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:10:20 by capa              #+#    #+#             */
/*   Updated: 2024/01/05 16:36:36 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/philo.h"

void	ft_usleep(int time, t_philo *philo)
{
	int	start;

	start = get_time();
	(void)philo;
	while ((get_time() - start) < time)
	{
		if (grim_reaper(philo))
			return ;
		usleep(50);
	}
}

void	drop_forks(t_philo *philo, int fork_id)
{
	while (!grim_reaper(philo))
	{
		pthread_mutex_lock(&philo->forks[fork_id].fork_mutex);
		if (philo->forks[fork_id].is_in_table == false)
		{
			philo->forks[fork_id].is_in_table = true;
			pthread_mutex_unlock(&philo->forks[fork_id].fork_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->forks[fork_id].fork_mutex);
	}
}

void	take_fork(t_philo *philo, int fork_id)
{
	while (!grim_reaper(philo) && !is_dead(philo))
	{
		pthread_mutex_lock(&philo->forks[fork_id].fork_mutex);
		if (philo->forks[fork_id].is_in_table == true)
		{
			philo->forks[fork_id].is_in_table = false;
			write_status(TAKE_LEFT_FORK, philo);
			pthread_mutex_unlock(&philo->forks[fork_id].fork_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->forks[fork_id].fork_mutex);
	}
}

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->death_mutex);
	if (philo->is_dead == true)
	{
		pthread_mutex_unlock(&philo->data->death_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->death_mutex);
	return (0);
}

void	mutex_control(t_mutex *mutex, t_opcode opcode)
{
	if (LOCK == opcode)
		pthread_mutex_lock(mutex);
	else if (UNLOCK == opcode)
		pthread_mutex_unlock(mutex);
	else if (INIT == opcode)
		pthread_mutex_init(mutex, NULL);
	else if (DESTROY == opcode)
		pthread_mutex_destroy(mutex);
	else
		printf("Wrong opcode for mutex handle❌");
}
