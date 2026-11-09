/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djo <djo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:12:15 by jmassavi          #+#    #+#             */
/*   Updated: 2025/04/26 15:42:24 by djo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_value(t_data *data, int argc, char **argv)
{
	data->n_philo = ft_atoi(NULL, argv[0]);
	if (data->n_philo == -1)
		return (1);
	data->t_die = ft_atoi(NULL, argv[1]);
	if (data->t_die == -1)
		return (1);
	data->t_eat = ft_atoi(NULL, argv[2]);
	if (data->t_eat == -1)
		return (1);
	data->t_sleep = ft_atoi(NULL, argv[3]);
	if (data->t_sleep == -1)
		return (1);
	if (argc == 5)
	{
		data->n_eat = ft_atoi(NULL, argv[4]);
		if (data->n_eat == -1)
			return (1);
	}
	else
		data->n_eat = -1;
	return (0);
}

int	check_value(t_data *data)
{
	if (data->n_eat == 0)
	{
		ft_perror(data, "philosophers should eat at least once", P_RED);
		return (1);
	}
	if (data->n_philo > 200)
		ft_pwarning(WARNING_ABOVE_200, P_YELLOW);
	else if (data->n_philo == 0)
	{
		ft_perror(data, "you must have at least 1 philosopher", P_RED);
		return (1);
	}
	return (0);
}

void	setup_alloc(t_data **data)
{
	(*data) = malloc(sizeof(t_data));
	if (!data)
		return ;
	(*data)->philo = NULL;
	(*data)->start_mutex = malloc(sizeof(pthread_mutex_t));
	if ((*data)->start_mutex)
		pthread_mutex_init((*data)->start_mutex, NULL);
}

int	setup_data(t_data **data, int argc, char **argv)
{
	setup_alloc(data);
	if (!data)
		return (1);
	if (!(*data)->start_mutex)
	{
		ft_doublefree(argv);
		ft_perror((*data), "allocation fail !", P_RED);
		return (1);
	}
	gettimeofday(&(*data)->time, NULL);
	if (set_value((*data), argc, argv))
	{
		free_data(*data);
		ft_doublefree(argv);
		return (1);
	}
	ft_doublefree(argv);
	if (check_value(*data))
		return (1);
	if (create_philo(data))
		return (1);
	return (0);
}
