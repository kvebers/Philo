/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:02:59 by kvebers           #+#    #+#             */
/*   Updated: 2023/02/12 13:16:36 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
int check_inputs(char **argv)
{
	
}
int	main(int argc, char **argv)
{
	
	if (argc != 5)
	{
		printf("Error");
		return (0);
	}
	if (check_inputs(argv) == 0)
		return (0);
	
}
