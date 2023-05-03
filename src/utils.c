/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:55:42 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/03 12:33:20 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <errno.h>

void	ft_putstr_fd(char *s, int fd)
{
	if (s != NULL)
		write(fd, s, ft_strlen(s));
}

int	ft_pthread_mutex_trylock(pthread_mutex_t *mutex)
{
	if (pthread_mutex_lock(mutex) != 0)
		return (EBUSY);
	else
		return (0);
}
