/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves_rotations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:36:13 by jpluta            #+#    #+#             */
/*   Updated: 2024/11/03 14:58:18 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ROTATE A - the first elem. becomes last (shift UP all elems)
void	ra(t_node **stack_a)
{
	if (!stack_a || !(*stack_a)->next)
		return ;
	t_node	*temp;
	t_node	*last;

	last = find_last(stack_a);
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = NULL;
	last->next = temp;
	write(1, "ra\n", 3);
}

// ROTATE B - the first elem. becomes last (shift UP all elems)
void	rb(t_node **stack_b)
{
	if (!stack_b || !(*stack_b)->next)
		return ;
	t_node	*temp;
	t_node	*last;

	last = find_last(stack_b);
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = NULL;
	last->next = temp;
	write(1, "rb\n", 3);
}

// Reverse rotate A - shift down all elem. of A (last element become first)
void	rra(t_node **stack_a)
{
	if (!stack_a || !(*stack_a)->next)
		return ;
	t_node	*last;
	t_node	*before_last;

	before_last = find_before_last(stack_a);
	last = find_last(stack_a);
	last->next = (*stack_a);
	before_last->next = NULL;
	*stack_a = last;
	write(1, "rra\n", 4);
}

// Reverse rotate B - shift down all elem. of B (last element become first)
void	rrb(t_node **stack_b)
{
	if (!stack_b || !(*stack_b)->next)
		return ;
	t_node	*last;
	t_node	*before_last;

	before_last = find_before_last(stack_b);
	last = find_last(stack_b);
	last->next = (*stack_b);
	before_last->next = NULL;
	*stack_b = last;
	write(1, "rrb\n", 4);
}