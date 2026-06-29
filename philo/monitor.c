/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 11:30:08 by maryaada          #+#    #+#             */
/*   Updated: 2026/06/29 11:48:30 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int  check_all_ate(t_sim_data *sim)
{
    int i;

    if (sim->limit_meals == -1)
        return (0);
    i = 0;
    while (i < sim->philo_n)
    {
        pthread_mutex_lock(&sim->dead_lock);
		// printf("DEBUG: philo %d ate %d / %ld\n",
        //     sim->philos[i].id,
        //     sim->philos[i].times_ate,
        //     sim->limit_meals);
        if (sim->philos[i].times_ate < sim->limit_meals)
        {
            pthread_mutex_unlock(&sim->dead_lock);
            return (0);
        }
        pthread_mutex_unlock(&sim->dead_lock);
        i++;
    }
    return (1);
}

static int  check_death(t_sim_data *sim)
{
    int i;

    i = 0;
    while (i < sim->philo_n)
    {
        pthread_mutex_lock(&sim->dead_lock);
        if (conv_to_ms() - sim->philos[i].last_meal_time > sim->time_to_die)
        {
            pthread_mutex_lock(&sim->print_lock);
            printf("%ld %d died\n",
                conv_to_ms() - sim->start_sim,
                sim->philos[i].id);
            pthread_mutex_unlock(&sim->print_lock);
            sim->end_sim = 1;
            pthread_mutex_unlock(&sim->dead_lock);
            return (1);
        }
        pthread_mutex_unlock(&sim->dead_lock);
        i++;
    }
    return (0);
}

void    *monitor_routine(void *arg)
{
    t_sim_data  *sim;

    sim = (t_sim_data *)arg;
    while (1)
    {
        if (check_death(sim))
            return (NULL);
        if (check_all_ate(sim))
        {
            set_end_sim(sim);
            return (NULL);
        }
        usleep(500);
    }
    return (NULL);
}
