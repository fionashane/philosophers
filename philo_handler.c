/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:16:33 by fsalimba          #+#    #+#             */
/*   Updated: 2023/12/18 14:16:33 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_philo_eat(t_philo *philo)
{
	if (take_both_forks(philo) != 0)
		return (1);
	set_philo_state(philo, EATING);
	print_message(philo->data, philo->id, EAT);
	set_last_eat_time(philo);
	wait_finish_eating(philo);
	drop_both_forks(philo);
	set_total_meals_eaten(philo);
	return (0);
}

int	start_philo_sleep(t_philo *philo)
{
	set_philo_state(philo, SLEEPING);
	if (get_philo_state(philo) == DEAD)
		return (1);
	print_message(philo->data, philo->id, SLEEP);
	ft_usleep(get_time_to_sleep(philo->data));
	return (0);
}

int	start_philo_think(t_philo *philo)
{
	set_philo_state(philo, THINKING);
	if (get_philo_state(philo) == DEAD)
		return (1);
	print_message(philo->data, philo->id, THINK);
	return (0);
}

int	handle_one_philo(t_philo *philo)
{
	take_left_fork(philo);
	ft_usleep(get_time_to_die(philo->data));
	set_philo_state(philo, DEAD);
	return (1);
}

bool	philo_died(t_philo *philo)
{
	bool		result;
	t_data		*data;

	data = philo->data;
	result = false;
	if (get_current_time() - get_last_eat_time(philo) > get_time_to_die(data)
		&& get_philo_state(philo) != EATING)
	{
		set_philo_state(philo, DEAD);
		result = true;
	}
	return (result);
}
