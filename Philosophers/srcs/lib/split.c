/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmassavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:09:56 by jmassavi          #+#    #+#             */
/*   Updated: 2025/04/18 21:09:58 by jmassavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*ft_substr(char *s, int start, int len)
{
	char			*result;
	unsigned int	len_result;
	unsigned int	i;

	result = NULL;
	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len_result = 0;
	else if (len < ft_strlen(s) - start)
		len_result = len;
	else
		len_result = ft_strlen(s) - start;
	result = malloc((len_result + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (i < len_result)
	{
		result[i] = s[i + start];
		i++;
	}
	result[i] = '\0';
	return (result);
}

static char	**init_splitted(char *s, char sep)
{
	int		count;
	size_t	i;
	char	**splitted;

	i = 0;
	count = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == sep)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != sep)
			i++;
	}
	splitted = (char **)malloc((count + 1) * sizeof(char *));
	if (!splitted)
		return (NULL);
	splitted[count] = NULL;
	return (splitted);
}

static void	*ft_free(char **splitted, int e)
{
	while (e > 0)
	{
		free(splitted[e]);
		e--;
	}
	free(splitted);
	return (NULL);
}

static size_t	move_to_word_end(char *s, size_t *i, char c)
{
	size_t	j;

	while (s[*i] && s[*i] == c)
		(*i)++;
	j = 0;
	while (s[*i + j] && s[*i + j] != c)
		(j)++;
	return (j);
}

char	**ft_split(char *s, char c)
{
	int		e;
	size_t	i;
	size_t	j;
	char	**splitted;

	i = 0;
	e = 0;
	splitted = init_splitted(s, c);
	if (!splitted)
		return (NULL);
	while (s[i])
	{
		j = move_to_word_end(s, &i, c);
		if (j > 0)
		{
			splitted[e] = ft_substr(s, i, j);
			if (!splitted[e])
				ft_free(splitted, e);
			e++;
		}
		i += j;
	}
	splitted[e] = NULL;
	return (splitted);
}
