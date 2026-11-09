/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djo <djo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:37:48 by jmassavi          #+#    #+#             */
/*   Updated: 2025/01/11 18:16:03 by djo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "MacroLibX/includes/mlx.h"
# include "libft/libft.h"
# include <math.h>
# include <fcntl.h>
#include <stdio.h>

typedef struct	value_s
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	e;
}	value_t;

typedef struct	pnt_s
{
	int	x;
	int	y;
	int	color;
} pnt_t;

typedef struct	ray_s
{
	pnt_t	pnt1;
	pnt_t	pnt2;
} ray_t;


typedef struct	map_s
{
	struct map_s	*down;
	struct map_s	*right;

	int		value;
	int		x;
	int		y;
	int		exist;
} map_t;

typedef struct	rot_s
{
	double	x;
	double	y;
	double	z;
	int	zoom;
	float	level;
	pnt_t	center;
} rot_t;

typedef struct	matrix_s
{
	double	M[3][3];
} matrix_t;

typedef struct	mlx_s
{
	void* mlx;
	void* win;
	matrix_t matrix;
	map_t	*map;
	rot_t	coordinate;
	void* img;
} mlx_t;

int key_hook(int key, void* param);
int mouse_hook(int key, void* param);
int window_hook(int event, void* param);

void	render(mlx_t mlx);
void clear_image(mlx_t *mlx);

void	ray_trace(mlx_t mlx, ray_t ray);

void	project_point(mlx_t mlx);

map_t	*parsing(char **argv);

map_t	*new_map_node(int x, int y, char *value);
void	matrix(matrix_t *tab, rot_t teta);
void	make_coordinate(rot_t *rotation);
void	free_map(map_t *map);

void	ft_doublefree(char **str);

#endif
