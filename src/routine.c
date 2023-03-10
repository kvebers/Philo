/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:11:26 by kvebers           #+#    #+#             */
/*   Updated: 2023/02/20 12:48:55 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_state(t_data *data, int i)
{
	pthread_mutex_lock(&data->print);
	printf("\033[31m%ld %i died \n\033[0m", get_time() % data->sync, i);
	pthread_mutex_unlock(&data->print);
}

void	*do_smt(void *args)
{
	t_data			*data;
	int				thread_id;

	data = (t_data *)args;
	thread_id = data->id;
	while (data->start != 1)
	{
	}
	usleep (500);
	while (data->murder != 1)
	{
		if (data->sync + data->time_to_die < get_time())
		{
			data->corpse_id = thread_id;
			data->death = 1;
		}	
	}
	return (NULL);
}
