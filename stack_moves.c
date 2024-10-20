/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:44:47 by jpluta            #+#    #+#             */
/*   Updated: 2024/10/20 18:50:02 by jpluta           ###   ########.fr       */
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
}

// // ROTATE A - the first elem. becomes last (shift UP all elems)
void	ra(t_node **stack_a)
{
	t_node	*temp;
	// t_node	*temp2;
	temp = (*stack_a)->next;
	temp = temp->next;
	temp->next = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	temp = temp->next;
	temp->next = NULL;
}