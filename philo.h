/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:02:57 by fsalimba          #+#    #+#             */
/*   Updated: 2023/12/19 10:51:44 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <stdint.h>
# include <stdbool.h>

typedef enum e_philo_state
{
	IDLE = 0,
	DEAD = 1,
	EATING = 2,
	SLEEPING = 3,
	THINKING = 4,
	FULL = 5
}	t_state;

struct	s_data;

typedef struct s_philo
{
	int				id;
	int				total_meals_eaten;
	t_state			state;
	uint64_t		last_eat_time;
	struct s_data	*data;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	mutex_state;
	pthread_mutex_t	mutex_total_meals_eaten;
	pthread_mutex_t	mutex_last_eat_time;
}t_philo;

typedef struct s_data
{
	int				nbr_philos;
	int				nbr_meals_until_full;
	bool			keep_iterating;
	t_philo			*philos;
	uint64_t		die_time;
	uint64_t		eat_time;
	uint64_t		sleep_time;
	uint64_t		start_time;
	pthread_t		*philo_threads;
	pthread_t		monitor_all_alive_thread;
	pthread_t		monitor_all_hungry_thread;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mutex_keep_iterating;
	pthread_mutex_t	mutex_nbr_philos;
	pthread_mutex_t	mutex_start_time;
	pthread_mutex_t	mutex_printf;
	pthread_mutex_t	mutex_die_time;
	pthread_mutex_t	mutex_eat_time;
	pthread_mutex_t	mutex_sleep_time;
}t_data;

// system_manager.c
int			run_philo(int argc, char **argv);
int			start_threads(t_data *data);
int			join_threads(t_data *data);

// argument_checker.c
int			check_arguments(int argc, char **argv);
int			check_valid_characters(int ac, char **av);
int			check_input_range(int argc, char **argv);
int			ft_atoi(char *str);

// data_initialiser.c
int			initialise_data(t_data *data, int argc, char **argv);
int			initialise_philos(t_data *data);
int			initialise_forks(t_data *data);

// time_handler.c
uint64_t	get_current_time(void);
void		ft_usleep(uint64_t time);

// routine_handler.c
void		*start_philo_routine(void *philo_p);
void		*check_all_hungry_routine(void *data_p);
void		*check_all_alive_routine(void *data_p);

// philo_handler.c
int			start_philo_eat(t_philo *philo);
int			start_philo_sleep(t_philo *philo);
int			start_philo_think(t_philo *philo);
int			handle_one_philo(t_philo *philo);
bool		philo_died(t_philo *philo);

// printing_engine.c
void		print_message(t_data *data, int id, char *message);
int			print_error(char *error_message);

// time_access.c
uint64_t	get_time_to_die(t_data *data);
uint64_t	get_time_to_eat(t_data *data);
uint64_t	get_time_to_sleep(t_data *data);
uint64_t	get_start_time(t_data *data);

// philo_access.c
t_state		get_philo_state(t_philo *philo);
void		set_philo_state(t_philo *philo, t_state state);
int			get_nbr_philos(t_data *data);
int			get_total_meals_eaten(t_philo *philo);
void		set_total_meals_eaten(t_philo *philo);

// fork_access.c
int			take_both_forks(t_philo *philo);
int			take_right_fork(t_philo *philo);
int			take_left_fork(t_philo *philo);
void		drop_right_fork(t_philo *philo);
void		drop_both_forks(t_philo *philo);

// iterating_access.c
bool		get_keep_iterating(t_data *data);
void		set_keep_iterating(t_data *data, bool value);
uint64_t	get_last_eat_time(t_philo *philo);
void		set_last_eat_time(t_philo *philo);

// data_access.c
int			malloc_data(t_data *data);
void		free_data(t_data *data);

// philo_utility.c
void		wait_finish_eating(t_philo *philo);
bool		is_philo_full(t_data *data, t_philo *philo);
void		notify_all_philos(t_data *data);
bool		was_nbr_meals_specified(t_data *data);

#endif