/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controll_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:13:41 by kvebers           #+#    #+#             */
/*   Updated: 2023/02/20 12:30:34 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	controller(t_data *data)
{
	int	i;

	data->start++;
	i = 0;
	data->sync = get_time();
	while (data->death != 1)
	{
	}
	data->murder = 1;
	print_state(data, data->corpse_id);
	while (i < data->nmb_of_philos)
	{
		pthread_join(data->philos[i].philos, NULL);
		i++;
	}
}
