/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djo <djo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:20:28 by jmassavi          #+#    #+#             */
/*   Updated: 2025/04/27 18:18:51 by djo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_H
# define THREAD_H

# include "philo.h"

int			start_philo(t_data *data);
void		*philo_thread(void *list);
void		sinc_philo(t_philo *philo);
int			routine_of_a_philosopher(t_philo *philo);

int			init_thread(t_philo *philo);
void		join_thread(t_philo *philo);

int			a_philosopher_is_dead(t_philo *philo);
void		murdered_a_philosopher(t_data *data, int mode);
long long	get_time(t_data *data);

#endif
