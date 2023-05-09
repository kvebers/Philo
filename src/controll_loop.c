/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controll_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:13:41 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/07 13:49:00 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	m_c(t_data *data)
{
	pthread_mutex_lock(&data->murdered);
	if (data->murder != 1)
	{
		pthread_mutex_unlock(&data->murdered);
		return (1);
	}
	pthread_mutex_unlock(&data->murdered);
	return (0);
}

int	m_c1(t_data *data)
{
	pthread_mutex_lock(&data->murdered1);
	if (data->murder1 != 1)
	{
		pthread_mutex_unlock(&data->murdered1);
		return (1);
	}
	pthread_mutex_unlock(&data->murdered1);
	return (0);
}

void	count_meals(t_data *data)
{
	pthread_mutex_lock(&data->food_eaten);
	if (data->i.times_to_eat != -1)
		data->philos_eaten++;
	pthread_mutex_unlock(&data->food_eaten);
}

void	controller(t_data *data)
{
	data->murder1 = 0;
	while (data->death != 1)
	{
	}
	data->murder = 1;
	data->murder1 = 1;
	usleep(100);
	pthread_mutex_lock(&data->starving);
	if (data->i.times_to_eat == -1)
		print_state(data, data->corpse_id, data->sync);
	else if (data->total_times_to_eat > data->philos_eaten)
		print_state(data, data->corpse_id, data->sync);
	usleep(1000);
	destroy_stuff2(data, data->i.nmb_of_philos);
}
