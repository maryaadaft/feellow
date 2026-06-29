/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 13:10:20 by maryaada          #+#    #+#             */
/*   Updated: 2026/06/29 12:02:49 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//!!delete this its for testing!!
void	pcheck(t_sim_data *sim)
{
	printf("philo n is - %ld\n", sim->philo_n);
	printf("time to die is - %ld\n", sim->time_to_die);
	printf("time to eat is - %ld\n", sim->time_to_eat);
	printf("time to sleep is - %ld\n", sim->time_to_sleep);
	if (sim->limit_meals)
		printf("limit is - %ld\n", sim->limit_meals);
}

void    debug_print(t_sim_data *sim)
{
    int i;

    i = 0;
    printf("=== SIM DATA ===\n");
    printf("philo_n:      %ld\n", sim->philo_n);
    printf("time_to_die:  %ld\n", sim->time_to_die);
    printf("time_to_eat:  %ld\n", sim->time_to_eat);
    printf("time_to_sleep:%ld\n", sim->time_to_sleep);
    printf("limit_meals:  %ld\n", sim->limit_meals);
    printf("start_sim:    %ld\n", sim->start_sim);
    printf("\n=== PHILOSOPHERS ===\n");
    while (i < sim->philo_n)
    {
        printf("philo %d | last_meal: %ld | l_fork: %d | r_fork: %d\n",
            sim->philos[i].id,
            sim->philos[i].last_meal_time,
            sim->philos[i].l_fork->fork_id,
            sim->philos[i].r_fork->fork_id);
        i++;
    }
}

//===================================================

t_sim_data	*parse_sim_data(char **argv, t_sim_data *sim)
{
	int	over_check;

	over_check = 0;
	sim->philo_n = to_num(argv[1], &over_check);
	sim->time_to_die = to_num(argv[2], &over_check);
	sim->time_to_eat = to_num(argv[3], &over_check);
	sim->time_to_sleep = to_num(argv[4], &over_check);
	if(!argv[5])
		sim->limit_meals = -1; //when 5 args this is not checked, set to -1 for later
	if(over_check == 1)
		print_error("invalid range detected, input range less than INT_MAX");
	return (sim);
}

void  parse_args(int argc, char **argv, t_sim_data *sim)
{
	int i;
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
			print_error("please enter a valid numerical input");
		i++;
	}
	parse_sim_data(argv, sim);
	if(argc == 6)
		sim->limit_meals = to_num(argv[5], &over_check);
	if(over_check == 1)
		print_error("invalid range detected, input range less than INT_MAX");
}

int	main(int argc, char **argv)
{
	//handle args
	t_sim_data sim;
	pthread_t monitor;
	int i;

	i = 0;
	parse_args(argc, argv, &sim);
	// printf("limit_meals is: %ld\n", sim.limit_meals);
	init_data(&sim);
	while( i <sim.philo_n)
	{
		pthread_create(&sim.philos[i].thread_id, NULL, philo_routine, &sim.philos[i]);
		i++;
	}
	pthread_create(&monitor, NULL, monitor_routine, &sim);
	i = 0;
	while (i < sim.philo_n)
	{
		pthread_join(sim.philos[i].thread_id, NULL);
		i++;
	}
	// pthread_join(sim.philos[i].thread_id, NULL);
	//debug_print(&sim);
	cleanup(&sim);
	// pcheck(&sim);
}
