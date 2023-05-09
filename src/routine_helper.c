/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 11:42:04 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/07 11:42:24 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	self_report_death(t_data *data, int thread_id)
{
	pthread_mutex_lock(&data->starving);
	data->corpse_id = thread_id;
	data->death = 1;
	pthread_mutex_unlock(&data->starving);
}

void	drop_forks(t_data *data, int thread_id)
{
	pthread_mutex_unlock(&data->forks[data->philos[thread_id].left_fork]);
	pthread_mutex_unlock(&data->forks[data->philos[thread_id].right_fork]);
}
