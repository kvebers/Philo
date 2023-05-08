/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:02:59 by kvebers           #+#    #+#             */
/*   Updated: 2023/05/06 10:33:44 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		return_value;

	if (argc < 5 || argc > 6
		|| parse_inputs(&data, argv, argc) == 0)
	{
		ft_putstr_fd("Proper use ./philo nmb_of_philos, time_to_die, ", 2);
		ft_putstr_fd("time_to_eat, time_to_sleep, times_to_eat\n", 2);
		return (0);
	}
	return_value = check_values(&data);
	if (return_value == 0 || init_philos(&data) == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	else if (return_value == 2)
		return (0);
	controller(&data);
	free_data(&data);
	return (0);
}
