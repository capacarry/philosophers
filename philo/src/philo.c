/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcapa-pe <gcapa-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:02:16 by gcapa-pe          #+#    #+#             */
/*   Updated: 2023/12/07 14:52:48 by gcapa-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Populating every element of my struct with my args
ex: 5 800 200 200 7*/

void data_init(t_global_data *data)
{
	data->end_program = false;
	data->all_philosophers = malloc(data->philo_nb);
	if(!data->all_philosophers)
	{
		printf("Error on malloc");
		exit(1);
	}
	
		
}

/*Checking arguments*/
int main (int ac, char *av[])
{	
	t_global_data data;

	if(ac >= 5 && ac <= 6)
	{	
		
		if(parsing(av,ac))
		{
			printf("All inputs valid ✅\n");
			data_init(&data);
			program_start(&data);
			free_everything(&data);
		}
	}
	else
		printf("Wrong number of arguments ❌!\n");
}