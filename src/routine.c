/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:11:26 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/03 14:26:19 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_state(t_data *data, int i)
{
	pthread_mutex_lock(&data->print);
	printf("\033[31m%ld %i died \n\033[0m", get_time() - data->sync, i + 1);
	pthread_mutex_unlock(&data->print);
}

void	self_report_death(t_data *data, int thread_id)
{
	if (ft_pthread_mutex_trylock(&data->starving) == 0)
	{
		data->corpse_id = thread_id;
		data->death = 1;
	}
	pthread_mutex_unlock(&data->starving);
}

void	*roulett_of_death(void *args)
{
	t_data			*data;
	int				thread_id;

	data = (t_data *)args;
	thread_id = data->id;
	while (data->start != 1)
	{
	}
	while (data->murder != 1)
	{
		usleep (100);
		if (data->sync + data->philos[thread_id].time_to_death
			< get_time() && data->murder != 1)
			self_report_death(data, thread_id);
	}
	return (NULL);
}
