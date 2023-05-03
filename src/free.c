/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:27:01 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/03 12:02:50 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	free_data(t_data *data)
{
	free(data->philos);
	free(data->forks);
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->starving);
}

void	destroy_stuff(t_data *data, int i, int j)
{
	int	cnt;

	cnt = 0;
	while (cnt <= j)
	{
		pthread_mutex_destroy(&data->forks[cnt]);
		pthread_detach(data->philos[cnt].philos);
		cnt++;
	}
	if (i != j)
		pthread_mutex_destroy(&data->forks[cnt]);
}
