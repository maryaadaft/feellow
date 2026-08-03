/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 17:58:11 by maryaada          #+#    #+#             */
/*   Updated: 2026/08/03 14:20:19 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	set_end_sim(t_sim_data *sim)
{
	pthread_mutex_lock(&sim->dead_lock);
	sim->end_sim = 1;
	pthread_mutex_unlock(&sim->dead_lock);
}

int	check_end_sim(t_sim_data *sim)
{
	int	status;

	pthread_mutex_lock(&sim->dead_lock);
	status = sim->end_sim;
	pthread_mutex_unlock(&sim->dead_lock);
	return (status);
}

void	print_action(t_philo *philo, char *action)
{
	if (check_end_sim(philo->sim_data))
		return ;
	pthread_mutex_lock(&philo->sim_data->print_lock);
	printf("%ld %d %s\n",
		conv_to_ms() - philo->sim_data->start_sim,
		philo->id,
		action);
	pthread_mutex_unlock(&philo->sim_data->print_lock);
}
