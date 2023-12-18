/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:13:13 by fsalimba          #+#    #+#             */
/*   Updated: 2023/12/18 14:13:13 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_philo_routine(void *philo_p)
{
	t_philo	*philo;

	philo = (t_philo *) philo_p;
	set_last_eat_time(philo);
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->eat_time - 10);
	while (get_philo_state(philo) != DEAD)
	{
		if (start_philo_eat(philo) != 0)
			break ;
		if (get_philo_state(philo) == DEAD)
			break ;
		if (start_philo_sleep(philo) != 0)
			break ;
		if (get_philo_state(philo) == DEAD)
			break ;
		if (start_philo_think(philo) != 0)
			break ;
	}
	return (NULL);
}

void	*check_all_hungry_routine(void *data_p)
{
	t_data	*data;
	int		i;
	int		nbr_philos;

	data = (t_data *)data_p;
	i = 0;
	nbr_philos = get_nbr_philos(data);
	while (i < nbr_philos && get_keep_iterating(data))
	{
		usleep(1000);
		if (is_philo_full(data, &data->philos[i]) == false)
			i = 0;
		i++;
	}
	if (get_keep_iterating(data) == true)
	{
		set_keep_iterating(data, false);
		notify_all_philos(data);
	}
	return (NULL);
}

void	*check_all_alive_routine(void *data_p)
{
	t_data	*data;
	t_philo	*philos;
	int		nbr_philos;
	int		i;

	data = (t_data *)data_p;
	philos = data->philos;
	nbr_philos = get_nbr_philos(data);
	i = -1;
	while (++i < nbr_philos && get_keep_iterating(data))
	{
		if (philo_died(&philos[i]) && get_keep_iterating(data))
		{
			print_message(data, philos[i].id, DIED);
			set_keep_iterating(data, false);
			notify_all_philos(data);
			break ;
		}
		if (i == nbr_philos - 1)
			i = -1;
		usleep(1000);
	}
	return (NULL);
}
