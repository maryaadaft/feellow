/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 11:48:49 by maryaada          #+#    #+#             */
/*   Updated: 2026/08/03 14:52:28 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_data(t_sim_data *data)
{
	int	i;

	i = 0;
	data->end_sim = false;
	data->start_sim = conv_to_ms();
	pthread_mutex_init(&data->dead_lock, NULL);
	pthread_mutex_init(&data->print_lock, NULL);
	data->philos = malloc(sizeof(t_philo) * data->philo_n);
	if (!data->philos)
		return (print_error("failed to malloc philos!"));
	data->forks = malloc(sizeof(t_fork) * data->philo_n);
	if (!data->forks)
		return (print_error("failed to malloc forks"));
	while (i < data->philo_n)
	{
		pthread_mutex_init(&data->forks[i].fork, NULL);
		data->forks[i].fork_id = i;
		data->philos[i].id = i + 1;
		data->philos[i].times_ate = 0;
		data->philos[i].last_meal_time = data->start_sim;
		data->philos[i].l_fork = &data->forks[i];
		data->philos[i].r_fork = &data->forks[(i + 1) % data->philo_n];
		data->philos[i].sim_data = data;
		i++;
	}
}
