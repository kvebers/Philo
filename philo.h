/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:15:46 by kvebers           #+#    #+#             */
/*   Updated: 2023/02/15 14:59:29 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct philos
{
	int			id;
	int			times_ate;
	int			time_to_death;
	int			right_fork;
	int			left_fork;
	pthread_t	philos;
}	t_philo;

typedef struct data
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_to_eat;
	t_philo			*philos;
	pthread_mutex_t	*forks;
}	t_data;

int		ft_atoi(const char *str);
int		prot_atoi(char *argv);
int		check_chars(char *argv);
int		ft_strlen(const char *str);
void	free_data(t_data *data);
int		init_philos(t_data *data);
int		init_philos(t_data *data);
int		init_forks(t_data *data);
#endif