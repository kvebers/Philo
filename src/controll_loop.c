/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controll_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:13:41 by kvebers           #+#    #+#             */
/*   Updated: 2023/02/19 14:00:06 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	controller(t_data *data)
{
	data->start++;
	gettimeofday(&data->sync, NULL);
	// while (data->death == data->nmb_of_philos)
	// {
	// }
	usleep(10000);
}
