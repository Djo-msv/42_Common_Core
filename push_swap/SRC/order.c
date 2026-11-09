/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmassavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 03:20:55 by jmassavi          #+#    #+#             */
/*   Updated: 2024/12/27 03:20:57 by jmassavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	move_list(int up_count, int down_count, t_list **pile_b)
{
	if (up_count < down_count)
	{
		while (up_count > 0)
		{
			up_count--;
			ft_printf("rb\n");
			rb(pile_b);
		}
	}
	else
	{
		while (down_count > 0)
		{
			down_count--;
			ft_printf("rrb\n");
			rrb(pile_b);
		}
	}
}

void	count_file(t_list *value, t_list **pile_b)
{
	int		up_count;
	int		down_count;
	t_list	*pile_tmp;

	up_count = 0;
	down_count = 1;
	pile_tmp = value;
	while (pile_tmp->next)
	{
		down_count++;
		pile_tmp = pile_tmp->next;
	}
	while (value->prev)
	{
		up_count++;
		value = value->prev;
	}
	move_list(up_count, down_count, pile_b);
}

void	put_order(t_list **pile_b)
{
	t_list	*value;
	t_list	*pile_tmp;

	value = *pile_b;
	pile_tmp = *pile_b;
	while (pile_tmp)
	{
		if (pile_tmp->cnt > value->cnt)
			value = pile_tmp;
		pile_tmp = pile_tmp->next;
	}
	count_file(value, pile_b);
}

void	put_in_a(t_list **pile_a, t_list **pile_b)
{
	put_order(pile_b);
	while (*pile_b)
	{
		pa(pile_a, pile_b);
		ft_printf("pa\n");
	}
}
