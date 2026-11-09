/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djo <djo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 20:01:44 by jmassavi          #+#    #+#             */
/*   Updated: 2025/01/11 20:17:31 by djo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/FdF.h"

map_t	*creat_unique_line(char **line, int x, int y)
{
	map_t		*new_node;
	map_t		*tmp_map;

	tmp_map = new_map_node(x, y, line[x]);
	new_node = tmp_map;
	while (line[x + 1])
	{
		x++;
		tmp_map->right = new_map_node(x, y, line[x]);
		tmp_map = tmp_map->right;
	}
	return (new_node);
}

map_t	*creat_line_map(char **line, map_t **map)
{
	int			x;
	static int	y = 0;
	map_t		*new_node;
	map_t		*tmp_map;

	x = 0;
	if (!map)
		return (creat_unique_line(line, x, y));
	tmp_map = *map;
	y++;
	tmp_map->down = new_map_node(x, y, line[x]);
	while (tmp_map->right)
	{
		x++;
		new_node = new_map_node(x, y, line[x]);
		tmp_map->down->right = new_node;
		tmp_map->right->down = new_node;
		tmp_map = tmp_map->right;
	}
	return (NULL);
}

void	creat_map(map_t **map, char **line)
{
	map_t	*tmp_map;

	tmp_map = *map;
	if (!*map)
	{
		*map = creat_line_map(line, NULL);
		ft_doublefree(line);
		return ;
	}
	while ((*map)->down)
		(*map) = (*map)->down;
	creat_line_map(line, map);
	(*map) = tmp_map;
	ft_doublefree(line);
}

char	*del_last_one(char *line)
{
	int		i;
	char	*new_line;

	i = 0;
	if (ft_strchr(line, '\n') != NULL)
	{
		new_line = ft_calloc(ft_strlen(line), 1);
		while (line[i + 1])
		{
			new_line[i] = line[i];
			i++;
		}
		free (line);
		return (new_line);
	}
	return (line);
}

map_t	*parsing(char **argv)
{
	int		fd;
	char	*line;
	map_t	*map;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(1);
	line = get_next_line(fd);
	map = NULL;
	while (line)
	{
		line = del_last_one(line);
		creat_map(&map, ft_split(line, ' '));
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}
