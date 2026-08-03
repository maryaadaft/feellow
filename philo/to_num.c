/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 14:14:14 by maryaada          #+#    #+#             */
/*   Updated: 2026/08/03 14:51:33 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_valid_input(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[i] == '-')
		print_error("Numbers should be positive!");
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long	to_num(const char *str, int *over_check)
{
	int			i;
	long long	n;

	n = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		n = (n * 10) + str[i] - 48;
		if (n > INT_MAX)
		{
			*over_check = 1;
			return (0);
		}
		i++;
	}
	return (n);
}
