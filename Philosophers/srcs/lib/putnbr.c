/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmassavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:09:25 by jmassavi          #+#    #+#             */
/*   Updated: 2025/04/18 21:09:28 by jmassavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putnbr(int n)
{
	char	chr;

	if (n == -2147483648)
		write (1, "-2147483648", 11);
	else
	{
		if (n < 0 && n != -2147483648)
		{
			write(1, "-", 1);
			ft_putnbr(n * -1);
		}
		else if (n >= 10)
		{
			ft_putnbr(n / 10);
			ft_putnbr(n % 10);
		}
		else
		{
			chr = (char)n + '0';
			write(1, &chr, 1);
		}
	}
}

void	ft_putnbr_var(char **var, long long n, int i)
{
	while ((*var)[i])
		i++;
	if (n >= 10)
	{
		ft_putnbr_var(var, n / 10, i);
		ft_putnbr_var(var, n % 10, i);
	}
	else
	{
		(*var)[i] = n + '0';
		(*var)[i + 1] = '\0';
	}
}
