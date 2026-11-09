/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmassavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:09:47 by jmassavi          #+#    #+#             */
/*   Updated: 2025/04/18 21:09:49 by jmassavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(t_philo *philo, unsigned int time)
{
	long long	end;

	end = get_time(philo->data) + time;
	while (get_time(philo->data) < end)
	{
		if (a_philosopher_is_dead(philo))
		{
			break ;
		}
		usleep(100);
	}
	philo->time = end;
}
