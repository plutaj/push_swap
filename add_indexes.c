/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_indexes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jozefpluta <jozefpluta@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:17:14 by jpluta            #+#    #+#             */
/*   Updated: 2024/10/29 15:58:04 by jozefpluta       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_indexes(t_node **stack_a)
{
	int index;
	t_node *temp;
	t_node *temp2;

	temp = *stack_a;
	while (temp)
		temp = temp->next;
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

