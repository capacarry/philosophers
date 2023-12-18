/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcapa-pe <gcapa-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:20:40 by gcapa-pe          #+#    #+#             */
/*   Updated: 2023/12/18 13:35:34 by gcapa-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_philo(t_global_data *data)
{   
    int i = 1;

    data->all_philosophers = malloc(data->philo_nb);
    if(!data->all_philosophers)
	{
		printf("Error on malloc");
	}

}