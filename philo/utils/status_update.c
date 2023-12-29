/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capa <capa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:58:39 by capa              #+#    #+#             */
/*   Updated: 2023/12/29 16:13:45 by capa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/philo.h"

void	write_status(t_status what_he_doing, t_philo *philo)
{
	long	passed;

	mutex_control(&philo->data->write_mutex, LOCK);
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
	mutex_control(&philo->data->write_mutex, UNLOCK);
}
