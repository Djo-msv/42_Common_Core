/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djo <djo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:19:45 by jmassavi          #+#    #+#             */
/*   Updated: 2025/01/11 18:21:38 by djo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/FdF.h"

void	loop_ray_trace(mlx_t mlx, ray_t ray, value_t val)
{
	while (0 == 0)
	{
		if ((ray.pnt1.x < 800 && ray.pnt1.x >= 0) && \
		(ray.pnt1.y < 800 && ray.pnt1.y >= 0))
			mlx_set_image_pixel(mlx.mlx, mlx.img, ray.pnt1.x, ray.pnt1.y, \
			ray.pnt1.color);
		if (ray.pnt1.x == ray.pnt2.x && ray.pnt1.y == ray.pnt2.y)
			break ;
		if ((2 * val.e) >= val.dy)
		{
			if (ray.pnt1.x == ray.pnt2.x)
				break ;
			val.e = val.e + val.dy;
			ray.pnt1.x = ray.pnt1.x + val.sx;
		}
		if ((2 * val.e) <= val.dx)
		{
			if (ray.pnt1.y == ray.pnt2.y)
				break ;
			val.e = val.e + val.dx;
			ray.pnt1.y = ray.pnt1.y + val.sy;
		}
	}
}

void	ray_trace(mlx_t mlx, ray_t ray)
{
	value_t	val;

	val.dx = abs(ray.pnt2.x - ray.pnt1.x);
	if (ray.pnt1.x < ray.pnt2.x)
		val.sx = 1;
	else
		val.sx = -1;
	val.dy = abs(ray.pnt2.y - ray.pnt1.y) * -1;
	if (ray.pnt1.y < ray.pnt2.y)
		val.sy = 1;
	else
		val.sy = -1;
	val.e = val.dx + val.dy;
	loop_ray_trace(mlx, ray, val);
}
