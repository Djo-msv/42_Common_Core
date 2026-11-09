/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmassavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:25:58 by jmassavi          #+#    #+#             */
/*   Updated: 2024/12/19 14:26:01 by jmassavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../Includes/push_swap.h"

int	checksize(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str[i] == '-' || str[i] == '-')
		i++;
	while (str[i] == '0')
		i++;
	while (str[i++])
		count++;
	if (count >= 12)
		return (0);
	if (ft_atol(str) > 2147483647 || ft_atol(str) < -2147483648)
		return (0);
	return (1);
}

int	checkdup(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[j])
		{
			if ((ft_atol(av[i]) == ft_atol(av[j])) && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	checkargv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_isnumber(argv[i]) == 0)
			return (0);
		if (checksize(argv[i]) == 0)
			return (0);
		i++;
	}
	if (checkdup(argv) == 0)
		return (0);
	return (1);
}
