/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:03:16 by kvebers           #+#    #+#             */
/*   Updated: 2023/02/18 11:57:24 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*do_smt(void *args)
{
	t_data		*data;

	data = (t_data *)args;
	printf("I am inited");
	while (data->start != 1);
	printf("I am still alive");
	return (NULL);
}

void	destroy_stuff(t_data *data, int i, int j)
{
	int	cnt;

	cnt = 0;
	data->start = 0;
	while (cnt <= j)
	{
		pthread_mutex_destroy(&data->forks[cnt]);
		pthread_detach(data->philos[cnt].philos);
		cnt++;
	}
	if (i != j)
		pthread_mutex_destroy(&data->forks[cnt]);
}

int	init_threads_forks(t_data *data, int i)
{
	if (pthread_mutex_init(&data->forks[i], NULL) != 0)
	{
		destroy_stuff(data, i, i - 1);
		return (0);
	}
	if (pthread_create(&data->philos[i].philos, NULL,
			&do_smt, (void *) data) != 0)
	{
		destroy_stuff(data, i, i);
		return (0);
	}
	usleep(1000);
	return (1);
}

void	init_philos_utils(t_data *data, int i)
{
	data->philos[i].id = i;
	data->philos[i].left_fork = i;
	data->philos[i].times_ate = 0;
	data->philos[i].time_to_death = data->time_to_die;
	if (i != data->nmb_of_philos - 1)
		data->philos[i].right_fork = i + 1;
	else
		data->philos[i].right_fork = 0;
}

int	init_philos(t_data *data)
{
	int	i;

	i = 0;
	data->philos = malloc(sizeof(t_philo) * data->nmb_of_philos);
	if (data->philos == NULL)
		return (0);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nmb_of_philos);
	if (data->forks == NULL)
		return (free(data->philos), 0);
	while (i < data->nmb_of_philos)
	{
		init_philos_utils(data, i);
		if (init_threads_forks(data, i) == 0)
			return (free(data->philos), free(data->forks), 0);
		i++;
	}
	while (data->start < 1)
		data->start++;
	return (1);
}
