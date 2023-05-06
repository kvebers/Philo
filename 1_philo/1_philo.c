/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_philo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 10:09:54 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/06 11:01:56 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	handle_1_philo(t_data *data)
{
	data->sync = get_time();
	printf("%ld 1 has taken a fork\n", display_time(data));
	usleep(data->i.time_to_die * 1000);
	printf("\033[31m%ld 1 died\n\033[0m", display_time(data));
}
