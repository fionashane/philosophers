/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initialiser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:05:32 by fsalimba          #+#    #+#             */
/*   Updated: 2023/12/18 14:05:32 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	initialise_data(t_data *data, int ac, char **av)
{
	data->keep_iterating = true;
	data->nbr_philos = ft_atoi(av[1]);
	data->die_time = (uint64_t) ft_atoi(av[2]);
	data->eat_time = (uint64_t) ft_atoi(av[3]);
	data->sleep_time = (uint64_t) ft_atoi(av[4]);
	data->nbr_meals_until_full = -1;
	if (ac == 6)
		data->nbr_meals_until_full = ft_atoi(av[5]);
	pthread_mutex_init(&data->mutex_keep_iterating, NULL);
	pthread_mutex_init(&data->mutex_nbr_philos, NULL);
	pthread_mutex_init(&data->mutex_start_time, NULL);
	pthread_mutex_init(&data->mutex_printf, NULL);
	pthread_mutex_init(&data->mutex_die_time, NULL);
	pthread_mutex_init(&data->mutex_eat_time, NULL);
	pthread_mutex_init(&data->mutex_sleep_time, NULL);
	return (malloc_data(data));
}

int	initialise_philos(t_data *data)
{
	t_philo	*philos;
	int		i;

	philos = data->philos;
	i = 0;
	while (i < data->nbr_philos)
	{
		philos[i].id = i + 1;
		philos[i].total_meals_eaten = 0;
		philos[i].state = IDLE;
		philos[i].data = data;
		pthread_mutex_init(&philos[i].mutex_total_meals_eaten, NULL);
		pthread_mutex_init(&philos[i].mutex_state, NULL);
		pthread_mutex_init(&philos[i].mutex_last_eat_time, NULL);
		set_last_eat_time(&philos[i]);
		i++;
	}
	return (0);
}

int	initialise_forks(t_data *data)
{
	t_philo	*philos;
	int		i;

	philos = data->philos;
	i = 0;
	while (i < data->nbr_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	i = 0;
	philos[0].left_fork = &data->forks[0];
	philos[0].right_fork = &data->forks[data->nbr_philos - 1];
	i++;
	while (i < data->nbr_philos)
	{
		philos[i].left_fork = &data->forks[i];
		philos[i].right_fork = &data->forks[i - 1];
		i++;
	}
	return (0);
}
