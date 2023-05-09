/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:27:01 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/09 18:07:30 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	free_data(t_data *data)
{
	free(data->forks);
	free(data->philos);
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->starving);
	pthread_mutex_destroy(&data->murdered);
	pthread_mutex_destroy(&data->food_eaten);
	pthread_mutex_destroy(&data->start);
	pthread_mutex_destroy(&data->murdered1);
	pthread_mutex_destroy(&data->add);
}

void	destroy_stuff(t_data *data, int i, int j)
{
	int	cnt;

	cnt = 0;
	while (cnt <= j)
	{
		pthread_detach(data->philos[cnt].philos);
		pthread_mutex_destroy(&data->forks[cnt]);
		cnt++;
	}
	if (i != j)
		pthread_mutex_destroy(&data->forks[cnt]);
}

void	destroy_stuff2(t_data *data, int j)
{
	int	cnt;

	cnt = 0;
	while (cnt < j)
	{
		pthread_join(data->philos[cnt].philos, NULL);
		cnt++;
	}
	cnt = 0;
	while (cnt < j)
	{
		pthread_mutex_destroy(&data->forks[cnt]);
		cnt++;
	}
	cnt = 0;
}
