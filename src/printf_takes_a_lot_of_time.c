/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_takes_a_lot_of_time.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 12:26:20 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/07 12:49:05 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_state(t_data *data, int i, int sync)
{
	pthread_mutex_lock(&data->print);
	printf("\033[31m%ld %i died\n\033[0m", display_time(sync), i + 1);
	pthread_mutex_unlock(&data->print);
}

void	print_sleep(t_data *data, int i, int sync)
{
	pthread_mutex_lock(&data->print);
	printf("%ld %i is sleeping\n", display_time(sync), i + 1);
	pthread_mutex_unlock(&data->print);
}

void	print_fork(t_data *data, int i, int sync)
{
	pthread_mutex_lock(&data->print);
	printf("%ld %i has taken a fork\n", display_time(sync), i + 1);
	pthread_mutex_unlock(&data->print);
}

void	print_eating(t_data *data, int i, int sync)
{
	pthread_mutex_lock(&data->print);
	printf("%ld %i is eating\n", display_time(sync), i + 1);
	pthread_mutex_unlock(&data->print);
}

void	print_thinking(t_data *data, int i, int sync)
{
	pthread_mutex_lock(&data->print);
	printf("%ld %i is thinking\n", display_time(sync), i + 1);
	pthread_mutex_unlock(&data->print);
}
