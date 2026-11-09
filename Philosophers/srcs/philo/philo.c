/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djo <djo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:11:14 by jmassavi          #+#    #+#             */
/*   Updated: 2025/04/27 18:15:33 by djo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_fork(t_philo *philo)
{
	if (philo == philo->next)
	{
		print_philo(philo->print, get_time(philo->data), philo->id, TAKEN_FORK);
		return (1);
	}
	pthread_mutex_lock(philo->fork);
	if (a_philosopher_is_dead(philo))
	{
		pthread_mutex_unlock(philo->fork);
		return (1);
	}
	print_philo(philo->print, get_time(philo->data), philo->id, TAKEN_FORK);
	return (0);
}

int	take_next_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->next->fork);
	if (a_philosopher_is_dead(philo))
	{
		pthread_mutex_unlock(philo->next->fork);
		return (1);
	}
	print_philo(philo->print, get_time(philo->data), philo->id, TAKEN_FORK);
	return (0);
}

int	take_both_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		if (take_fork(philo))
			return (1);
		if (take_next_fork(philo))
		{
			pthread_mutex_unlock(philo->fork);
			return (1);
		}
	}
	else
	{
		if (take_next_fork(philo))
			return (1);
		if (take_fork(philo))
		{
			pthread_mutex_unlock(philo->next->fork);
			return (1);
		}
	}
	return (0);
}

void	handle_fork(t_philo *philo)
{
	if (philo->id % 2 != 0)
		pthread_mutex_unlock(philo->fork);
	pthread_mutex_unlock(philo->next->fork);
	if ((philo->id % 2 == 0))
		pthread_mutex_unlock(philo->fork);
}

int	routine_of_a_philosopher(t_philo *philo)
{
	if (take_both_fork(philo))
		return (1);
	philo->time = get_time(philo->data);
	print_philo(philo->print, philo->time, philo->id, EATING);
	ft_sleep(philo, philo->data->t_eat);
	if (a_philosopher_is_dead(philo))
	{
		handle_fork(philo);
		return (1);
	}
	handle_fork(philo);
	pthread_mutex_lock(philo->t_die_mutex);
	philo->time_of_death = get_time(philo->data) + philo->data->t_die;
	pthread_mutex_unlock(philo->t_die_mutex);
	if (a_philosopher_is_dead(philo))
		return (1);
	print_philo(philo->print, philo->time, philo->id, SLEEPING);
	ft_sleep(philo, philo->data->t_sleep);
	if (a_philosopher_is_dead(philo))
		return (1);
	print_philo(philo->print, philo->time, philo->id, THINKING);
	return (0);
}
