/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmassavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 08:12:01 by jmassavi          #+#    #+#             */
/*   Updated: 2024/12/19 08:12:03 by jmassavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	printfile(t_list **head)
{
	t_list	*current;

	current = *head;
	while (current)
	{
		ft_printf("value -> %d\n", current->cnt);
		current = current->next;
	}
}

void	initialization(t_list **pile_a, t_list **pile_b)
{
	pb(pile_a, pile_b);
	ft_printf("pb\n");
	pb(pile_a, pile_b);
	ft_printf("pb\n");
}

int	main(int argc, char **argv)

{
	int	arg;
	t_list	*pile_a;
	t_list	*pile_b;

	(void)argc;
	pile_a = NULL;
	pile_b = NULL;
	arg = parsing(&pile_a, argv);
	if (arg > 2)
		sort(pile_a, pile_b);
	else if (arg == 2)
	{
		ft_printf("ra\n");
		pop_all(&pile_a);
	}
	else
		pop_all(&pile_a);
}
