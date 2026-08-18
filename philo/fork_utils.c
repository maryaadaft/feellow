/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 12:53:39 by maryaada          #+#    #+#             */
/*   Updated: 2026/08/18 14:20:54 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_forks(t_philo *philo)
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

void	release_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
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
