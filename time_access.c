/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_access.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:20:05 by fsalimba          #+#    #+#             */
/*   Updated: 2023/12/18 14:20:05 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	get_time_to_die(t_data *data)
{
	uint64_t	time_to_die;

	pthread_mutex_lock(&data->mutex_die_time);
	time_to_die = data->die_time;
	pthread_mutex_unlock(&data->mutex_die_time);
	return (time_to_die);
}

uint64_t	get_time_to_eat(t_data *data)
{
	uint64_t	time_to_eat;

	pthread_mutex_lock(&data->mutex_eat_time);
	time_to_eat = data->eat_time;
	pthread_mutex_unlock(&data->mutex_eat_time);
	return (time_to_eat);
}

uint64_t	get_time_to_sleep(t_data *data)
{
	uint64_t	time_to_sleep;

	pthread_mutex_lock(&data->mutex_sleep_time);
	time_to_sleep = data->sleep_time;
	pthread_mutex_unlock(&data->mutex_sleep_time);
	return (time_to_sleep);
}

uint64_t	get_start_time(t_data *data)
{
	uint64_t	time;

	pthread_mutex_lock(&data->mutex_start_time);
	time = data->start_time;
	pthread_mutex_unlock(&data->mutex_start_time);
	return (time);
}
