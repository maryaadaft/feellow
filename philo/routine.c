/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 13:45:34 by maryaada          #+#    #+#             */
/*   Updated: 2026/06/22 13:48:29 by maryaada         ###   ########.fr       */
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
	}
}