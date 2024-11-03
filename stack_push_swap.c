/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:44:47 by jpluta            #+#    #+#             */
/*   Updated: 2024/11/03 16:30:15 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// SWAP A - swap first two elems. of A
void	sa(t_node **stack_a)
{
	if (!stack_a || !(*stack_a)->next)
		return ;
	t_node	*temp;

	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = (*stack_a)->next;
	(*stack_a)->next = temp;

	write(1, "sa\n", 3);
}

// SWAP B - swap first two elems. of B
void	sb(t_node **stack_b)
{
	if (!stack_b || !(*stack_b)->next)
		return ;
	t_node	*temp;

	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = (*stack_b)->next;
	(*stack_b)->next = temp;

	write(1, "sb\n", 3);
}

// SWAP A && SWAP B at the same time
void	ss(t_node **stack_a, t_node **stack_b)
{
	if (!stack_a || !(*stack_a)->next)
		return ;
	else if (!stack_b || !(*stack_b)->next)
		return ;
	t_node	*temp;

	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = (*stack_a)->next;
	(*stack_a)->next = temp;
	temp = NULL;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = (*stack_b)->next;
	(*stack_b)->next = temp;
	write(1, "ss\n", 3);
}

// Take the first element of A and push it to B
void	pa(t_node **stack_b, t_node **stack_a)
{
	if (!stack_b)
		return ;
	t_node	*temp;

	temp = (*stack_b);
	*stack_b = (*stack_b)->next;
	temp->next = (*stack_a);
	*stack_a = temp;
	write(1, "pa\n", 3);
}

// Take the first element of A and push it to B
void	pb(t_node **stack_a, t_node **stack_b)
{
	if (!stack_a)
		return ;
	t_node	*temp;

	temp = (*stack_a);
	*stack_a = (*stack_a)->next;
	temp->next = (*stack_b);
	*stack_b = temp;
	write(1, "pb\n", 3);
}