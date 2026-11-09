/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmassavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 03:48:23 by jmassavi          #+#    #+#             */
/*   Updated: 2024/12/27 03:48:30 by jmassavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	push_back(t_list **head, long value)
{
	t_list	*new_node;
	t_list	*current;

	new_node = create_node(value);
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	current = *head;
	while (current->next)
		current = current->next;
	current->next = new_node;
	new_node->prev = current;
}

void	push_front(t_list **head, long value)
{
	t_list	*new_node;
	t_list	*current;

	new_node = create_node(value);
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	current = *head;
	current->prev = new_node;
	new_node->next = current;
	*head = new_node;
}

void	pop_front(t_list **head)
{
	t_list	*tmp;

	if (!*head)
		return ;
	tmp = *head;
	if ((*head)->next == NULL)
	{
		free(tmp);
		(*head) = NULL;
		return ;
	}
	*head = (*head)->next;
	(*head)->prev = NULL;
	free(tmp);
}

void	pop_back(t_list **head)
{
	t_list	*tmp;

	if (!*head)
		return ;
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	(tmp->prev)->next = NULL;
	free(tmp);
}

void	pop_all(t_list **head)
{
	t_list	*tmp;

	if (!*head)
		return ;
	tmp = *head;
	while ((*head))
	{
		*head = (*head)->next;
		pop_front(&tmp);
	}
}
