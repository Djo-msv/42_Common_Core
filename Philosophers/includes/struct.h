/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djo <djo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:20:07 by jmassavi          #+#    #+#             */
/*   Updated: 2025/04/26 15:41:16 by djo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "philo.h"

typedef struct s_philo
{
	pthread_t		thread_t;
	unsigned int	id;
	long long		time_of_death;
	long long		time;
	bool			die;
	char			*print;
	pthread_mutex_t	*die_mutex;
	pthread_mutex_t	*t_die_mutex;
	pthread_mutex_t	*fork;
	struct s_data	*data;
	struct s_philo	*next;
}	t_philo;

typedef struct s_data
{
	pthread_mutex_t	*start_mutex;
	struct timeval	time;
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_eat;
	t_philo			*philo;
}	t_data;

#endif
