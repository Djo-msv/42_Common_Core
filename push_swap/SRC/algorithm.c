/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmassavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 03:54:09 by jmassavi          #+#    #+#             */
/*   Updated: 2024/12/27 03:54:15 by jmassavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

t_svars	*recursive(t_list *pile_a, t_list *pile_b)
{
	t_svars	*my_struct1;
	t_svars	*my_struct2;

	my_struct1 = calculate_cost(&pile_a, &pile_b);
	minimum_cost(my_struct1);
	if (pile_a->next == NULL)
		return (my_struct1);
	my_struct2 = recursive(pile_a->next, pile_b);
	if (my_struct1->cost < my_struct2->cost)
	{
		free(my_struct2);
		return (my_struct1);
	}
	else
	{
		free(my_struct1);
		return (my_struct2);
	}
}

void	sort(t_list *pile_a, t_list *pile_b)
{
	t_svars	*stuct;

	initialization(&pile_a, &pile_b);
	while (pile_a)
	{
		stuct = recursive(pile_a, pile_b);
		make_instruction(&pile_a, &pile_b, stuct);
		free(stuct);
	}
	put_in_a(&pile_a, &pile_b);
	pop_all(&pile_a);
	pop_all(&pile_b);
}
