/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 13:45:34 by maryaada          #+#    #+#             */
/*   Updated: 2026/06/29 12:41:32 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//make only even number philos take a fork 1st, and lock them instantly
static	void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->r_fork->fork);
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(&philo->l_fork->fork);
		print_action(philo, "has taken a fork");
	}
	else 
	{
		pthread_mutex_lock(&philo->l_fork->fork);
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(&philo->r_fork->fork);
		print_action(philo, "has taken a fork");
	}
}

static	void  philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->sim_data->dead_lock);
	philo->last_meal_time = conv_to_ms();
	philo->times_ate++;
	pthread_mutex_unlock(&philo->sim_data->dead_lock);
	print_action(philo, "is eating");
	safe_usleep(philo->sim_data->time_to_eat);
}

static void release_forks(t_philo *philo)
{
	if(philo->id % 2 == 0)
	{
		pthread_mutex_unlock(&philo->r_fork->fork);
		pthread_mutex_unlock(&philo->l_fork->fork);
	}
	else 
	{
		pthread_mutex_unlock(&philo->l_fork->fork);
		pthread_mutex_unlock(&philo->r_fork->fork);
	}
}

void    *philo_routine(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    if (philo->sim_data->philo_n == 1)
    {
        pthread_mutex_lock(&philo->l_fork->fork);
        print_action(philo, "has taken a fork");
        // safe_usleep(philo->sim_data->time_to_die + 1);
		while(!check_end_sim(philo->sim_data))
			safe_usleep(500);
        pthread_mutex_unlock(&philo->l_fork->fork);
        return (NULL);
    }
    if (philo->id % 2 == 0)
        safe_usleep(1);
    // while (!check_end_sim(philo->sim_data))
    // {
    //     take_forks(philo);
    //     if (check_end_sim(philo->sim_data))
    //     {
    //         release_forks(philo);
    //         break ;
    //     }
    //    philo_eat(philo);
    //     release_forks(philo);
    //     print_action(philo, "is sleeping");
    //     safe_usleep(philo->sim_data->time_to_sleep);
    //     print_action(philo, "is thinking");
    // }
	while (1)
	{
    	if (check_end_sim(philo->sim_data))
        	break ;
    	take_forks(philo);
    	if (check_end_sim(philo->sim_data))
    	{
			release_forks(philo);
			break ;
    	}
		philo_eat(philo);
		release_forks(philo);
		print_action(philo, "is sleeping");
		safe_usleep(philo->sim_data->time_to_sleep);
		print_action(philo, "is thinking");
		if (philo->sim_data->philo_n % 2 != 0)
    		safe_usleep(philo->sim_data->time_to_eat / 2);
	}
	return (NULL);
}
