/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:11:26 by kvebers           #+#    #+#             */
/*   Updated: 2023/02/19 13:55:18 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void    print_test(t_data *data, int i)
{
    pthread_mutex_lock(&data->print);
    printf("Thread id %i\n", i);
    pthread_mutex_unlock(&data->print);

}

void	*do_smt(void *args)
{
	t_data		*data;
	int			thread_id;

	data = (t_data *)args;
	thread_id = data->id;
	while (data->start != 1)
	{
	}
    print_test(data, thread_id);
	return (NULL);
}
