/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 13:10:20 by maryaada          #+#    #+#             */
/*   Updated: 2026/05/11 14:23:01 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void  parse_args(int argc, char **argv, t_sim_data *sim)
{
	int i;
	int	over_check;

	i = 1;
	over_check = 0;
	sim = malloc(sizeof(t_sim_data));
	if (sim == NULL)
		return ;

	if (argc < 5 || argc > 6)
		print_error("Please Enter 5 or 6 arguments..");
		//validate numbers
			//timestamp arg not above 60ms (????)
	while (i < argc)
	{
		if ((is_valid_input(argv[i]) == 0))
			print_error("please enter a valid numerical input");
		i++;
		//atoi(argv[1] -> argv[5]) 4 arguments
	}
	sim->philo_n = to_num(argv[1], &over_check); //figure out how atoi will work here.
	sim->time_to_die = to_num(argv[2], &over_check);
	sim->time_to_eat = to_num(argv[3], &over_check);
	sim->time_to_sleep = to_num(argv[4], &over_check);
	sim->limit_meals = -1; //when 5 args this is not checked, set to -1 for later
	if(argc == 6)
		sim->limit_meals = to_num(argv[5], &over_check);
	if(over_check == 1)
		print_error("invalid range detected, input range less than INT_MAX");

		//validate numbers and exit program at 5th argument
		//with a flag maybe???? later
}

int	main(int argc, char **argv)
{
	//handle args
	t_sim_data sim;
	parse_args(argc, argv, &sim);
	
}
