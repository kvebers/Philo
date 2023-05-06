/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:03:16 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/06 16:35:07 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	init_threads_forks(t_data *data, int i)
{
	if (pthread_mutex_init(&data->forks[i], NULL) != 0)
	{
		destroy_stuff(data, i, i - 1);
		return (0);
	}
	if (pthread_create(&data->philos[i].philos, NULL,
			&roulett_of_death, (void *) data) != 0)
	{
		destroy_stuff(data, i, i);
		return (0);
	}
	return (1);
}

void	init_philos_utils(t_data *data, int i)
{
	data->id = i;
	if (data->i.nmb_of_philos % 2 == 0)
		data->philos[i].offset = 1;
	data->philos[i].offset = 2;
	if (data->philos[i].offset == 1 && i % 2 == 1)
		data->philos[i].expected_time = data->i.time_to_eat - 5;
	else if (data->philos[i].offset == 2 && i % 2 == 1)
		data->philos[i].expected_time = data->i.time_to_eat - 5;
	else if (data->philos[i].offset == 2 && i % 2 == 2)
		data->philos[i].expected_time = 2 * data->i.time_to_eat - 5;
	else
		data->philos[i].expected_time = 0;
	data->philos[i].i.nmb_of_philos = data->i.nmb_of_philos;
	data->philos[i].i.time_to_die = data->i.time_to_die;
	data->philos[i].i.time_to_eat = data->i.time_to_eat;
	data->philos[i].i.time_to_sleep = data->i.time_to_sleep;
	data->philos[i].i.times_to_eat = data->i.times_to_eat;
	data->philos[i].id = i;
	data->philos[i].left_fork = i;
	data->philos[i].time_to_death = data->i.time_to_die;
	if (i != data->i.nmb_of_philos - 1)
		data->philos[i].right_fork = i + 1;
	else
		data->philos[i].right_fork = 0;
}

int	init_philos(t_data *data)
{
	int	i;

	i = 0;
	data->philos = malloc(sizeof(t_philo) * data->i.nmb_of_philos);
	if (data->philos == NULL)
		return (0);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->i.nmb_of_philos);
	if (data->forks == NULL)
		return (free(data->philos), 0);
	pthread_mutex_lock(&data->start);
	while (i < data->i.nmb_of_philos)
	{
		init_philos_utils(data, i);
		if (init_threads_forks(data, i) == 0)
			return (free(data->philos), free(data->forks), 0);
		i++;
		usleep(1000);
	}
	usleep(1000);
	data->sync = get_time();
	pthread_mutex_unlock(&data->start);
	return (1);
}
