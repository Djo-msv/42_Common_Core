/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmassavi <jmassavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 08:06:44 by jmassavi          #+#    #+#             */
/*   Updated: 2024/12/23 17:53:25 by jmassavi         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	long		cnt;

	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef struct s_svars
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	cost;
}	t_svars;


void	push_back(t_list **head, long value);
void	push_front(t_list **head, long value);
void	pop_front(t_list **head);
void	pop_back(t_list **head);
void	pop_all(t_list **head);

t_list	*create_node(long value);
t_svars	*create_struct(void);

int		parsing(t_list **pile_a, char **argv);

void	sa(t_list **head_a);
void	sb(t_list **head_b);
void	ss(t_list **head_a, t_list **head_b);

void	pa(t_list **head_a, t_list **head_b);
void	pb(t_list **head_a, t_list **head_b);

void	ra(t_list **head_a);
void	rb(t_list **head_b);
void	rr(t_list **head_a, t_list **head_b);

void	rra(t_list **head_a);
void	rrb(t_list **head_b);
void	rrr(t_list **head_a, t_list **head_b);

int		checkargv(char **argv);

void	sort(t_list *pile_a, t_list *pile_b);

t_svars	*calculate_cost(t_list **pile_a, t_list **pile_b);

void	minimum_cost(t_svars *my_struct);

int		upup(t_svars *my_struct, int  status);
int		downdown(t_svars *my_struct, int  status);
int		updown(t_svars *my_struct, int  status);
int		downup(t_svars *my_struct, int  status);

void	initialization(t_list **pile_a, t_list **pile_b);
void	printfile(t_list **head);

void	make_instruction(t_list **pile_a, t_list **pile_b, t_svars *stuct);

void	put_in_a(t_list **pile_a, t_list **pile_b);

#endif
