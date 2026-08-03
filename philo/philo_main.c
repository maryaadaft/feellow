/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 13:10:20 by maryaada          #+#    #+#             */
/*   Updated: 2026/08/03 14:49:34 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_sim_data	*parse_sim_data(char **argv, t_sim_data *sim)
{
	int	over_check;

	over_check = 0;
	sim->philo_n = to_num(argv[1], &over_check);
	if (sim->philo_n <= 0)
		print_error("Invalid number of philosophers");
	sim->time_to_die = to_num(argv[2], &over_check);
	sim->time_to_eat = to_num(argv[3], &over_check);
	sim->time_to_sleep = to_num(argv[4], &over_check);
	if (!argv[5])
		sim->limit_meals = -1;
	if (over_check == 1)
		print_error("invalid range detected, input range less than INT_MAX");
	return (sim);
}

void	parse_args(int argc, char **argv, t_sim_data *sim)
{
	int	i;
	int	over_check;

	i = 1;
	over_check = 0;
	if (sim == NULL)
		return ;
	if (argc < 5 || argc > 6)
		print_error("Please Enter 5 or 6 arguments..");
	while (i < argc)
	{
		if ((is_valid_input(argv[i]) == 0))
			print_error("Please enter a valid numerical input");
		i++;
	}
	parse_sim_data(argv, sim);
	if (argc == 6)
		sim->limit_meals = to_num(argv[5], &over_check);
	if (over_check == 1 || sim->limit_meals == 0)
		print_error("Invalid range detected, input range less than INT_MAX");
}

int	main(int argc, char **argv)
{
	t_sim_data	sim;
	pthread_t	monitor;
	int			i;

	i = 0;
	parse_args(argc, argv, &sim);
	init_data(&sim);
	while (i < sim.philo_n)
	{
		pthread_create(&sim.philos[i].thread_id,
			NULL, philo_routine, &sim.philos[i]);
		i++;
	}
	pthread_create(&monitor, NULL, monitor_routine, &sim);
	i = 0;
	while (i < sim.philo_n)
	{
		pthread_join(sim.philos[i].thread_id, NULL);
		i++;
	}
	pthread_join(monitor, NULL);
	cleanup(&sim);
}
