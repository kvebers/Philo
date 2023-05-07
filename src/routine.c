/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:11:26 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/07 14:17:08 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	take_forks(t_data *data, int thread_id, t_input local)
{
	pthread_mutex_lock(&data->forks[data->philos[thread_id].left_fork]);
	if (m_c(data) == 1)
		print_fork(data, thread_id, local.sync);
	pthread_mutex_lock(&data->forks[data->philos[thread_id].right_fork]);
	if (m_c1(data) == 1)
	{
		print_fork(data, thread_id, local.sync);
		data->philos[thread_id].time_to_death
			= display_time(local.sync) + local.time_to_die;
		print_eating(data, thread_id, local.sync);
		count_meals(data);
		usleep(local.time_to_eat * 1000);
	}
	drop_forks(data, thread_id);
	if (m_c(data) == 1)
	{
		print_sleep(data, thread_id, local.sync);
		usleep(local.time_to_sleep * 1000);
	}
	if (m_c1(data) == 1)
		print_thinking(data, thread_id, local.sync);
}

void	setup_delay(t_data *data, int thread_id, int sync)
{
	if (data->i.nmb_of_philos % 2 == 0)
	{
		if (thread_id % 2 == 1)
		{
			print_thinking(data, thread_id, sync);
			usleep(data->i.time_to_eat * 950);
		}
	}
	else if (data->i.nmb_of_philos % 2 == 1)
	{
		if (thread_id % 3 == 1)
		{
			print_thinking(data, thread_id, sync);
			usleep(data->i.time_to_eat * 990);
		}
		else if (thread_id % 3 == 2)
		{
			print_thinking(data, thread_id, sync);
			usleep(data->i.time_to_eat * 1100);
		}
	}
}

void	*roulett_of_death(void *args)
{
	t_data	*data;
	int		thread_id;
	t_input	local;

	data = (t_data *)args;
	local.nmb_of_philos = data->i.nmb_of_philos;
	local.time_to_die = data->i.time_to_die;
	local.time_to_eat = data->i.time_to_eat;
	local.time_to_sleep = data->i.time_to_sleep;
	local.times_to_eat = data->i.times_to_eat;
	thread_id = data->id;
	pthread_mutex_lock(&data->start);
	local.sync = data->sync;
	pthread_mutex_unlock(&data->start);
	setup_delay(data, thread_id, local.sync);
	while (data->murder != 1)
	{
		usleep (50);
		if (m_c(data) == 1)
			take_forks(data, thread_id, local);
		if (local.sync + data->philos[thread_id].time_to_death
			< get_time() && m_c(data))
			self_report_death(data, thread_id);
	}
	return (NULL);
}
