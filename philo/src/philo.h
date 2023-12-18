/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcapa-pe <gcapa-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:53:41 by gcapa-pe          #+#    #+#             */
/*   Updated: 2023/12/18 13:35:34 by gcapa-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

/*LIBRARIES 📖*/ 
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
#include <errno.h>

//mutex redifinition so its easier to read the code; 
typedef pthread_mutex_t t_mutex;
// reminder of existence of this struct to compiler.
typedef struct s_global_data t_global_data;
/*STRUCTS*/
//
//OPCODE for mutex ( representation for mutex operations through an array of ints)
typedef enum  e_opcode
{
	LOCK,  // 0
	UNLOCK,  // 1
	INIT,    // 2
	DESTROY,  // 3
	CREATE,  // 4
	JOIN,  // 5
	DETACH, // 6
	
}     t_opcode;

//
/*fork struct 🍴*/
typedef struct s_fork
{	
	t_mutex fork;
	int fork_id;
	
}				t_fork;
//
//
/*philosopher struct 🤔*/
typedef struct s_philo
{
	pthread_t	thread_id;
	int			phil_id; // id of the corresponding philo;
	long		meals_consumed; // number of meals that the philo has eaten
	bool		philo_full;// philo as reached number of meals;
	bool		philo_dead; // philo is dead 💀
	long		last_meal_time; // time passed since last meal;
	t_fork		*left_fork;
	t_fork		*right_fork;
	
}				t_philo;
//
/* global data for entirety of program 🌐 */
typedef struct 			s_global_data
{	
	long 	philo_nb; // number of philos
	long 	time_to_die;
	long 	time_to_eat;
	long 	time_to_sleep;
	long 	limit_of_meals;
	long	start_of_program;// timestamp of start of program 🕐
	bool 	end_program; // one philo dies or all philos are full 💀
	t_fork 	*all_forks; //array to all the forks [🍴,🍴,🍴,🍴,🍴]
	t_philo *all_philosophers;// array to all philosophers  [🤔,🤔,🤔,🤔,🤔]
}				t_global_data;
//
//
//
/*UTILS 🛠️*/ 
int				ft_atoi(const char *nptr);
int				parsing(char *args[], int nb_args);
//
/*DATA MANAGEMENT 🔠*/
void data_init(t_global_data *data, char *av[])
void mutex_init(t_mutex *mutex, t_opcode opcode);
#endif