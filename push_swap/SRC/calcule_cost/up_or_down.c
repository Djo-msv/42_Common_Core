/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_or_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmassavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 03:36:38 by jmassavi          #+#    #+#             */
/*   Updated: 2024/12/27 03:36:44 by jmassavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

int	upup(t_svars *my_struct, int status)
{
	int	cost;

	if (my_struct->ra >= my_struct->rb)
		cost = my_struct->ra;
	if (my_struct->ra < my_struct->rb)
		cost = my_struct->rb;
	if (status == 1)
	{
		if (my_struct->ra >= my_struct->rb)
		{
			my_struct->ra = my_struct->ra - my_struct->rb;
			my_struct->rr = my_struct->rb;
			my_struct->rb = -1;
		}
		if (my_struct->ra < my_struct->rb)
		{
			my_struct->rb = my_struct->rb - my_struct->ra;
			my_struct->rr = my_struct->ra;
			my_struct->ra = -1;
		}
		my_struct->rra = -1;
		my_struct->rrb = -1;
	}
	return (cost);
}

int	downdown(t_svars *my_struct, int status)
{
	int	cost;

	if (my_struct->rra >= my_struct->rrb)
		cost = my_struct->rra;
	if (my_struct->rra < my_struct->rrb)
		cost = my_struct->rrb;
	if (status == 1)
	{
		if (my_struct->rra >= my_struct->rrb)
		{
			my_struct->rra = my_struct->rra - my_struct->rrb;
			my_struct->rrr = my_struct->rrb;
			my_struct->rrb = -1;
		}
		if (my_struct->rra < my_struct->rrb)
		{
			my_struct->rrb = my_struct->rrb - my_struct->rra;
			my_struct->rrr = my_struct->rra;
			my_struct->rra = -1;
		}
		my_struct->ra = -1;
		my_struct->rb = -1;
	}
	return (cost);
}

int	updown(t_svars *my_struct, int status)
{
	int	cost;

	cost = my_struct->ra + my_struct->rrb;
	if (status == 1)
	{
		my_struct->rb = -1;
		my_struct->rra = -1;
	}
	return (cost);
}

int	downup(t_svars *my_struct, int status)
{
	int	cost;

	cost = my_struct->rb + my_struct->rra;
	if (status == 1)
	{
		my_struct->ra = -1;
		my_struct->rrb = -1;
	}
	return (cost);
}
