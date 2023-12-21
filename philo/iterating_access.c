/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterating_access.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:29:22 by fsalimba          #+#    #+#             */
/*   Updated: 2023/12/18 14:29:22 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	get_keep_iterating(t_data *data)
{
	bool	keep_iterating;

	pthread_mutex_lock(&data->mutex_keep_iterating);
	keep_iterating = data->keep_iterating;
	pthread_mutex_unlock(&data->mutex_keep_iterating);
	return (keep_iterating);
}

void	set_keep_iterating(t_data *data, bool value)
{
	pthread_mutex_lock(&data->mutex_keep_iterating);
	data->keep_iterating = value;
	pthread_mutex_unlock(&data->mutex_keep_iterating);
}

uint64_t	get_last_eat_time(t_philo *philo)
{
	uint64_t	last_eat_time;

	pthread_mutex_lock(&philo->mutex_last_eat_time);
	last_eat_time = philo->last_eat_time;
	pthread_mutex_unlock(&philo->mutex_last_eat_time);
	return (last_eat_time);
}

void	set_last_eat_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex_last_eat_time);
	philo->last_eat_time = get_current_time();
	pthread_mutex_unlock(&philo->mutex_last_eat_time);
}
