/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmassavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 03:40:11 by jmassavi          #+#    #+#             */
/*   Updated: 2024/12/27 03:40:13 by jmassavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

t_list	*search_value(t_list *pile_a, t_list *pile_b)
{
	int		value;
	t_list	*pile_b_tmp;
	t_list	*result;

	value = pile_a->cnt;
	pile_b_tmp = pile_b;
	result = NULL;
	if (!pile_b_tmp)
		return (NULL);
	while (pile_b_tmp->next)
	{
		if ((pile_b_tmp->next)->cnt > pile_b_tmp->cnt && \
			(value > (pile_b_tmp->next)->cnt || value < pile_b_tmp->cnt))
			result = pile_b_tmp->next;
		if ((pile_b_tmp->next)->cnt < value && value < pile_b_tmp->cnt)
			result = pile_b_tmp->next;
		pile_b_tmp = pile_b_tmp->next;
	}
	if (result == NULL)
		result = pile_b;
	return (result);
}

void	calculate_pile_a(t_svars *result, t_list *pile_a)
{
	int		up_result;
	int		down_result;
	t_list	*pile_a_tmp;

	up_result = 0;
	down_result = 1;
	pile_a_tmp = pile_a;
	while (pile_a_tmp->next)
	{
		down_result++;
		pile_a_tmp = pile_a_tmp->next;
	}
	while (pile_a->prev != NULL)
	{
		up_result++;
		pile_a = pile_a->prev;
	}
	result->ra = up_result;
	result->rra = down_result;
}

void	calculate_pile_b(t_svars *result, t_list *pile_a, t_list *pile_b)
{
	int		up_result;
	int		down_result;
	t_list	*pile_b_tmp;

	up_result = 0;
	down_result = 1;
	pile_b_tmp = search_value(pile_a, pile_b);
	pile_b = pile_b_tmp;
	if (!pile_b_tmp)
		return ;
	while (pile_b_tmp->next)
	{
		down_result++;
		pile_b_tmp = pile_b_tmp->next;
	}
	while (pile_b->prev != NULL)
	{
		up_result++;
		pile_b = pile_b->prev;
	}
	result->rb = up_result;
	result->rrb = down_result;
}

t_svars	*calculate_cost(t_list **pile_a, t_list **pile_b)
{
	t_list	*check_pile_a;
	t_list	*check_pile_b;
	t_svars	*result;

	check_pile_a = *pile_a;
	check_pile_b = *pile_b;
	result = create_struct();
	calculate_pile_a(result, check_pile_a);
	calculate_pile_b(result, check_pile_a, check_pile_b);
	return (result);
}
