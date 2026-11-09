/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_min_cost.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmassavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 03:37:38 by jmassavi          #+#    #+#             */
/*   Updated: 2024/12/27 03:37:41 by jmassavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	change_struct(int value, t_svars *my_struct)
{
	if (value == 1)
		upup(my_struct, 1);
	if (value == 2)
		downdown(my_struct, 1);
	if (value == 3)
		updown(my_struct, 1);
	if (value == 4)
		downup(my_struct, 1);
}

void	minimum_cost(t_svars *my_struct)
{
	int	value;

	if (my_struct->cost != 2147483647)
		return ;
	if (upup(my_struct, 0) != 0 && upup(my_struct, 0) < my_struct->cost)
	{
		my_struct->cost = upup(my_struct, 0);
		value = 1;
	}
	if (downdown(my_struct, 0) != 0 && downdown(my_struct, 0) < my_struct->cost)
	{
		my_struct->cost = downdown(my_struct, 0);
		value = 2;
	}
	if (updown(my_struct, 0) != 0 && updown(my_struct, 0) < my_struct->cost)
	{
		my_struct->cost = updown(my_struct, 0);
		value = 3;
	}
	if (downup(my_struct, 0) != 0 && downup(my_struct, 0) < my_struct->cost)
	{
		my_struct->cost = downup(my_struct, 0);
		value = 4;
	}
	change_struct(value, my_struct);
}
