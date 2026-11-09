/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmassavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:36:52 by jmassavi          #+#    #+#             */
/*   Updated: 2024/10/22 22:36:55 by jmassavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_recursivemem(unsigned long nbr, char *base, int *count)
{
	unsigned long	len;

	len = ft_len(base);
	if (nbr >= len)
	{
		ft_recursivemem(nbr / len, base, count);
		ft_recursivemem(nbr % len, base, count);
	}
	else
		ft_putchr(base[nbr], count);
}

void	ft_putmem(unsigned long nbr, int *count)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	if (!nbr)
	{
		ft_putstr("(nil)", count);
		return ;
	}
	ft_putstr("0x", count);
	ft_recursivemem(nbr, base, count);
}
