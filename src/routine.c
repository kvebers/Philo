/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:11:26 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/06 16:50:36 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_state(t_data *data, int i, int state)
{
	pthread_mutex_lock(&data->print);
	if (state == DEATH)
		printf("\033[31m%ld %i died\n\033[0m", display_time(data), i + 1);
	else if (state == FORKS)
		printf("%ld %i has taken a fork\n", display_time(data), i + 1);
	else if (state == EATING)
		printf("%ld %i is eating\n", display_time(data), i + 1);
	else if (state == SLEEPING)
		printf("%ld %i is sleeping\n", display_time(data), i + 1);
	else if (state == THINKING)
		printf("%ld %i is thinking\n", display_time(data), i + 1);
	pthread_mutex_unlock(&data->print);
}

void	self_report_death(t_data *data, int thread_id)
{
	pthread_mutex_lock(&data->starving);
	data->corpse_id = thread_id;
	data->death = 1;
	pthread_mutex_unlock(&data->starving);
}

void	drop_forks(t_data *data, int thread_id)
{
	pthread_mutex_unlock(&data->forks[data->philos[thread_id].left_fork]);
	pthread_mutex_unlock(&data->forks[data->philos[thread_id].right_fork]);
}

void	take_forks(t_data *data, int thread_id)
{
	pthread_mutex_lock(&data->forks[data->philos[thread_id].left_fork]);
	if (m_c(data) == 1)
		print_state(data, thread_id, FORKS);
	pthread_mutex_lock(&data->forks[data->philos[thread_id].right_fork]);
	if (m_c(data) == 1)
		print_state(data, thread_id, FORKS);
	if (m_c(data) == 1)
	{
		data->philos[thread_id].time_to_death
			= display_time(data) + data->i.time_to_die;
		data->philos[thread_id].expected_time = get_time()
			+ data->philos[thread_id].i.time_to_eat
			* data->philos[thread_id].offset - 10;
		print_state(data, thread_id, EATING);
		count_meals(data);
	}
	if (m_c(data) == 1)
		usleep(data->i.time_to_eat * 1000);
	drop_forks(data, thread_id);
	if (m_c(data) == 1)
		print_state(data, thread_id, SLEEPING);
	if (m_c(data) == 1)
		usleep(data->i.time_to_sleep * 1000);
	if (m_c(data) == 1)
		print_state(data, thread_id, THINKING);
}

void	*roulett_of_death(void *args)
{
	t_data	*data;
	int		thread_id;

	data = (t_data *)args;
	thread_id = data->id;
	pthread_mutex_lock(&data->start);
	data->philos[thread_id].expected_time
		= data->philos[thread_id].expected_time
		+ data->sync;
	pthread_mutex_unlock(&data->start);
	while (data->murder != 1)
	{
		usleep (100);
		if (get_time() > data->philos[thread_id].expected_time
			&& m_c(data) == 1)
			take_forks(data, thread_id);
		if (data->philos[thread_id].sync + data->philos[thread_id].time_to_death
			< get_time() && m_c(data))
			self_report_death(data, thread_id);
	}
	return (NULL);
}
