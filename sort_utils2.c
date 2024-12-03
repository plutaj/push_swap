/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jozefpluta <jozefpluta@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:52:26 by jpluta            #+#    #+#             */
/*   Updated: 2024/12/03 19:41:21 by jozefpluta       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Add costs to every element in a stack
void	find_couple_byrr(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp_a;
	int		index_of_a;

	temp_a = *stack_a;
	index_of_a = 1;
	while (temp_a)
	{
		make_cost(&temp_a, index_of_a, stack_a, stack_b);
		temp_a = temp_a->next;
		index_of_a++;
	}
}

int	find_pair_stack_b(t_node *temp_a, t_node **stack_b)
{
	int		highest_lower_i;
	int		index_of_b;
	t_node	*temp_b;

	highest_lower_i = -1;
	index_of_b = -1;
	temp_b = *stack_b;
	while (temp_b)
	{
		if (temp_a->index > temp_b->index)
		{
			if (temp_b->index > highest_lower_i)
			{
				highest_lower_i = temp_b->index;
				index_of_b = get_position_index(&temp_b, stack_b);
			}
		}
		temp_b = temp_b->next;
	}
	if (highest_lower_i == -1 && index_of_b == -1)
		index_of_b = find_biggest(stack_b);
	return (index_of_b);
}

void	make_cost(t_node **temp_a, int index_of_a,
			t_node **stack_a, t_node **stack_b)
{
	int	cost_a;
	int	cost_b;
	int	stack_a_count;
	int	stack_b_count;
	int	index_of_b;

	cost_a = 0;
	cost_b = 0;
	stack_a_count = count_nodes(*stack_a);
	stack_b_count = count_nodes(*stack_b);
	index_of_b = find_pair_stack_b(*temp_a, stack_b);
	if (((count_nodes(*stack_a) + count_nodes(*stack_b)) / 2) < (index_of_a + index_of_b))
	{
		cost_a = stack_a_count - index_of_a;
		cost_b = stack_b_count - index_of_b;
		(*temp_a)->cost = cost_a > cost_b ? cost_a : cost_b;
	}
	else
	{
		(*temp_a)->cost = index_of_a > index_of_b ? index_of_a : index_of_b;
	}
}

int	find_biggest(t_node **stack_b)
{
	t_node	*temp_b;
	int		i;

	temp_b = *stack_b;
	i = temp_b->index;
	if (*stack_b == NULL)
		return (-1);
	while (temp_b)
	{
		if (temp_b->index > i)
			i = temp_b->index;
		temp_b = temp_b->next;
	}
	temp_b = *stack_b;
	while (temp_b->index != i)
		temp_b = temp_b->next;
	return (get_position_index(&temp_b, stack_b));
}

// Return index of actuall position in stack
int	get_position_index(t_node **elem, t_node **stack)
{
	int		index;
	t_node	*temp_elem;
	t_node	*temp_stack;

	index = 1;
	temp_stack = *stack;
	temp_elem = *elem;
	while (temp_stack)
	{
		if (temp_elem->index == temp_stack->index)
			return index;
		temp_stack = temp_stack->next;
		index++;
	}
	return (index);
}