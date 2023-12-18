/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_access.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:30:49 by fsalimba          #+#    #+#             */
/*   Updated: 2023/12/18 14:30:49 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	malloc_data(t_data *data)
{
	data->philos = malloc(sizeof(t_philo) * data->nbr_philos);
	if (!(data->philos))
		return (1);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nbr_philos);
	if (!(data->forks))
		return (free(data->philos), 1);
	data->philo_threads = malloc(sizeof(pthread_t) * data->nbr_philos);
	if (!(data->philo_threads))
		return (free(data->philos), free(data->forks), 1);
	return (0);
}

void	free_data(t_data *data)
{
	int	i;
	int	nbr_of_philos;

	nbr_of_philos = get_nbr_philos(data);
	i = 0;
	while (i < nbr_of_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].mutex_state);
		pthread_mutex_destroy(&data->philos[i].mutex_total_meals_eaten);
		pthread_mutex_destroy(&data->philos[i].mutex_last_eat_time);
		i++;
	}
	pthread_mutex_destroy(&data->mutex_die_time);
	pthread_mutex_destroy(&data->mutex_eat_time);
	pthread_mutex_destroy(&data->mutex_sleep_time);
	pthread_mutex_destroy(&data->mutex_nbr_philos);
	pthread_mutex_destroy(&data->mutex_printf);
	pthread_mutex_destroy(&data->mutex_keep_iterating);
	pthread_mutex_destroy(&data->mutex_start_time);
	free(data->philo_threads);
	free(data->philos);
	free(data->forks);
}
