/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmassavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:09:34 by jmassavi          #+#    #+#             */
/*   Updated: 2025/04/18 21:09:36 by jmassavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr(char *s)
{
	int	len;

	if (!s)
		return ;
	len = ft_strlen(s);
	write(1, s, len);
}

void	ft_putstr_var(char **var, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((*var)[i])
		i++;
	while (str[j])
		(*var)[i++] = str[j++];
	(*var)[i] = '\0';
}
