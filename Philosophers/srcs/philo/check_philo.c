/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djo <djo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:10:54 by jmassavi          #+#    #+#             */
/*   Updated: 2025/04/26 15:50:39 by djo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sinc_philo(t_philo *philo)
{
	pthread_mutex_lock((philo)->data->start_mutex);
	pthread_mutex_unlock((philo)->data->start_mutex);
	pthread_mutex_lock(philo->t_die_mutex);
	philo->time_of_death = get_time(philo->data) + philo->data->t_die;
	pthread_mutex_unlock(philo->t_die_mutex);
}

int	a_philosopher_is_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->die_mutex);
	if (philo->die == true)
	{
		pthread_mutex_unlock(philo->die_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->die_mutex);
	return (0);
}

void	murdered_a_philosopher(t_data *data, int mode)
{
	t_philo	*philo;

	philo = data->philo;
	pthread_mutex_lock(philo->die_mutex);
	while (philo->die != true)
	{
		philo->die = true;
		pthread_mutex_unlock(philo->die_mutex);
		philo = philo->next;
		pthread_mutex_lock(philo->die_mutex);
	}
	pthread_mutex_unlock(philo->die_mutex);
	if (mode)
		print_die_message(get_time(data), philo->id);
}

long long	get_time(t_data *data)
{
	struct timeval	time;
	long long		sec;
	long long		usec;

	gettimeofday(&time, NULL);
	sec = time.tv_sec - data->time.tv_sec;
	usec = sec * 1000000;
	usec = usec + (time.tv_usec - data->time.tv_usec);
	return (usec / 1000);
}

int	start_philo(t_data *data)
{
	t_philo	*philo;

	philo = data->philo;
	if (init_thread(philo))
		return (1);
	while (1)
	{
		pthread_mutex_lock(philo->t_die_mutex);
		if (philo->time_of_death < 0)
		{
			pthread_mutex_unlock(philo->t_die_mutex);
			break ;
		}
		if (philo->time_of_death < get_time(data))
		{
			pthread_mutex_unlock(philo->t_die_mutex);
			murdered_a_philosopher(data, 1);
			break ;
		}
		pthread_mutex_unlock(philo->t_die_mutex);
		usleep(10);
		philo = philo->next;
	}
	join_thread(data->philo);
	return (0);
}
