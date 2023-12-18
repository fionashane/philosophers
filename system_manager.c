/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:03:22 by fsalimba          #+#    #+#             */
/*   Updated: 2023/12/18 14:03:22 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	if (check_arguments(ac, av) != 0)
		return (print_error("Invalid Input\n"));
	if (run_philo(ac, av) != 0)
		return (print_error("Memory Allocation Error\n"));
	return (0);
}

int	run_philo(int ac, char **av)
{
	t_data	data;

	if (initialise_data(&data, ac, av) != 0)
		return (print_error("Memory Allocation Error\n"));
	if (initialise_philos(&data) != 0)
		return (print_error("Philos Initialisation Error\n"));
	if (initialise_forks(&data) != 0)
		return (print_error("Forks Initialisation Error\n"));
	if (start_threads(&data) != 0)
		return (print_error("Start Threads Error\n"));
	if (join_threads(&data) != 0)
		return (print_error("Join Threads Error\n"));
	free_data(&data);
	return (0);
}

int	start_threads(t_data *data)
{
	int	nbr_philosophers;
	int	i;

	nbr_philosophers = get_nbr_philos(data);
	i = 0;
	data->start_time = get_current_time();
	while (i < nbr_philosophers)
	{
		if (pthread_create(&data->philo_threads[i], NULL,
				&start_philo_routine, &data->philos[i]))
			return (1);
		i++;
	}
	if (pthread_create(&data->monitor_all_alive_thread, NULL,
			&check_all_alive_routine, data))
		return (1);
	if (was_nbr_meals_specified(data) == true
		&& pthread_create(&data->monitor_all_hungry_thread, NULL,
			&check_all_hungry_routine, data))
		return (1);
	return (0);
}

int	join_threads(t_data *data)
{
	int	i;
	int	nbr_of_philos;

	nbr_of_philos = get_nbr_philos(data);
	if (pthread_join(data->monitor_all_alive_thread, NULL))
		return (1);
	if (was_nbr_meals_specified(data) == true
		&& pthread_join(data->monitor_all_hungry_thread, NULL))
		return (1);
	i = 0;
	while (i < nbr_of_philos)
	{
		if (pthread_join(data->philo_threads[i], NULL))
			return (1);
		i++;
	}
	return (0);
}
