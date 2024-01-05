/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_everything.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capa <capa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:14:35 by capa              #+#    #+#             */
/*   Updated: 2024/01/05 17:24:20 by capa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/philo.h"

void	free_everything(t_global_data *data)
{
	int	i;

	i = -1;
	if (data->all_philosophers->forks)
	{
		while (++i < data->philo_nb)
		{
			pthread_mutex_destroy(&data->all_philosophers[i].forks->fork_mutex);
		}
	}
	free(data->all_philosophers->forks);
	pthread_mutex_destroy(&data->death_mutex);
	pthread_mutex_destroy(&data->write_mutex);
	free(data->all_philosophers);
}
