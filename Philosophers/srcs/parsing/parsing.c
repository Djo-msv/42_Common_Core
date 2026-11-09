/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djo <djo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:10:30 by jmassavi          #+#    #+#             */
/*   Updated: 2025/04/22 00:32:39 by djo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*ft_join(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	if (!str1 || !str2)
		return (NULL);
	result = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!result)
	{
		free(str1);
		return (NULL);
	}
	while (str1[i])
	{
		result[i] = str1[i];
		i++;
	}
	while (str2[j])
		result[i++] = str2[j++];
	result[i] = '\0';
	free(str1);
	return (result);
}

char	**pars(char **argv)
{
	int		i;
	char	*result;
	char	**tab;

	i = 0;
	result = malloc(1);
	result[0] = '\0';
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

char	**parsing(char **argv)
{
	int		code;
	char	**arg;

	arg = pars(&argv[1]);
	if (!arg)
		return (NULL);
	code = checkargv(arg);
	if (code != 0)
	{
		ft_doublefree(arg);
		if (code == 1)
			ft_perror(NULL, ARG_NUM, P_RED);
		if (code == 2)
			ft_perror(NULL, OVERFLOW, P_RED);
		return (NULL);
	}
	return (arg);
}
