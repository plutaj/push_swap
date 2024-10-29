/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jozefpluta <jozefpluta@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:09:52 by jpluta            #+#    #+#             */
/*   Updated: 2024/10/29 20:19:11 by jozefpluta       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	edge_cases(t_node *stack_a)
{
	int	i;

	i = count_nodes(stack_a);
	is_num_double(&stack_a);
	if (i == 1)
		single_arg_case(&stack_a);
	else if (i == 2)
	{
		if (check_if_sorted(&stack_a) == 1)
			sort_two(&stack_a);
	}
	else if (i == 3)
	{
		if (check_if_sorted(&stack_a) == 1)
			sort_three(&stack_a);
	}
	// sort(&stack_a);
}

// void	sort(t_node *stack_a)
// {
// 	t_node	*stack_b;

// 	stack_b = NULL;

// 	// while (count_nodes(&stack_a) > 3)
// 	// {

// 	// }
// }
