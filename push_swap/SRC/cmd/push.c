/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmassavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:17:46 by jmassavi          #+#    #+#             */
/*   Updated: 2024/12/19 11:17:48 by jmassavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	pa(t_list **head_a, t_list **head_b)
{
	t_list	*content_a;
	t_list	*content_b;

	content_a = *head_a;
	content_b = *head_b;
	if (!content_b)
		return ;
	push_front(head_a, content_b->cnt);
	pop_front(head_b);
}

void	pb(t_list **head_a, t_list **head_b)
{
	t_list	*content_a;
	t_list	*content_b;

	content_a = *head_a;
	content_b = *head_b;
	if (!content_a)
		return ;
	push_front(head_b, content_a->cnt);
	pop_front(head_a);
}
