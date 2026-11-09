/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djo <djo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:10:10 by jmassavi          #+#    #+#             */
/*   Updated: 2025/04/27 19:07:53 by djo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*create_node(t_data **data, int id)
{
	t_philo	*node;

	node = malloc(sizeof(t_philo));
	if (!node)
		return (NULL);
	node->data = (*data);
	node->id = id;
	node->fork = malloc(sizeof(pthread_mutex_t));
	if (node->fork)
		pthread_mutex_init(node->fork, NULL);
	node->die_mutex = malloc(sizeof(pthread_mutex_t));
	if (node->die_mutex)
		pthread_mutex_init(node->die_mutex, NULL);
	node->t_die_mutex = malloc(sizeof(pthread_mutex_t));
	if (node->t_die_mutex)
		pthread_mutex_init(node->t_die_mutex, NULL);
	node->print = malloc(sizeof(char) * 255);
	node->time_of_death = (*data)->t_die;
	node->next = NULL;
	node->die = false;
	node->time = 0;
	node->thread_t = 0;
	return (node);
}

int	protect_node(t_data **data, t_philo **head, t_philo **node, int id)
{
	(*node) = create_node(data, id);
	if (!(*node) || !(*node)->fork || !(*node)->die_mutex || \
		!(*node)->t_die_mutex || !(*node)->print)
	{
		free_philo(*head);
		ft_perror((*data), "allocation fail", P_RED);
		return (1);
	}
	return (0);
}

int	new_node(t_data **data, t_philo **head, int id)
{
	t_philo	*list;

	list = *head;
	if (!list)
		return (protect_node(data, head, &(*head), id));
	while (list->next)
		list = list->next;
	return (protect_node(data, head, &list->next, id));
}

void	loop_the_loop(t_philo *head)
{
	t_philo	*list;

	list = head;
	while (list->next)
		list = list->next;
	list->next = head;
}

int	create_philo(t_data **data)
{
	int		i;
	t_philo	*chained_list;

	i = 0;
	chained_list = NULL;
	while (i != (*data)->n_philo)
	{
		if (new_node(data, &chained_list, i++))
			return (1);
	}
	loop_the_loop(chained_list);
	(*data)->philo = chained_list;
	return (0);
}
