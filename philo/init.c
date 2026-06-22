/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 11:48:49 by maryaada          #+#    #+#             */
/*   Updated: 2026/06/22 13:37:43 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//shorten fn perchance
void	init_data(t_sim_data *sim_data)
{
	int i;

	i = 0;
	sim_data->end_sim = false;
	sim_data->start_sim = conv_to_ms();
    pthread_mutex_init(&sim_data->dead_lock, NULL);
    pthread_mutex_init(&sim_data->print_lock, NULL);
	sim_data->philos = malloc(sizeof(t_philo) * sim_data->philo_n);
	if (!sim_data->philos)
		return (print_error("failed to malloc philos!"));
	sim_data->forks = malloc(sizeof(t_fork) * sim_data->philo_n);
	if (!sim_data->forks)
		return (print_error("failed to malloc forks"));
	while(i < sim_data->philo_n)
	{
		pthread_mutex_init(&sim_data->forks[i].fork, NULL);
		sim_data->forks[i].fork_id = i;
		sim_data->philos[i].id = i + 1;
		sim_data->philos[i].times_ate = 0;
		sim_data->philos[i].last_meal_time = sim_data->start_sim;
		sim_data->philos[i].l_fork = &sim_data->forks[i];
		sim_data->philos[i].r_fork = &sim_data->forks[(i + 1) % sim_data->philo_n]; //???????
		sim_data->philos[i].sim_data = sim_data;
		i++;
	}
}

