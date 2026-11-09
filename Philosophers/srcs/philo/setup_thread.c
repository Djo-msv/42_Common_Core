/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djo <djo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:11:19 by jmassavi          #+#    #+#             */
/*   Updated: 2025/04/27 18:11:59 by djo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_thread(void *list)
{
	t_philo	*philo;
	int		number_of_cycles;

	philo = (t_philo *)list;
	number_of_cycles = 0;
	sinc_philo(philo);
	if (philo->id % 2 == 0)
		ft_sleep(philo, philo->data->t_eat);
	while (number_of_cycles++ != philo->data->n_eat)
	{
		if (routine_of_a_philosopher(philo))
			break ;
	}
	pthread_mutex_lock(philo->t_die_mutex);
	if (philo != philo->next)
		philo->time_of_death = -1;
	pthread_mutex_unlock(philo->t_die_mutex);
	return (NULL);
}

int	init_thread(t_philo *philo)
{
	int	start_loop;

	start_loop = 1;
	pthread_mutex_lock((philo)->data->start_mutex);
	while (philo->id != 0 || start_loop)
	{
		start_loop = 0;
		if (pthread_create(&philo->thread_t, NULL, philo_thread, philo))
		{
			pthread_mutex_unlock(philo->data->start_mutex);
			murdered_a_philosopher(philo->data, 0);
			join_thread(philo->data->philo);
			ft_perror(philo->data, "thread fail", P_RED);
			return (1);
		}
		philo = philo->next;
	}
	pthread_mutex_unlock((philo)->data->start_mutex);
	return (0);
}

void	join_thread(t_philo *philo)
{
	int	start_loop;

	start_loop = 1;
	while (philo->id != 0 || start_loop)
	{
		start_loop = 0;
		pthread_join(philo->thread_t, NULL);
		philo = philo->next;
	}
}
