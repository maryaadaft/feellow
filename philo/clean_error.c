/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 14:03:10 by maryaada          #+#    #+#             */
/*   Updated: 2026/08/03 14:45:44 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	cleanup(t_sim_data *sim)
{
	int	i;

	i = 0;
	while (i < sim->philo_n)
	{
		pthread_mutex_destroy(&sim->forks[i].fork);
		i++;
	}
	pthread_mutex_destroy(&sim->dead_lock);
	pthread_mutex_destroy(&sim->print_lock);
	free(sim->forks);
	free(sim->philos);
}

void	print_error(char *msg)
{
	write(2, "=================================\n", 35);
	write(2, msg, ft_strlen(msg));
	write(2, "\n=================================\n", 35);
	exit(1);
}
