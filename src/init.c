/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:03:16 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/04 13:52:31 by kvebers          ###   ########.fr       */
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
		usleep(1000);
	}
	return (1);
}
