/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:34:02 by jpluta            #+#    #+#             */
/*   Updated: 2024/10/20 15:54:30 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_node *stack_a) // Free stack after program ends
{
	t_node	*current;
	t_node	*next_node;

	current = stack_a;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
}
