/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmassavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 08:31:30 by jmassavi          #+#    #+#             */
/*   Updated: 2024/12/19 08:31:31 by jmassavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

int	is_sorted(char **argv)
{
	int	i;
	int	value;
	
	i = 0;
	value = -2147483648;
	while (argv[i])
	{
		if (value > ft_atol(argv[i]))
			return (1);
		value = ft_atol(argv[i]);
		i++;
	}
	return (0);
}

void	ft_doublefree(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free (str[i]);
		i++;
	}
	free (str);
	str = NULL;
}

char	*ft_join(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	if (!str1 || !str2)
		return (NULL);
	result = ft_calloc(ft_strlen(str1) + ft_strlen(str2) + 1, sizeof(char));
	if (!result)
		return (NULL);
	while (str1[i])
	{
		result[i] = str1[i];
		i++;
	}
	while (str2[j])
		result[i++] = str2[j++];
	free(str1);
	return (result);
}

char	**pars(char **argv)
{
	int	i;
	char	*result;
	char	**tab;

	i = 1;
	result = ft_calloc(1, sizeof(char));
	while (argv[i])
	{
		result = ft_join(result, argv[i]);
		result = ft_join(result, " ");
		i++;
	}
	tab = ft_split(result, ' ');
	free (result);
	return (tab);
}

int	parsing(t_list	**pile_a, char **argv)
{
	int	i;
	char	**arg;

	arg = pars(argv);
	i = 0;
	if (checkargv(arg) == 0)
	{
		write(2, "Error\n", 6);
		ft_doublefree(arg);
		exit(1);
	}
	if (is_sorted(arg) == 0)
	{
		ft_doublefree(arg);
		exit(1);
	}
	while (arg[i])
	{
		push_back(pile_a, ft_atol(arg[i]));
		i++;
	}
	ft_doublefree(arg);
	return (i);
}
