/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capa <capa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:58:39 by capa              #+#    #+#             */
/*   Updated: 2024/01/05 15:56:22 by capa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/philo.h"

/*This is simply an output function to display what the philo is doing.
We use our "t_mutex write_mutex" to prevent other threads from reaching
this function, creating data races*/
void	write_status(t_status what_he_doing, t_philo *philo)
{
	long	passed;

	pthread_mutex_lock(&philo->data->write_mutex);
	passed = get_time() - philo->data->t_start_of_program;
	if ((what_he_doing == TAKE_LEFT_FORK || what_he_doing == TAKE_RIGHT_FORK)
		&& !philo->data->end_program)
		printf("%lu %d has taken a fork\n", passed, philo->phil_id);
	else if (what_he_doing == EATING && !philo->data->end_program)
		printf("\033[1;32m%lu %d is eating\033[0m\n", passed, philo->phil_id);
	else if (what_he_doing == SLEEPING && !philo->data->end_program)
		printf("\033[1;34m%lu %d is sleeping\033[0m\n", passed, philo->phil_id);
	else if (what_he_doing == THINKING && !philo->data->end_program)
		printf("%lu %d is thinking\n", passed, philo->phil_id);
	else if (what_he_doing == DIED && !philo->data->end_program)
		printf("\033[1;31m%lu %d died\033[0m\n", passed, philo->phil_id);
	if (what_he_doing == DIED)
		philo->data->end_program = true;
	pthread_mutex_unlock(&philo->data->write_mutex);
}

int	ft_abs(int num)
{
	if (num < 0)
	{
		return (-num);
	}
	else
	{
		return (num);
	}
}
