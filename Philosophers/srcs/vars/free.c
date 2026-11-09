/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djo <djo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:12:03 by jmassavi          #+#    #+#             */
/*   Updated: 2025/04/27 18:26:02 by djo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philo(t_philo *philo)
{
	t_philo	*to_kill;

	if (!philo)
		return ;
	while (philo->next)
	{
		to_kill = philo;
		if (philo->data->n_philo - 1 != (int)philo->id)
			philo = philo->next;
		if (to_kill->fork)
			pthread_mutex_destroy(to_kill->fork);
		if (to_kill->die_mutex)
			pthread_mutex_destroy(to_kill->die_mutex);
		if (to_kill->t_die_mutex)
			pthread_mutex_destroy(to_kill->t_die_mutex);
		free(to_kill->print);
		free(to_kill->fork);
		free(to_kill->die_mutex);
		free(to_kill->t_die_mutex);
		free(to_kill);
		if (to_kill == philo)
			break ;
	}
}

void	free_data(t_data *data)
{
	if (!data)
		return ;
	if (data && data->philo)
		free_philo(data->philo);
	if (data->start_mutex)
	{
		pthread_mutex_destroy(data->start_mutex);
		free(data->start_mutex);
	}
	free(data);
}

void	ft_doublefree(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free (str[i]);
		i++;
	}
	free (str);
	str = NULL;
}
