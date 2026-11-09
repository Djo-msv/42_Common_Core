/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djo <djo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:07:36 by jmassavi          #+#    #+#             */
/*   Updated: 2025/04/22 00:22:05 by djo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	handle_error(int argc)
{
	if (argc > 4)
		ft_pwarning(TO_MUCH_ARGS, P_RED);
	else
		ft_pwarning(NOT_ENOUGH_ARGS, P_RED);
}

int	main(int argc, char **argv)
{
	char	**arg;
	t_data	*data;

	arg = parsing(argv);
	if (!arg)
		return (1);
	argc = ft_tablen(arg);
	if (argc == 4 || argc == 5)
	{
		if (setup_data(&data, argc, arg))
			return (1);
		if (start_philo(data))
			return (1);
		free_data(data);
	}
	else
	{
		ft_doublefree(arg);
		handle_error(argc);
	}
	return (0);
}
