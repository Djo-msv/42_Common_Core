/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djo <djo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:49:17 by djo               #+#    #+#             */
/*   Updated: 2025/01/11 17:09:29 by djo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/FdF.h"

void	press_key(int key, mlx_t *mlx)
{
	if (key == 26)
		(*mlx).coordinate.x -= 0.1;
	if (key == 22)
		(*mlx).coordinate.x += 0.1;
	if (key == 7)
		(*mlx).coordinate.y -= 0.1;
	if (key == 4)
		(*mlx).coordinate.y += 0.1;
	if (key == 8)
		(*mlx).coordinate.z -= 0.1;
	if (key == 20)
		(*mlx).coordinate.z += 0.1;
	if (key == 87)
		(*mlx).coordinate.level += 1;
	if (key == 86)
		(*mlx).coordinate.level -= 1;
	if (key == 81)
		(*mlx).coordinate.center.y += 5;
	if (key == 82)
		(*mlx).coordinate.center.y -= 5;
	if (key == 79)
		(*mlx).coordinate.center.x += 5;
	if (key == 80)
		(*mlx).coordinate.center.x -= 5;
}

int	key_hook(int key, void *param)
{
	mlx_t	*mlx;

	mlx = (mlx_t *)param;
	clear_image(mlx);
	if (key == 41)
		mlx_loop_end((*mlx).mlx);
	press_key(key, mlx);
	render((*mlx));
	param = mlx;
	return (0);
}

int	mouse_hook(int key, void *param)
{
	mlx_t	*mlx;

	mlx = (mlx_t *)param;
	clear_image(mlx);
	if (key == 1)
	{
		(*mlx).coordinate.level = (*mlx).coordinate.level / \
		(*mlx).coordinate.zoom;
		(*mlx).coordinate.zoom += 1;
		(*mlx).coordinate.level *= (*mlx).coordinate.zoom;
	}
	if (key == 2 && (*mlx).coordinate.zoom > 1)
	{
		(*mlx).coordinate.level = (*mlx).coordinate.level / \
		(*mlx).coordinate.zoom;
		(*mlx).coordinate.zoom -= 1;
		(*mlx).coordinate.level *= (*mlx).coordinate.zoom;
	}
	render((*mlx));
	param = mlx;
	return (0);
}

int	window_hook(int event, void *param)
{
	mlx_t	mlx;

	mlx = *(mlx_t *)param;
	if (event == 0)
		mlx_loop_end(mlx.mlx);
	return (0);
}
