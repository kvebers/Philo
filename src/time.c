/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:07:37 by kvebers           #+#    #+#             */
/*   Updated: 2023/02/20 11:12:05 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long	get_time(void)
{
	long			time;
	struct timeval	timer;

	gettimeofday(&timer, NULL);
	time = timer.tv_sec * 1000 + timer.tv_usec / 1000;
	return (time);
}
