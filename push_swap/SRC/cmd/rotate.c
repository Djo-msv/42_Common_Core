/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmassavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:50:23 by jmassavi          #+#    #+#             */
/*   Updated: 2024/12/19 11:50:24 by jmassavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	ra(t_list **head_a)
{
	t_list	*content;

	content = *head_a;
	if (!content)
		return ;
	push_back(head_a, content->cnt);
	pop_front(head_a);
}

void	rb(t_list **head_b)
{
	t_list	*content;

	content = *head_b;
	if (!content)
		return ;
	push_back(head_b, content->cnt);
	pop_front(head_b);
}

void	rr(t_list **head_a, t_list **head_b)
{
	ra(head_a);
	rb(head_b);
}
