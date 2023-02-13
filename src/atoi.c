/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:47:23 by kvebers           #+#    #+#             */
/*   Updated: 2023/02/13 11:26:23 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

char	*ft_strdup(const char *s1)
{
	int		counter;
	int		counter1;
	char	*dest;

	counter = 0;
	counter1 = 0;
	while (*(s1 + counter) != '\0')
		counter++;
	dest = malloc((counter) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (counter1 < counter)
	{
		*(dest + counter1) = *(s1 + counter1);
		counter1++;
	}
	*(dest + counter1) = '\0';
	return (dest);
}

int	prot_atoi1(int bonus, char *argv)
{
	int		cnt;
	char	*max;

	if (bonus == 0)
		max = ft_strdup("2147483647");
	if (bonus == 1)
		max = ft_strdup("-2147483648");
	cnt = bonus;
	while (argv[cnt] != '\0')
	{
		if (argv[cnt] > max[cnt])
			return (free(max), 0);
		else if (argv[cnt] < max[cnt])
			return (free(max), 1);
		cnt++;
	}
	return (free(max), 1);
}

int	prot_atoi(char *argv)
{
	int	len;

	len = ft_strlen(argv);
	if (argv[0] == '-' && len > 11)
		return (0);
	if (argv[0] != '-' && len > 10)
		return (0);
	if (argv[0] == '-' && len == 11)
	{
		if (prot_atoi1(1, argv) == 0)
			return (0);
	}
	if (argv[0] != '-' && len == 10)
	{
		if (prot_atoi1(0, argv) == 0)
			return (0);
	}
	return (1);
}

int	check_chars(char *argv)
{
	int	cnt;

	cnt = 0;
	while (*(argv + cnt) != '\0')
	{
		if (*(argv + cnt) < '0' || *(argv + cnt) > '9')
			return (0);
		cnt++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	long			output;
	long			sign;
	unsigned long	c;

	sign = 1;
	c = 0;
	output = 0;
	while ((*(str + c) >= 9 && *(str + c) <= 13) || *(str + c) == ' ')
		c++;
	if (*(str + c) == '+' || *(str + c) == '-')
	{
		if (*(str + c) == '-')
			sign = (-1);
		c++;
	}
	while (*(str + c) != '\0')
	{
		if (*(str + c) < '0' || *(str + c) > '9')
			break ;
		output = output * 10 + (*(str + c) - '0');
		c++;
	}
	return (output * sign);
}
