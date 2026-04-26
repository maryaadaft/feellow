/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 13:10:20 by maryaada          #+#    #+#             */
/*   Updated: 2026/04/23 13:17:27 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void  parse_args(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		exit(1); //why exit(1) and not exit(0)

	if(argc == 5)
		//validate numbers
		//atoi(argv[1] -> argv[5]) 4 arguments
	if(argc == 6)
		//validate numbers and exit program at 5th argument
		//with a flag maybe????
}

int	main(int argc, char **argv)
{
	//handle args
	
}
