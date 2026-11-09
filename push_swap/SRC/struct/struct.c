/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmassavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 03:48:12 by jmassavi          #+#    #+#             */
/*   Updated: 2024/12/27 03:48:18 by jmassavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

t_list	*create_node(long value)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->cnt = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_svars	*create_struct(void)
{
	t_svars	*new_struct;

	new_struct = malloc(sizeof(t_svars));
	if (!new_struct)
		return (NULL);
	new_struct->ra = 0;
	new_struct->rb = 0;
	new_struct->rr = 0;
	new_struct->rra = 0;
	new_struct->rrb = 0;
	new_struct->rrr = 0;
	new_struct->cost = 2147483647;
	return (new_struct);
}
