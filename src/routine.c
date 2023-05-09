/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:11:26 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/08 13:41:05 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	take_forks(t_data *data, int thread_id)
{
	pthread_mutex_lock(&data->forks[data->philos[thread_id].left_fork]);
	if (m_c1(data) == 1)
		print_fork(data, thread_id);
	pthread_mutex_lock(&data->forks[data->philos[thread_id].right_fork]);
	if (m_c(data) == 1)
		print_fork(data, thread_id);
	if (m_c1(data) == 1)
	{
		data->philos[thread_id].time_to_death
			= display_time(data) + data->i.time_to_die;
		print_eating(data, thread_id);
		count_meals(data);
	}
	if (m_c(data) == 1)
		usleep(data->i.time_to_eat * 1000);
	drop_forks(data, thread_id);
	if (m_c1(data) == 1)
		print_sleep(data, thread_id);
	if (m_c(data) == 1)
		usleep(data->i.time_to_sleep * 1000);
	if (m_c1(data) == 1)
		print_thinking(data, thread_id);
}

void	*roulett_of_death(void *args)
{
	t_data	*data;
	int		thread_id;

	data = (t_data *)args;
	thread_id = data->id;
	pthread_mutex_lock(&data->start);
	pthread_mutex_unlock(&data->start);
	while (data->murder != 1)
	{
		usleep (100);
		if (data->regulator == thread_id % 2 && data->murder != 1
			&& data->i.nmb_of_philos % 2 == 0)
			take_forks(data, thread_id);
		else if (data->regulator == thread_id % 3 && data->murder != 1
			&& data->i.nmb_of_philos % 2 == 1)
			take_forks(data, thread_id);
		if (data->sync + data->philos[thread_id].time_to_death
			< get_time() && data->murder != 1)
			self_report_death(data, thread_id);
	}
	return (NULL);
}
