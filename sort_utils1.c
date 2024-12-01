/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:47:12 by jpluta            #+#    #+#             */
/*   Updated: 2024/12/01 14:12:39 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	edge_cases(t_node **stack_a)
{
	int	i;

	i = count_nodes(*stack_a);
	is_num_double(stack_a);
	if (i == 1)
		single_arg_case(stack_a);
	else if (i == 2)
	{
		if (check_if_sorted(stack_a) == 1)
			sort_two(stack_a);
	}
	else if (i == 3)
	{
		if (check_if_sorted(stack_a) == 1)
			sort_three(stack_a);
	}
}

void	sort_three(t_node **stack_a)
{
	t_node	*temp;

	temp = (*stack_a)->next;
	if (check_if_sorted(stack_a) == 1)
	{
		if (((*stack_a)->data > temp->data)
			&& ((*stack_a)->data > temp->next->data))
		{
			if (temp->data > temp->next->data)
			{
				ra(&(*stack_a));
				sa(&(*stack_a));
			}
			else
				ra(&(*stack_a));
		}
		else if (((*stack_a)->data < temp->data)
			&& ((*stack_a)->data < temp->next->data))
		{
			sa(stack_a);
			ra(&(*stack_a));
		}
		else
			sort_three_2(stack_a, temp);
	}
}

void	sort_three_2(t_node **stack_a, t_node *temp)
{
	if (((*stack_a)->data > temp->data)
		&& ((*stack_a)->data < temp->next->data))
		sa(&(*stack_a));
	else
		rra(&(*stack_a));
}

void	sort_two(t_node **stack_a)
{
	if ((*stack_a)->data > (*stack_a)->next->data)
		sa(&(*stack_a));
}

// Returns 1 if NOT sorted, else returns 0
int	check_if_sorted(t_node **stack_a)
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
