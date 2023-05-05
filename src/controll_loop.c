/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controll_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:13:41 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/05 18:14:05 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	count_meals(t_data *data)
{
	pthread_mutex_lock(&data->food_eaten);
	if (data->times_to_eat != -1)
		data->philos_eaten++;
	pthread_mutex_unlock(&data->food_eaten);
}

void	controller(t_data *data)
{
	usleep(1000);
	data->start++;
	data->sync = get_time();
	while (data->death != 1)
	{
		if (data->nmb_of_philos % 2 == 0)
			data->regulator = display_time(data) / (data->time_to_eat
					+ data->nmb_of_philos / 50 + 5) % 2;
		else
			data->regulator = display_time(data) / (data->time_to_eat + 6) % 3;
		if (data->total_times_to_eat < data->philos_eaten
			&& data->times_to_eat != -1)
			break ;
	}
	data->murder = 1;
	pthread_mutex_lock(&data->starving);
	if (data->times_to_eat == -1)
		print_state(data, data->corpse_id, DEATH);
	else if (data->total_times_to_eat > data->philos_eaten)
		print_state(data, data->corpse_id, DEATH);
	usleep(1000);
	destroy_stuff2(data, data->nmb_of_philos);
}
