/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 17:58:11 by maryaada          #+#    #+#             */
/*   Updated: 2026/05/11 14:23:59 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
		i++;
	return (i);
}

void    print_error(char *msg)
{
	write(2, "\n=================================\n", 35);
	write(2, msg, ft_strlen(msg));
	write(2, "\n=================================\n", 35);
	exit(1); //exit the program with failure code 1;

}

