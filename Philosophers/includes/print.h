/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djo <djo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:19:54 by jmassavi          #+#    #+#             */
/*   Updated: 2025/04/26 15:41:06 by djo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "philo.h"

# define TO_MUCH_ARGS "to much argument :\nphilo take the following arguments: \
\n[number_of_philosophers] [time_to_die time_to_eat] [time_to_sleep] \
[number_of_times_each_philosopher_must_eat]"
# define NOT_ENOUGH_ARGS "not enough argument :\nphilo take the following arguments: \
\n[number_of_philosophers] [time_to_die time_to_eat] [time_to_sleep] \
[number_of_times_each_philosopher_must_eat]"

# define WARNING_ABOVE_200 "/!\\ values above 200 philosophers can cause slowdowns \
or even crashes /!\\"

# define TAKEN_FORK "has taken a fork 🍴"
# define EATING "is eating 🍕"
# define SLEEPING "is sleeping 😴"
# define THINKING "is thinking 🤔"
# define DEATH_MSG "is dead 💀💀💀"

/*
# define TAKEN_FORK "has taken a fork"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define DEATH_MSG "id dead"
*/

void	handle_error(int argv);
void	ft_perror(t_data *data, char *str, char *color);
void	ft_pwarning(char *str, char *color);

void	print_die_message(int time, int id);
void	print_philo(char *result, long long time, int id, char *msg);

#endif
