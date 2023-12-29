/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capa <capa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:53:41 by gcapa-pe          #+#    #+#             */
/*   Updated: 2023/12/29 16:22:06 by capa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*LIBRARIES 📖*/
# include <errno.h>
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define WHITE "\e[0m"
# define RED "\e[31m"
# define GREEN "\e[32m"

typedef pthread_mutex_t			t_mutex;
typedef struct s_global_data	t_global_data;
/*STRUCTS*/
typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_LEFT_FORK,
	TAKE_RIGHT_FORK,
	DIED,
}								t_status;

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}								t_opcode;

typedef struct s_fork
{
	t_mutex						fork_mutex;
	bool						is_in_table;
}								t_fork;

/*philosopher struct 🤔*/
typedef struct s_philo
{
	int							phil_id;
	int							meals_consumed;
	bool						philo_full;
	bool						is_dead;
	int							time_till_death;
	pthread_t					phil_thread;
	long int					last_meal;
	t_mutex						philo_lock;
	t_global_data				*data;
	t_fork						*forks;

}								t_philo;
/* global data for entirety of program 🌐 */
typedef struct s_global_data
{
	int							philo_nb;
	int							limit_of_meals;
	int							time_to_die;
	int							time_to_eat;
	int							time_to_sleep;
	int							t_start_of_program;
	bool						end_program;
	bool						philo_is_eating;
	pthread_t					soul_taker;
	t_mutex						death_mutex;
	t_mutex						write_mutex;
	t_philo						*all_philosophers;
}								t_global_data;
/*UTILS 🛠️*/
int								ft_atoi(const char *nptr);
int								check_args(char *args[], int nb_args);
void							ft_usleep(int time, t_philo *philo);
int								get_time(void);
/*DATA MANAGEMENT 🔠*/
void							free_everything(t_global_data *data);
void							init_threads(t_global_data *data);
t_fork							*init_forks(t_global_data *data);
void							drop_forks(t_philo *philo, int fork_id);
int								philo_init(t_global_data *data);
int								data_init(t_global_data *data, char *av[],
									int ac);
void							mutex_control(t_mutex *mutex, t_opcode opcode);
/*SIMULATION */
void							eat(t_philo *philo);
int								grim_reaper(t_philo *philo);
void							take_fork(t_philo *philo, int fork_id);
void							drop_forks(t_philo *philo, int fork_id);
void							write_status(t_status what_he_doing,
									t_philo *philo);
void							*dinner_start(void *philo);
int								is_dead(t_philo *philo);

#endif
