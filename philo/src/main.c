/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capa <capa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:32:57 by capa              #+#    #+#             */
/*   Updated: 2023/12/29 16:11:27 by capa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Checking arguments*/
int	main(int ac, char *av[])
{
	t_global_data	data;

	if (ac >= 5 && ac <= 6)
	{
		if (check_args(av, ac))
		{
			printf("ALL INPUTS VALID ✅\n");
			if (data_init(&data, av, ac) == 1)
			{
				free(data.all_philosophers);
				return (0);
			}
			if (philo_init(&data) == -1)
				return (0);
			init_threads(&data);
			free_everything(&data);
		}
	}
	else
		printf("Wrong number of arguments ❌!\n");
}
