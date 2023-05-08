/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:11:26 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/08 12:14:01 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	take_forks(t_data *data, int thread_id, t_input *local)
{
	pthread_mutex_lock(&data->forks[data->philos[thread_id].left_fork]);
	if (m_c(data) == 1)
		print_fork(data, thread_id, local->sync);
	pthread_mutex_lock(&data->forks[data->philos[thread_id].right_fork]);
	if (m_c1(data) == 1)
	{
		print_fork(data, thread_id, local->sync);
		local->time_to_death = display_time(local->sync) + local->time_to_die;
		local->expected_time = local->time_to_death - 20;
		print_eating(data, thread_id, local->sync);
		count_meals(data);
		usleep(local->time_to_eat * 1000);
	}
	drop_forks(data, thread_id);
	if (m_c(data) == 1)
	{
		print_sleep(data, thread_id, local->sync);
		usleep(local->time_to_sleep * 1000);
	}
	if (m_c1(data) == 1)
		print_thinking(data, thread_id, local->sync);
}

void	*roulett_of_death(void *args)
{
	t_data	*data;
	int		thread_id;
	t_input	local;

	data = (t_data *)args;
	thread_id = data->id;
	init_local(data, &local);
	pthread_mutex_lock(&data->start);
	local.sync = data->sync;
	pthread_mutex_unlock(&data->start);
	while (data->murder != 1)
	{
		if (local.expected_time < display_time(local.sync))
			take_forks(data, thread_id, &local);
		if (local.time_to_death < display_time(local.sync) && m_c(data) == 1)
			self_report_death(data, thread_id);
		usleep (50);
	}
	return (NULL);
}
