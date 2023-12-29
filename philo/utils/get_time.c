/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capa <capa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:14:45 by capa              #+#    #+#             */
/*   Updated: 2023/12/29 15:59:56 by capa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/philo.h"

/*in this function we will set a "start" point in or time
and we will continously check the difference between the
current time and "start" with get_current_time() so we can check
how many time has passed*/

int	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
