/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:47:12 by jpluta            #+#    #+#             */
/*   Updated: 2024/10/27 16:48:50 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **stack_a)
{
	t_node	*temp;

	temp = (*stack_a)->next;
	if (check_if_sorted(stack_a) == 1)
	{
		if (((*stack_a)->data > temp->data)				// 3 x x
			&& ((*stack_a)->data > temp->next->data))
		{
			if (temp->data > temp->next->data)			// 3 2 1
			{
				ra(&(*stack_a));
				sa(&(*stack_a));
			}
			else										// 3 1 2
				ra(&(*stack_a));
		}
		else if (((*stack_a)->data < temp->data)
			&& ((*stack_a)->data < temp->next->data))	// 1 3 2
		{
			sa(&(*stack_a));
			ra(&(*stack_a));
		}
		else											// 2 x x
		{
			if (((*stack_a)->data > temp->data)			// 2 1 3
				&& ((*stack_a)->data < temp->next->data))
				sa(&(*stack_a));
			else
				rra(&(*stack_a));
		}
	}
}

void	sort_two(t_node **stack_a)
{
	if ((*stack_a)->next < (*stack_a))
		sa(&(*stack_a));
}

int	check_if_sorted(t_node **stack_a) // Returns 1 if NOT sorted, else returns 0
{
	t_node	*temp;
	t_node	*temp2;

	temp = *stack_a;
	temp2 = temp->next;
	while (temp && temp2)
	{
		if (temp->data > temp2->data)
			return (1);
		temp = temp->next;
		temp2 = temp2->next;
	}
	return (0);
}

int	count_nodes(t_node *stack_a)
{
	t_node	*temp;
	int		i;

	temp = stack_a;
	i = 1;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}