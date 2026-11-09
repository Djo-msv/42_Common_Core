/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmassavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:53:29 by jmassavi          #+#    #+#             */
/*   Updated: 2024/12/19 10:53:30 by jmassavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	sa(t_list **head_a)
{
	t_list	*first;
	t_list	*second;

	first = *head_a;
	second = first->next;
	if (!first || !second)
		return ;
	first->next = second->next;
	first->prev = second->prev;
	second->next = first;
	second->prev = NULL;
	*head_a = second;
}

void	sb(t_list **head_b)
{
	t_list	*first;
	t_list	*second;

	first = *head_b;
	second = first->next;
	if (!first || !second)
		return ;
	first->next = second->next;
	first->prev = second->prev;
	second->next = first;
	second->prev = NULL;
	*head_b = second;
}

void	ss(t_list **head_a, t_list **head_b)
{
	sa(head_a);
	sb(head_b);
}
