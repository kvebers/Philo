/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:11:26 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/04 16:35:31 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_state(t_data *data, int i, int state)
{
	pthread_mutex_lock(&data->print);
	if (state == DEATH)
	{
		usleep (1000);
		printf("\033[31m%ld %i died\n\033[0m", get_time()
			- data->sync - 1, i + 1);
	}
	else if (state == FORKS)
		printf("%ld %i has taken a fork\n", display_time(data), i + 1);
	else if (state == EATING)
	{
		printf("%ld %i is eating\n", display_time(data), i + 1);
		count_meals(data, i);
	}
	else if (state == SLEEPING)
		printf("%ld %i is sleeping\n", display_time(data), i + 1);
	else if (state == THINKING)
		printf("%ld %i is thinking\n", display_time(data), i + 1);
	if (state != DEATH)
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
	if (data->murder != 1)
		print_state(data, thread_id, FORKS);
	pthread_mutex_lock(&data->forks[data->philos[thread_id].right_fork]);
	if (data->murder != 1)
		print_state(data, thread_id, FORKS);
	if (data->murder != 1)
	{
		data->philos[thread_id].time_to_death
			= display_time(data) + data->time_to_die;
		print_state(data, thread_id, EATING);
	}
	if (data->murder != 1)
		usleep(data->time_to_eat * 1000);
	drop_forks(data, thread_id);
	if (data->murder != 1)
		print_state(data, thread_id, SLEEPING);
	if (data->murder != 1)
		usleep(data->time_to_sleep * 1000);
	if (data->murder != 1)
		print_state(data, thread_id, THINKING);
}

void	*roulett_of_death(void *args)
{
	t_data	*data;
	int		thread_id;

	data = (t_data *)args;
	thread_id = data->id;
	while (data->start != 1)
	{
	}
	while (data->murder != 1)
	{
		usleep (100);
		if (data->regulator == thread_id % 2 && data->murder != 1)
			take_forks(data, thread_id);
		if (data->sync + data->philos[thread_id].time_to_death
			< get_time() && data->murder != 1)
			self_report_death(data, thread_id);
		if (data->murder == 1)
			break ;
	}
	return (NULL);
}
