/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 13:10:20 by maryaada          #+#    #+#             */
/*   Updated: 2026/05/04 18:11:35 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void  parse_args(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		print_error("Please Enter 5 or 6 arguments..");
	if(argc == 5)
	{	
		//validate numbers
			//not negative
			//actual number
			//overflow intmax
			//timestamp arg not above 60ms (????)
		int i;
		
		i = 0;
		while (i < argc)
		{
			ft_atoi(argv[i]);
			i++;
		}
		//atoi(argv[1] -> argv[5]) 4 arguments
	}
	if(argc == 6)
		//validate numbers and exit program at 5th argument
		//with a flag maybe????
}

int	main(int argc, char **argv)
{
	//handle args
	
}
