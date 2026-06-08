/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 13:12:49 by maryaada          #+#    #+#             */
/*   Updated: 2026/06/08 16:34:28 by maryaada         ###   ########.fr       */
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
# include <stdbool.h>

//use long cause we are using ms so int will be annoying

//telling compiler the struct is defined down already
typedef struct s_fork_data	t_fork;
typedef struct s_sim_data	t_sim_data;

//philo data
typedef struct s_philo_data {
	int	id;
	int	times_ate;
	// int	max_food; //remove? 
	long last_meal_time; 
	t_fork *l_fork;
	t_fork *r_fork;
	pthread_t	thread_id; 
	t_sim_data *sim_data;
}	t_philo;

//the fork
typedef struct s_fork_data {
	pthread_mutex_t fork;
	int	fork_id;

}	t_fork;

//general data storage table
typedef struct s_sim_data {
	long philo_n;
	long time_to_die;
	long time_to_eat;
	long time_to_sleep;
	long limit_meals; //5th arg if specified that will end sim at n
	long start_sim;
	int end_sim; //boolean whether all philos ate or one died
	pthread_mutex_t dead_lock;
	pthread_mutex_t print_lock;
	t_fork *forks;
	t_philo *philos;
	 
}	t_sim_data;

void	print_error(char *msg);


long	to_num(const char *str, int *over_check);
int		is_valid_input(char *str);
void 	parse_args(int argc, char **argv, t_sim_data *sim);
int		ft_strlen(char *str);

#endif