/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djo <djo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:36:05 by jmassavi          #+#    #+#             */
/*   Updated: 2025/01/11 19:38:55 by djo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/FdF.h"

map_t	*new_map_node(int x, int y, char *value)
{
	map_t	*new_node;

	new_node = malloc(sizeof(map_t));
	new_node->down = NULL;
	new_node->right = NULL;
	new_node->value = ft_atoi(value);
	new_node->x = x;
	new_node->y = y;
	new_node->exist = 1;
	return (new_node);
}

void	free_map(map_t *map)
{
	map_t	*prev_map;
	map_t	*map_tmp;

	while (map)
	{
		map_tmp = map;
		map = map->down;
		while (map_tmp)
		{
			prev_map = map_tmp;
			map_tmp = map_tmp->right;
			free (prev_map);
		}
	}
}

void	matrix(matrix_t *tab, rot_t teta)
{
	(*tab).M[0][0] = cos(teta.y) * cos(teta.z);
	(*tab).M[0][1] = cos(teta.x) * sin(teta.z) + \
	sin(teta.x) * sin(teta.y) * cos(teta.z);
	(*tab).M[0][2] = sin(teta.x) * sin(teta.z) - \
	cos(teta.x) * sin(teta.y) * cos(teta.z);
	(*tab).M[1][0] = -cos(teta.y) * sin(teta.z);
	(*tab).M[1][1] = cos(teta.x) * cos(teta.z) - \
	sin(teta.x) * sin(teta.y) * sin(teta.z);
	(*tab).M[1][2] = sin(teta.x) * cos(teta.z) + \
	cos(teta.x) * sin(teta.y) * sin(teta.z);
	(*tab).M[2][0] = sin(teta.y);
	(*tab).M[2][1] = -sin(teta.x) * cos(teta.y);
	(*tab).M[2][2] = cos(teta.x) * cos(teta.y);
}

void	make_coordinate(rot_t *coordinate)
{
	(*coordinate).zoom = 25;
	(*coordinate).level = (*coordinate).zoom;
	(*coordinate).x = -33 * M_PI / 180.0;
	(*coordinate).y = -33 * M_PI / 180.0;
	(*coordinate).z = 33 * M_PI / 180.0;
	(*coordinate).center.x = 400;
	(*coordinate).center.y = 400;
}
