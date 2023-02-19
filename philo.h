/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:15:46 by kvebers           #+#    #+#             */
/*   Updated: 2023/02/19 13:59:17 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>	

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
	int				death;
	int				id;
	int				start;
	int				nmb_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_to_eat;
	struct timeval	sync;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
}	t_data;

int		ft_atoi(const char *str);
int		prot_atoi(char *argv);
int		check_chars(char *argv);
int		ft_strlen(const char *str);
void	free_data(t_data *data);
int		init_philos(t_data *data);
void	*do_smt(void *args);
void	controller(t_data *data);
void	destroy_stuff(t_data *data, int i, int j);

#endif