/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controll_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:13:41 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/03 12:40:36 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	controller(t_data *data)
{
	int	i;

	usleep(1000);
	data->start++;
	i = 0;
	data->sync = get_time();
	while (data->death != 1)
	{
	}
	print_state(data, data->corpse_id);
	data->murder = 1;
	while (i < data->nmb_of_philos)
	{
		pthread_join(data->philos[i].philos, NULL);
		i++;
	}
}
