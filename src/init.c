/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:03:16 by kvebers           #+#    #+#             */
/*   Updated: 2023/02/16 13:17:38 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// int	init_threads(t_data *data)
// {
// 	data->philos->philos = malloc(sizeof(pthread_t));
// }

int	init_philos(t_data *data)
{
	int	i;

	i = 0;
	data->philos = malloc(sizeof(t_philo) * data->number_of_philosophers);
	if (data->philos == NULL)
		return (0);
	while (i < data->number_of_philosophers)
	{
		data->philos[i].id = i;
		data->philos[i].left_fork = i;
		data->philos[i].times_ate = 0;
		data->philos[i].time_to_death = data->time_to_die;
		if (i != data->number_of_philosophers - 1)
			data->philos[i].right_fork = i + 1;
		else
			data->philos[i].right_fork = 0;
		pthread_create(data->philos[i].philos, NULL, &thread_function, NULL);
		i++;
	}
	return (1);
}

int	init_forks(t_data *data)
{
	data->forks = malloc(sizeof(pthread_mutex_t)
			* data->number_of_philosophers);
	if (data->forks == NULL)
		return (0);
	data->forks
}
