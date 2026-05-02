/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 13:12:49 by maryaada          #+#    #+#             */
/*   Updated: 2026/05/02 20:13:06 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>


//use long cauyse we are using ms so int will be annoying

//philo data
typedef struct s_philo_data {
	int	id;
	int	times_ate;
	int	max_food;
	int	time_since_meal; 
	t_fork *l_fork;
	t_fork *r_fork;
	pthread_t	thread_id; 
	t_sim_data *sim_Data;
	
}	t_philo;

//the fork
typedef struct s_fork_data {
	pthread_mutex_t fork;
	int	fork_id;

	
}	t_fork;


//general data storage
typedef struct s_sim_data {
	long philo_n;
	long time_to_die;
	long time_to_eat;
	long time_to_sleep;
	long limit_meals; //5th arg if specified that will end sim at n
	long start_sim;
	int end_sim; //boolean whether all philos ate or one died
	t_fork *forks;
	t_philo *philos;
	 
}	t_sim_data;

#endif