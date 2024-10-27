/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:44:47 by jpluta            #+#    #+#             */
/*   Updated: 2024/10/27 17:13:53 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// SWAP A - swap first two elems. of A
void	sa(t_node **stack_a)
{
	t_node	*temp;

	temp = *stack_a;
	if ((*stack_a)->next == NULL)
		exit(1);
	*stack_a = (*stack_a)->next;
	temp->next = (*stack_a)->next;
	(*stack_a)->next = temp;
	write(1, "sa\n", 3);
}

// ROTATE A - the first elem. becomes last (shift UP all elems)
void	ra(t_node **stack_a)
{
	t_node	*temp;
	t_node	*last;

	last = find_last(&stack_a);
	temp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	temp->next = NULL;
	last->next = temp;
	write(1, "ra\n", 3);
}

// Reverse rotate A - shift down all elem. of A (last element become first)
void	rra(t_node **stack_a)
{
	t_node	*temp;
	t_node	*last;

	last = find_before_last(&stack_a);
	temp = find_last(&stack_a);
	temp->next = (*stack_a);
	(*stack_a) = temp;
	last->next = NULL;
	write(1, "rra\n", 4);
}

// Take the first element of A and push it to B
void	pb(t_node **stack_a, t_node *stack_b)
{
	t_node	*temp;

	temp = (*stack_a)->next;
	if (*stack_a != NULL)
	{
		(*stack_a)->next = stack_b;
		stack_b = (*stack_a);
		(*stack_a) = temp;
	}
}