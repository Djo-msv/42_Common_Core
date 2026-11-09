/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djo <djo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:20:05 by jmassavi          #+#    #+#             */
/*   Updated: 2025/01/11 17:11:19 by djo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/FdF.h"

mlx_t	__setup(void)
{
	mlx_t	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 800, 800, "FdF");
	mlx_set_fps_goal(mlx.mlx, 60);
	return (mlx);
}

void	__loop(mlx_t mlx)
{
	mlx_loop(mlx.mlx);
	mlx_destroy_image(mlx.mlx, mlx.img);
	mlx_destroy_window(mlx.mlx, mlx.win);
	mlx_destroy_display(mlx.mlx);
}

int	update(void *param)
{
	mlx_t	mlx;

	mlx = *(mlx_t *)param;
	mlx_on_event(mlx.mlx, mlx.win, MLX_WINDOW_EVENT, window_hook, param);
	mlx_on_event(mlx.mlx, mlx.win, MLX_KEYDOWN, key_hook, param);
	mlx_on_event(mlx.mlx, mlx.win, MLX_MOUSEWHEEL, mouse_hook, param);
	return (0);
}

int	main(int ac, char **av)
{
	mlx_t	mlx;
	map_t	*map;
	rot_t	coordinate;

	(void)ac;
	mlx = __setup();
	map = parsing(av);
	make_coordinate(&coordinate);
	mlx.coordinate = coordinate;
	mlx.map = map;
	mlx.img = mlx_new_image(mlx.mlx, 800, 800);
	render(mlx);
	mlx_loop_hook(mlx.mlx, update, &mlx);
	__loop(mlx);
	free_map(map);
	return (0);
}
