/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djo <djo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:10:25 by jmassavi          #+#    #+#             */
/*   Updated: 2025/04/22 00:36:55 by djo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	checksize(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	while (str[i++])
		count++;
	if (count >= 11)
		return (0);
	return (1);
}

int	ft_isdigit(int caract)
{
	if (caract >= '0' && caract <= '9')
		return (2048);
	else
		return (0);
}

int	check_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	if (i == 1 && (str[0] == '-' || str[0] == '+'))
		return (0);
	return (1);
}

int	checkargv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (check_number(argv[i]) == 0)
			return (1);
		if (checksize(argv[i]) == 0)
			return (2);
		i++;
	}
	return (0);
}
