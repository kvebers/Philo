/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:15:46 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/03 13:01:07 by kvebers          ###   ########.fr       */
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
	int			death;
	pthread_t	philos;
}	t_philo;

typedef struct data
{
	int				corpse_id;
	int				death;
	int				murder;
	int				id;
	int				start;
	int				nmb_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_to_eat;
	long			sync;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	starving;
}	t_data;

int		ft_atoi(const char *str);
int		prot_atoi(char *argv);
int		check_chars(char *argv);
int		ft_strlen(const char *str);
void	free_data(t_data *data);
int		init_philos(t_data *data);
void	*roulett_of_death(void *args);
void	controller(t_data *data);
void	destroy_stuff(t_data *data, int i, int j);
long	get_time(void);
void	print_state(t_data *data, int i);
void	ft_putstr_fd(char *s, int fd);
int		ft_pthread_mutex_trylock(pthread_mutex_t *mutex);

#endif