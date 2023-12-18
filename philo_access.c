/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:23:34 by fsalimba          #+#    #+#             */
/*   Updated: 2023/12/18 14:23:34 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_state	get_philo_state(t_philo *philo)
{
	t_state	current_state;

	pthread_mutex_lock(&philo->mutex_state);
	current_state = philo->state;
	pthread_mutex_unlock(&philo->mutex_state);
	return (current_state);
}

void	set_philo_state(t_philo *philo, t_state state)
{
	pthread_mutex_lock(&philo->mutex_state);
	if (philo->state != DEAD)
		philo->state = state;
	pthread_mutex_unlock(&philo->mutex_state);
}

int	get_nbr_philos(t_data *data)
{
	int	number_of_philos;

	pthread_mutex_lock(&data->mutex_nbr_philos);
	number_of_philos = data->nbr_philos;
	pthread_mutex_unlock(&data->mutex_nbr_philos);
	return (number_of_philos);
}

int	get_total_meals_eaten(t_philo *philo)
{
	int	total_meals_eaten;

	pthread_mutex_lock(&philo->mutex_total_meals_eaten);
	total_meals_eaten = philo->total_meals_eaten;
	pthread_mutex_unlock(&philo->mutex_total_meals_eaten);
	return (total_meals_eaten);
}

void	set_total_meals_eaten(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex_total_meals_eaten);
	philo->total_meals_eaten++;
	pthread_mutex_unlock(&philo->mutex_total_meals_eaten);
}
