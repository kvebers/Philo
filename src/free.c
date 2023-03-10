/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:27:01 by kvebers           #+#    #+#             */
/*   Updated: 2023/02/19 13:20:29 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	free_data(t_data *data)
{
	free(data->philos);
	free(data->forks);
	pthread_mutex_destroy(&data->print);
	free(data);
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