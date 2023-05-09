/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:11:26 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/09 13:59:56 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	timer_loop(t_data *data, int time)
{
	long	time_passed;

	time_passed = display_time(data);
	while (time_passed + time > display_time(data))
	{
		if (m_c(data) == 0)
			break ;
		if (data->i.nmb_of_philos < 50)
			usleep(100);
		else
			usleep(1000);
	}
}

void	take_forks(t_data *data, int thread_id, t_input *i, t_philo *philo)
{
	pthread_mutex_lock(&data->forks[philo->left_fork]);
	print_fork(data, thread_id);
	pthread_mutex_lock(&data->forks[philo->right_fork]);
	print_fork(data, thread_id);
	if (philo->time_to_death < display_time(data))
	{
		self_report_death(data, thread_id);
		drop_forks(data, thread_id);
	}
	else
	{
		print_eating(data, thread_id, philo, i);
		count_meals(data);
		timer_loop(data, i->time_to_eat);
		drop_forks(data, thread_id);
		print_sleep(data, thread_id);
		timer_loop(data, i->time_to_sleep);
		print_thinking(data, thread_id);
	}
}

void	finall_setup(t_data *data, int thread_id, t_philo *philo, t_input *i)
{
	philo->potato = 0;
	if (i->nmb_of_philos % 2 == 0)
	{
		if (thread_id % 2 == 0)
			philo->potato = 0;
		else if (thread_id % 2 == 1)
			philo->potato = display_time(data)
				+ i->time_to_eat;
	}
	else
	{
		if (thread_id % 2 == 0)
			philo->potato = 0;
		else if (thread_id % 2 == 1)
			philo->potato = display_time(data)
				+ i->time_to_eat;
		if (thread_id == data->i.nmb_of_philos - 1)
		{
			philo->potato = display_time(data)
				+ i->time_to_eat * 2;
			data->sync = get_time();
		}
	}
	philo->time_to_death = display_time(data)
		+ i->time_to_die;
}



void	*roulett_of_death(void *args)
{
	t_data	*data;
	int		thread_id;
	t_philo	*philo;
	t_input	*input;

	data = (t_data *)args;
	thread_id = data->id;
	philo = &data->philos[thread_id];
	input = &data->i;
	pthread_mutex_lock(&data->start);
	finall_setup(data, thread_id, philo, input);
	pthread_mutex_unlock(&data->start);
	while (data->murder != 1)
	{
		if (philo->time_to_death
			< display_time(data))
			self_report_death(data, thread_id);
		if (display_time(data) > philo->potato)
			take_forks(data, thread_id, input, philo);
		usleep (100);
	}
	return (NULL);
}
