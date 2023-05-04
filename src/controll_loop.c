/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controll_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:13:41 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/04 16:21:34 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	count_meals(t_data *data, int thread_id)
{
	pthread_mutex_lock(&data->food_eaten);
	data->philos[thread_id].times_ate++;
	if (data->philos[thread_id].times_ate == data->times_to_eat)
	{
		data->philos_eaten--;
	}
	pthread_mutex_unlock(&data->food_eaten);
}

void	controller(t_data *data)
{
	usleep(1000);
	data->start++;
	data->sync = get_time();
	while (data->death != 1 && data->philos_eaten != 0)
		data->regulator = display_time(data) / (data->time_to_eat
				+ data->nmb_of_philos / 12 + 1) % 2;
	data->murder = 1;
	pthread_mutex_lock(&data->starving);
	if (data->philos_eaten != 0)
		print_state(data, data->corpse_id, DEATH);
	destroy_stuff2(data, data->nmb_of_philos);
}
