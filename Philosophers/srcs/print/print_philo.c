/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djo <djo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:11:50 by jmassavi          #+#    #+#             */
/*   Updated: 2025/04/26 15:40:19 by djo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_die_message(int time, int id)
{
	usleep(500);
	printf("%s[%d]%s %d %s%s%s\n", \
	P_GREEN, time, P_TEAL, id, P_RED, DEATH_MSG, P_NOC);
}

int	calcule_size(int time, int id, char *msg)
{
	int	len;

	len = ft_intlen(time);
	len += ft_intlen(id);
	len += ft_strlen(msg);
	len += 30;
	return (len);
}

void	print_philo(char *result, long long time, int id, char *msg)
{
	int	len;

	result[0] = '\0';
	len = calcule_size(time, id, msg);
	ft_putstr_var(&result, P_GREEN);
	ft_putstr_var(&result, "[");
	ft_putnbr_var(&result, time, 0);
	ft_putstr_var(&result, "]");
	ft_putstr_var(&result, P_TEAL);
	ft_putstr_var(&result, " ");
	ft_putnbr_var(&result, id, 0);
	ft_putstr_var(&result, " ");
	ft_putstr_var(&result, P_PINK);
	ft_putstr_var(&result, msg);
	ft_putstr_var(&result, P_NOC);
	ft_putstr_var(&result, "\n");
	write(1, result, len);
}
