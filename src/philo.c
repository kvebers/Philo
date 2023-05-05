/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:02:59 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/05 18:10:09 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	add_values(t_data *data, char *ptr, int cnt)
{
	if (cnt == 1)
		data->nmb_of_philos = ft_atoi(ptr);
	else if (cnt == 2)
		data->time_to_die = ft_atoi(ptr);
	else if (cnt == 3)
		data->time_to_eat = ft_atoi(ptr);
	else if (cnt == 4)
		data->time_to_sleep = ft_atoi(ptr);
	else if (cnt == 5)
		data->times_to_eat = ft_atoi(ptr);
}

int	check_values(t_data *data)
{
	if (data->nmb_of_philos < 1 || data->time_to_die < 0
		|| data->time_to_eat < 0 || data->time_to_sleep < 0
		|| data->times_to_eat < -1)
		return (0);
	if (pthread_mutex_init(&data->print, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&data->starving, NULL) != 0)
	{
		pthread_mutex_destroy(&data->print);
		return (0);
	}
	if (pthread_mutex_init(&data->food_eaten, NULL) != 0)
	{
		pthread_mutex_destroy(&data->starving);
		pthread_mutex_destroy(&data->print);
		return (0);
	}
	data->id = 0;
	data->death = 0;
	data->murder = 0;
	data->start = 0;
	data->philos_eaten = 0;
	data->total_times_to_eat = data->nmb_of_philos * data->times_to_eat;
	return (1);
}

int	parse_inputs(t_data *data, char **argv, int argc)
{
	int		cnt;
	int		cnt1;
	char	*ptr;

	cnt = 1;
	while (cnt < argc)
	{
		cnt1 = 0;
		if (*(argv[cnt]) == ' ')
		{
			while (*(argv[cnt] + cnt1) == ' ')
				cnt1++;
		}
		if (*(argv[cnt] + cnt1) == '+')
			cnt1++;
		ptr = argv[cnt] + cnt1;
		if (check_chars(argv[cnt] + cnt1 + 1) == 0
			|| prot_atoi(argv[cnt] + cnt1) == 0)
			return (0);
		add_values(data, ptr, cnt);
		cnt++;
	}
	if (argc < 6)
		data->times_to_eat = -1;
	return (1);
}

void	handle_1_philo(t_data *data)
{
	data->sync = get_time();
	printf("%ld 1 has taken a fork\n", display_time(data));
	usleep(data->time_to_die * 1000);
	printf("\033[31m%ld 1 died\n\033[0m", display_time(data));
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6
		|| parse_inputs(&data, argv, argc) == 0)
	{
		ft_putstr_fd("Proper use ./philo nmb_of_philos, time_to_die, ", 2);
		ft_putstr_fd("time_to_eat, time_to_sleep, times_to_eat\n", 2);
		return (0);
	}
	if (data.nmb_of_philos == 1)
	{
		handle_1_philo(&data);
		return (0);
	}
	else if (check_values(&data) == 0 || init_philos(&data) == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	controller(&data);
	free_data(&data);
	return (0);
}
