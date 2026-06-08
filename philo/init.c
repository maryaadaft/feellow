/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 11:48:49 by maryaada          #+#    #+#             */
/*   Updated: 2026/06/08 16:29:20 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//shorten fn perchance
void	init_data(t_sim_data *sim_data)
{
	int i;

	i = 0;
	sim_data->end_sim = false;
	sim_data->philos = malloc(sizeof(t_philo) * sim_data->philo_n);
	if (!sim_data->philos)
		return (print_error("failed to malloc for philos!"));
	sim_data->forks = malloc(sizeof(t_fork) * sim_data->philo_n);
	if (!sim_data->forks)
		return (print_error("failed to malloc forks"));
	while(i < sim_data->philo_n)
	{
		sim_data->philos[i].id = i + 1;
		sim_data->philos[i].times_ate = 0;
		sim_data->philos[i].last_meal_time = sim_data->start_sim;
		sim_data->philos[i].l_fork = &sim_data->forks[i];
		sim_data->philos[i].r_fork = &sim_data->forks[(i + 1) % sim_data->philo_n]; //???????
		sim_data->philos[i].sim_data = sim_data;
		i++;
	}
}
