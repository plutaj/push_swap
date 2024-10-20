/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:47:12 by jpluta            #+#    #+#             */
/*   Updated: 2024/10/20 18:56:22 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **stack_a)
{
	if (check_if_sorted(stack_a) == 1)
	{
		ra(&(*stack_a));
	}
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