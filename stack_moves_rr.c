/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_mutual_rotates.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 16:14:41 by jpluta            #+#    #+#             */
/*   Updated: 2024/11/03 16:35:40 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Rotate stack_a and stack_b at the same time
void	rr(t_node **stack_a, t_node **stack_b)
{
	if (!stack_a || !(*stack_a)->next)
		return ;
	else if (!stack_b || !(*stack_b)->next)
		return ;
	t_node	*temp;
	t_node	*last;

	last = find_last(stack_a);
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = NULL;
	last->next = temp;
	temp = NULL;
	last = NULL;
	last = find_last(stack_b);
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = NULL;
	last->next = temp;
	write(1, "rr\n", 3);

}

// REVERSE rotate stack_a and stack_b at the same time
void	rrr(t_node **stack_a, t_node **stack_b)
{
	if (!stack_a || !(*stack_a)->next)
		return ;
	else if (!stack_b || !(*stack_b)->next)
		return ;
	t_node	*last;
	t_node	*before_last;

	before_last = find_before_last(stack_a);
	last = find_last(stack_a);
	last->next = (*stack_a);
	before_last->next = NULL;
	*stack_a = last;
	last = NULL;
	before_last = NULL;
	before_last = find_before_last(stack_b);
	last = find_last(stack_b);
	last->next = (*stack_b);
	before_last->next = NULL;
	*stack_b = last;
	write(1, "rrr\n", 4);
}