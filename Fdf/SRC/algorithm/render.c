/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djo <djo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:51:30 by djo               #+#    #+#             */
/*   Updated: 2025/01/11 17:13:36 by djo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/FdF.h"

void	render(mlx_t mlx)
{
	matrix_t	tab;

	matrix(&tab, mlx.coordinate);
	mlx.matrix = tab;
	project_point(mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
}

void	clear_image(mlx_t *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i != 800)
	{
		j = 0;
		while (j != 800)
			mlx_set_image_pixel((*mlx).mlx, (*mlx).img, i, j++, 0xFF000000);
		i++;
	}
}
