/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmassavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 21:50:13 by jmassavi          #+#    #+#             */
/*   Updated: 2024/12/26 21:50:14 by jmassavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	make_rotation(t_list **pile_a, t_list **pile_b, t_svars *stuct)
{
	while (stuct->rr > 0)
	{
		rr(pile_a, pile_b);
		ft_printf("rr\n");
		stuct->rr = stuct->rr - 1;
	}
	while (stuct->ra > 0)
	{
		ra(pile_a);
		ft_printf("ra\n");
		stuct->ra = stuct->ra - 1;
	}
	while (stuct->rb > 0)
	{
		rb(pile_b);
		ft_printf("rb\n");
		stuct->rb = stuct->rb - 1;
	}
}

void	make_reverse_rotation(t_list **pile_a, t_list **pile_b, t_svars *stuct)
{
	while (stuct->rrr > 0)
	{
		rrr(pile_a, pile_b);
		ft_printf("rrr\n");
		stuct->rrr = stuct->rrr - 1;
	}
	while (stuct->rra > 0)
	{
		rra(pile_a);
		ft_printf("rra\n");
		stuct->rra = stuct->rra - 1;
	}
	while (stuct->rrb > 0)
	{
		rrb(pile_b);
		ft_printf("rrb\n");
		stuct->rrb = stuct->rrb - 1;
	}
}

void	make_instruction(t_list **pile_a, t_list **pile_b, t_svars *stuct)
{
	make_rotation(pile_a, pile_b, stuct);
	make_reverse_rotation(pile_a, pile_b, stuct);
	pb(pile_a, pile_b);
	ft_printf("pb\n");
}
