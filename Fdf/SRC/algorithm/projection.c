/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djo <djo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 23:26:50 by jmassavi          #+#    #+#             */
/*   Updated: 2025/01/11 17:38:07 by djo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/FdF.h"

void	calcule(map_t *input, pnt_t *output, mlx_t mlx)
{
	(*output).x = ((mlx.matrix.M[0][0] * (input->x * mlx.coordinate.zoom)) \
	+ (mlx.matrix.M[0][1] * (input->y * mlx.coordinate.zoom)) + \
	(mlx.matrix.M[0][2] * (input->value * mlx.coordinate.level)));
	(*output).y = ((mlx.matrix.M[1][0] * (input->x * mlx.coordinate.zoom)) \
	+ (mlx.matrix.M[1][1] * (input->y * mlx.coordinate.zoom)) + \
	(mlx.matrix.M[1][2] * (input->value * mlx.coordinate.level)));
	(*output).x += mlx.coordinate.center.x;
	(*output).y += mlx.coordinate.center.y;
}

void	create_ray(mlx_t mlx, map_t *pnt1, map_t *pnt2)
{
	ray_t	ray;

	ray.pnt1.color = 0xFFFFFFFF;
	calcule(pnt1, &ray.pnt1, mlx);
	calcule(pnt2, &ray.pnt2, mlx);
	ray_trace(mlx, ray);
}

void	put_node_center(map_t **map_tmp, map_t *map)
{
	int		i;
	map_t	*map_re;

	i = 0;
	(*map_tmp) = map;
	while ((*map_tmp))
	{
		i++;
		(*map_tmp) = (*map_tmp)->right;
	}
	i = (i / 2);
	(*map_tmp) = map;
	while ((*map_tmp)->x != i)
		(*map_tmp) = (*map_tmp)->right;
	map_re = (*map_tmp);
	i = 0;
	while ((*map_tmp))
	{
		i++;
		(*map_tmp) = (*map_tmp)->down;
	}
	i = (i / 2);
	(*map_tmp) = map_re;
	while ((*map_tmp)->y != i)
		(*map_tmp) = (*map_tmp)->down;
}

void	calcul_center(map_t *map, mlx_t *mlx)
{
	pnt_t	position;
	map_t	*map_tmp;

	put_node_center(&map_tmp, map);
	position.x = (((*mlx).matrix.M[0][0] * (map_tmp->x * \
	(*mlx).coordinate.zoom)) + ((*mlx).matrix.M[0][1] * \
	(map_tmp->y * (*mlx).coordinate.zoom)));
	position.y = (((*mlx).matrix.M[1][0] * (map_tmp->x * \
	(*mlx).coordinate.zoom)) + ((*mlx).matrix.M[1][1] * \
	(map_tmp->y * (*mlx).coordinate.zoom)));
	(*mlx).coordinate.center.x += 400 - position.x - 400;
	(*mlx).coordinate.center.y += 400 - position.y - 400;
}

void	project_point(mlx_t mlx)
{
	map_t	*line_map;
	map_t	*tmp_map;

	line_map = mlx.map;
	calcul_center(mlx.map, &mlx);
	while (line_map)
	{
		tmp_map = line_map;
		while (tmp_map)
		{
			if (tmp_map->right)
				create_ray(mlx, tmp_map, tmp_map->right);
			if (tmp_map->down)
				create_ray(mlx, tmp_map, tmp_map->down);
			tmp_map = tmp_map->right;
		}
		line_map = line_map->down;
	}
}
