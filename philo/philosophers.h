/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 13:12:49 by maryaada          #+#    #+#             */
/*   Updated: 2026/08/03 14:28:44 by maryaada         ###   ########.fr       */
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

typedef struct s_fork_data	t_fork;
typedef struct s_sim_data	t_sim_data;

typedef struct s_philo_data
{
	int			id;
	int			times_ate;
	long		last_meal_time;
	t_fork		*l_fork;
	t_fork		*r_fork;
	pthread_t	thread_id;
	t_sim_data	*sim_data;
}	t_philo;

typedef struct s_fork_data
{
	pthread_mutex_t	fork;
	int				fork_id;
}	t_fork;

typedef struct s_sim_data
{
	long			philo_n;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			limit_meals;
	long			start_sim;
	int				end_sim;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	print_lock;
	t_fork			*forks;
	t_philo			*philos;
}	t_sim_data;

void	print_error(char *msg);
long	to_num(const char *str, int *over_check);
int		is_valid_input(char *str);
void	parse_args(int argc, char **argv, t_sim_data *sim);
int		ft_strlen(char *str);
void	cleanup(t_sim_data *sim);
void	init_data(t_sim_data *sim_data);
void	*philo_routine(void *arg);
void	*monitor_routine(void *arg);
long	conv_to_ms(void);
void	safe_usleep(long ms);
void	set_end_sim(t_sim_data *sim);
int		check_end_sim(t_sim_data *sim);
void	print_action(t_philo *philo, char *action);

#endif