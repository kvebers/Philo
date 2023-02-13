/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:02:59 by kvebers           #+#    #+#             */
/*   Updated: 2023/02/13 12:09:41 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	add_values(t_data *data, char *ptr, int cnt)
{
	if (cnt == 1)
		data->number_of_philosophers = ft_atoi(ptr);
	else if (cnt == 2)
		data->time_to_die = ft_atoi(ptr);
	else if (cnt == 3)
		data->time_to_eat = ft_atoi(ptr);
	else if (cnt == 4)
		data->time_to_sleep = ft_atoi(ptr);
}

int	check_values(t_data *data)
{
	if (data->number_of_philosophers < 1)
		return (0);
	if (data->time_to_die < 0)
		return (0);
	if (data->time_to_eat < 0)
		return (0);
	if (data->time_to_sleep < 0)
		return (0);
	return (1);
}


int	parse_inputs(t_data *data, char **argv)
{
	int		cnt;
	int		cnt1;
	char	*ptr;

	cnt = 1;
	while (cnt < 5)
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
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL || argc != 5 || parse_inputs(data, argv) == 0)
	{
		write(2, "Error\n", 6);
		return (free(data), 0);
	}
	if (check_values(data) == 0)
	{
		write(2, "Error\n", 6);
		return (free(data), 0);
	}
	free_data(data);
	return (0);
}
