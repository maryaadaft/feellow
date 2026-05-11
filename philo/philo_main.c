/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 13:10:20 by maryaada          #+#    #+#             */
/*   Updated: 2026/05/11 15:10:54 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	pcheck(t_sim_data *sim)
{
	printf("philo n is - %ld\n", sim->philo_n);
	printf("time to die is - %ld\n", sim->time_to_die);
	printf("time to eat is - %ld\n", sim->time_to_eat);
	printf("time to sleep is - %ld\n", sim->time_to_sleep);
	if (sim->limit_meals)
		printf("limit is - %ld\n", sim->limit_meals);
}

t_sim_data	*parse_sim_data(char **argv, t_sim_data *sim)
{
	int	over_check;

	over_check = 0;
	sim->philo_n = to_num(argv[1], &over_check);
	sim->time_to_die = to_num(argv[2], &over_check) * 1000;
	sim->time_to_eat = to_num(argv[3], &over_check) * 1000;
	sim->time_to_sleep = to_num(argv[4], &over_check) * 1000;
	sim->limit_meals = -1; //when 5 args this is not checked, set to -1 for later
	if (sim->time_to_die < 60000 || sim->time_to_eat < 60000
		|| sim->time_to_sleep < 60000)
			print_error("Time specified is less than 60ms");
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
	// sim->philo_n = to_num(argv[1], &over_check);
	// sim->time_to_die = to_num(argv[2], &over_check) * 1000;
	// sim->time_to_eat = to_num(argv[3], &over_check) * 1000;
	// sim->time_to_sleep = to_num(argv[4], &over_check) * 1000;
	// sim->limit_meals = -1; //when 5 args this is not checked, set to -1 for later
	// if (sim->time_to_die < 60000 || sim->time_to_eat < 60000
	// 	|| sim->time_to_sleep < 60000)
	// 		print_error("Time specified is less than 60ms");
	if(argc == 6)
		sim->limit_meals = to_num(argv[5], &over_check);
	// if(over_check == 1)
	// 	print_error("invalid range detected, input range less than INT_MAX");
		//validate numbers and exit program at 5th argument
		//with a flag maybe???? later
}

int	main(int argc, char **argv)
{
	//handle args
	t_sim_data sim;
	parse_args(argc, argv, &sim);

	pcheck(&sim);
	
}
