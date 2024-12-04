/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:58:02 by jpluta            #+#    #+#             */
/*   Updated: 2024/12/04 15:21:12 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_cheapest(t_node **stack_a)
{
	t_node	*temp;
	t_node	*cheapest;

	temp = *stack_a;
	cheapest = temp;
	while (temp)
	{
		if (temp->cost < cheapest->cost)
			cheapest = temp;
		temp = temp->next;
	}
	return (cheapest);
}

int	count_nodes(t_node *stack)
{
	t_node	*temp;
	int		i;

	temp = stack;
	i = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
