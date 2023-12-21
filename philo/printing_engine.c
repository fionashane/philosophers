/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_engine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:18:42 by fsalimba          #+#    #+#             */
/*   Updated: 2023/12/18 14:18:42 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(t_data *data, int id, char *message)
{
	uint64_t	time;

	time = get_current_time() - get_start_time(data);
	pthread_mutex_lock(&data->mutex_printf);
	if (get_keep_iterating(data))
		printf("%llu %d %s\n", time, id, message);
	pthread_mutex_unlock(&data->mutex_printf);
}

int	print_error(char *error_message)
{
	printf("%s\n", error_message);
	return (1);
}
