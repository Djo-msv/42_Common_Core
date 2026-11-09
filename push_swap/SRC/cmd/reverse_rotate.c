/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmassavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:02:03 by jmassavi          #+#    #+#             */
/*   Updated: 2024/12/19 12:02:04 by jmassavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	rra(t_list **head_a)
{
	t_list	*content;

	content = *head_a;
	if (!content)
		return ;
	while (content->next)
		content = content->next;
	push_front(head_a, content->cnt);
	pop_back(head_a);
}

void	rrb(t_list **head_b)
{
	t_list	*content;

	content = *head_b;
	if (!content)
		return ;
	while (content->next)
		content = content->next;
	push_front(head_b, content->cnt);
	pop_back(head_b);
}

void	rrr(t_list **head_a, t_list **head_b)
{
	rra(head_a);
	rrb(head_b);
}
