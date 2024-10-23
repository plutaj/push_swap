/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_indexes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:17:14 by jpluta            #+#    #+#             */
/*   Updated: 2024/10/23 19:01:28 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void add_indexes(t_node **stack_a) {
	int num_of_nodes = 0;
	int index;
	t_node *temp;
	t_node *temp2;

	temp = *stack_a;
	while (temp)
	{
		num_of_nodes++;
		temp = temp->next;
	}
	temp = *stack_a;
	while (temp)
	{
		index = 1;
		temp2 = *stack_a;
		while (temp2)
		{
			if (temp2->data < temp->data)
				index++;
			temp2 = temp2->next;
		}
		temp->index = index;
		temp = temp->next;
	}
}

