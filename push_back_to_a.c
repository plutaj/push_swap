/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:49:15 by jpluta            #+#    #+#             */
/*   Updated: 2024/12/01 14:13:24 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back_to_a(t_node **stack_a, t_node **stack_b)
{
	while (count_nodes(*stack_b) != 0)
	{
		if (!find_highest_index(stack_a, stack_b))
			push_on_lowest(stack_a, stack_b);
		else
			push_on_highest(stack_a, stack_b);
	}
}

t_node	*find_lowest_index(t_node **stack_a)
{
	t_node	*temp_a;
	t_node	*lowest_index;

	temp_a = *stack_a;
	lowest_index = *stack_a;
	while (temp_a)
	{
		if (temp_a->index < lowest_index->index)
			lowest_index = temp_a;
		temp_a = temp_a->next;
	}
	return (lowest_index);
}

// Calculate cheaper to ra or rra stack_a and push from B to A to its place
void	push_on_lowest(t_node **stack_a, t_node **stack_b)
{
	t_node	*lowest_index;
	int		count;

	lowest_index = find_lowest_index(stack_a);
	count = count_nodes(*stack_a);
	if (get_position_index(&lowest_index, stack_a) <= (count / 2))
	{
		while (*stack_a != lowest_index)
			ra(stack_a);
	}
	else
	{
		while (*stack_a != lowest_index)
			rra(stack_a);
	}
	pa(stack_b, stack_a);
}

t_node	*find_highest_index(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp_a;
	t_node	*highest_index;

	temp_a = *stack_a;
	highest_index = *stack_a;
	while (temp_a)
	{
		if (temp_a->index > (*stack_b)->index)
		{
			if (temp_a->index < highest_index->index)
				highest_index = temp_a;
		}
		temp_a = temp_a->next;
	}
	if (!temp_a && (highest_index->index < (*stack_b)->index))
		highest_index = NULL;
	return (highest_index);
}

void	push_on_highest(t_node **stack_a, t_node **stack_b)
{
	t_node	*highest_index;
	int		count;

	highest_index = find_highest_index(stack_a, stack_b);
	count = count_nodes(*stack_a);
	if (get_position_index(&highest_index, stack_a) <= (count / 2))
	{
		while ((*stack_a) != highest_index)
			ra(stack_a);
	}
	else
	{
		while ((*stack_a) != highest_index)
			rra(stack_a);
	}
	pa(stack_b, stack_a);
}
