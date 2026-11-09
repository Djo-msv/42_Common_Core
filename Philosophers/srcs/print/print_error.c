/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djo <djo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:11:32 by jmassavi          #+#    #+#             */
/*   Updated: 2025/04/22 00:04:50 by djo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_perror(t_data *data, char *str, char *color)
{
	write(2, color, ft_strlen(color));
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	write(2, P_NOC_PROMPT, ft_strlen(P_NOC_PROMPT));
	free_data(data);
}

void	ft_pwarning(char *str, char *color)
{
	write(2, color, ft_strlen(color));
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	write(2, P_NOC_PROMPT, ft_strlen(P_NOC_PROMPT));
}
