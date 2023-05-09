/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 10:46:30 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/09 11:36:33 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	init_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->print, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&data->starving, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&data->food_eaten, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&data->murdered, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&data->start, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&data->murdered1, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&data->add, NULL) != 0)
		return (0);
	return (1);
}
