/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djo <djo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:08:03 by jmassavi          #+#    #+#             */
/*   Updated: 2025/04/22 00:36:05 by djo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(t_data *data, const char *nptr)
{
	int			i;
	long long	r;

	i = 0;
	r = 0;
	while ((nptr[i] == ' ' || nptr[i] == '+'))
		i++;
	if (nptr[i] == 45)
	{
		ft_perror(data, "negate input", P_RED);
		return (-1);
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		r = (r * 10) + (nptr[i++] - '0');
		if (r > MAX_INT)
		{
			ft_perror(data, "too high value", P_RED);
			return (-1);
		}
	}
	return (r);
}
