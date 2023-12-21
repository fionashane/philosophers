/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utility.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:31:59 by fsalimba          #+#    #+#             */
/*   Updated: 2023/12/18 14:31:59 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_finish_eating(t_philo *philo)
{
	ft_usleep(get_time_to_eat(philo->data));
}

bool	is_philo_full(t_data *data, t_philo *philo)
{
	bool	philo_is_full;

	philo_is_full = false;
	if (get_total_meals_eaten(philo) >= data->nbr_meals_until_full)
		philo_is_full = true;
	return (philo_is_full);
}

void	notify_all_philos(t_data *data)
{
	t_philo	*philos;
	int		i;
	int		nbr_philos;

	nbr_philos = get_nbr_philos(data);
	philos = data->philos;
	i = 0;
	while (i < nbr_philos)
	{
		set_philo_state(&philos[i], DEAD);
		i++;
	}
}

bool	was_nbr_meals_specified(t_data *data)
{
	if (data->nbr_meals_until_full > 0)
		return (true);
	return (false);
}
