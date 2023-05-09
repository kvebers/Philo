/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 10:04:10 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/09 18:03:18 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	add_values(t_data *data, char *ptr, int cnt)
{
	if (cnt == 1)
		data->i.nmb_of_philos = ft_atoi(ptr);
	else if (cnt == 2)
		data->i.time_to_die = ft_atoi(ptr);
	else if (cnt == 3)
		data->i.time_to_eat = ft_atoi(ptr);
	else if (cnt == 4)
		data->i.time_to_sleep = ft_atoi(ptr);
	else if (cnt == 5)
		data->i.times_to_eat = ft_atoi(ptr);
}

int	check_values(t_data *data)
{
	if (data->i.nmb_of_philos < 1 || data->i.time_to_die < 60
		|| data->i.time_to_eat < 60 || data->i.time_to_sleep < 60
		|| data->i.times_to_eat < -1)
		return (0);
	if (data->i.nmb_of_philos > 200 || data->i.time_to_die > 100000
		|| data->i.time_to_eat > 100000 || data->i.time_to_sleep > 100000
		|| data->i.times_to_eat > 10000)
		return (0);
	if (data->i.nmb_of_philos == 1)
	{
		handle_1_philo(data);
		return (2);
	}
	if (init_mutex(data) == 0)
		return (0);
	init_numbs(data);
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
		data->i.times_to_eat = -1;
	return (1);
}

void	init_numbs(t_data *data)
{
	data->id = 0;
	data->death = 0;
	data->murder1 = 0;
	data->murder = 0;
	data->philos_eaten = 0;
	data->total_inits = 0;
	data->total_times_to_eat = data->i.nmb_of_philos * data->i.times_to_eat;
	if (data->i.nmb_of_philos % 2 == 0)
		data->i.mp = data->i.times_to_eat;
	else
		data->i.mp = data->i.times_to_eat * 3;
}

