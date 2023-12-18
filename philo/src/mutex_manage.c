/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcapa-pe <gcapa-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:55:27 by gcapa-pe          #+#    #+#             */
/*   Updated: 2023/12/07 17:37:18 by gcapa-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Having discovered OPCODES(array of ints you create on header file, starting from 0 
that each number represent something you pass to it, check header file),
I can now use them in my program to facilitate function calling and management*/
/*I will now make a MUTEX function that will handle all my operations within MUTEX
LOCK, UNLOCK, INIT, DESTROY, CREATE, JOIN, DETACH. Ill also implement a error
management func to make debbuging more precise*/

void  error_mutex_handle(int status, t_opcode opcode)
{	
	if(status == 0)
	{
		if(status == EINVAL && (opcode == LOCK|| opcode == UNLOCK) )
		{
				printf("The value specified by mutex is invalid");
				exit(1);
		}
		else if(status == INIT  && opcode == EINVAL)
		{
				printf("The value specified by mutex is invalid");
				exit(1);
		}
		else if (status == EDEADLK)
		{
				printf("A deadlock would accur if the thread blocked waiting for mutex");
				exit(1);
		}
		else if (status == EPERM)
		{
			printf("The current thread does not hold a lock on mutex");
				exit(1);
		}
		else if (status == ENOMEM)
		{
			printf("The process cannot allocate enough memory to create another mutex");
				exit(1);
		}
		else if (status == EBUSY)
		{
			printf("Mutex is already locked");
			exit(1);
		}
	}
}

 
void 	mutex_init(t_mutex *mutex, t_opcode opcode)
{
	if(LOCK == opcode)
		error_mutex_handle(pthread_mutex_lock(mutex),opcode);
	else if(UNLOCK == opcode)
		error_mutex_handle(pthread_mutex_unlock(mutex),opcode);
	else if(INIT == opcode)
		error_mutex_handle(pthread_mutex_init(mutex,NULL),opcode);
	else if(DESTROY == opcode)
		error_mutex_handle(pthread_mutex_destroy(mutex),opcode);
	else
		printf("Wrong opcode for mutex handle❌");
}		
