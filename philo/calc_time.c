/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 11:54:22 by maryaada          #+#    #+#             */
/*   Updated: 2026/06/22 12:13:13 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	conv_to_ms(void)
{
	struct timeval time_now;
	long	total_time;

	gettimeofday(&time_now, NULL);
	total_time = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
	return (total_time);
}

void    safe_usleep(long ms)
{
    long    start;

    start = conv_to_ms();
    while (conv_to_ms() - start < ms)
        usleep(500);
}