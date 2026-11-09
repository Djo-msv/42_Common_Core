/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djo <djo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:20:45 by jmassavi          #+#    #+#             */
/*   Updated: 2025/04/22 00:24:01 by djo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARS_H
# define VARS_H

# include "philo.h"

int		setup_data(t_data **data, int argc, char **argv);

void	free_philo(t_philo *philo);
void	free_data(t_data *data);
void	ft_doublefree(char **str);

#endif
