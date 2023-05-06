/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:15:46 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/06 15:40:16 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>	

enum e_philos
{
	DEATH,
	FORKS,
	EATING,
	SLEEPING,
	THINKING
};

typedef struct input
{
	int				nmb_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_to_eat;
}	t_input;

typedef struct philos
{
	t_input		i;
	long		expected_time;
	int			offset;
	int			id;
	long		sync;
	int			time_to_death;
	int			right_fork;
	int			left_fork;
	int			death;
	pthread_t	philos;
}	t_philo;

typedef struct data
{
	t_philo			*philos;
	t_input			i;
	int				corpse_id;
	int				death;
	int				murder;
	int				id;
	int				regulator;
	int				philos_eaten;
	int				total_times_to_eat;
	long			sync;
	pthread_mutex_t	*forks;
	pthread_mutex_t	start;
	pthread_mutex_t	timer;
	pthread_mutex_t	food_eaten;
	pthread_mutex_t	print;
	pthread_mutex_t	starving;
	pthread_mutex_t	murdered;
}	t_data;


// Utils //
int		ft_atoi(const char *str);
int		prot_atoi(char *argv);
int		check_chars(char *argv);
int		ft_strlen(const char *str);

// 1_philo //
void	handle_1_philo(t_data *data);
// init_mutex
int		init_mutex(t_data *data);

void	free_data(t_data *data);
int		init_philos(t_data *data);
void	*roulett_of_death(void *args);
void	controller(t_data *data);
void	destroy_stuff(t_data *data, int i, int j);
long	get_time(void);
void	print_state(t_data *data, int i, int state);
void	ft_putstr_fd(char *s, int fd);
long	display_time(t_data *data);
void	close_all_mutexes(t_data *data);
void	destroy_stuff2(t_data *data, int j);
void	count_meals(t_data *data);
void	init_numbs(t_data *data);
int		check_values(t_data *data);
int		parse_inputs(t_data *data, char **argv, int argc);
int		m_c(t_data *data);
#endif