/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jozefpluta <jozefpluta@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:09:52 by jpluta            #+#    #+#             */
/*   Updated: 2024/12/03 19:29:09 by jozefpluta       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_node **stack_a, t_node **stack_b)
{
	t_node	*node_to_push;
	int		i_of_final_dest_b;

	i_of_final_dest_b = 0;
	if (check_if_sorted(stack_a) == 0)
		return ;
	edge_cases(stack_a);
	while (count_nodes(*stack_a) > 3 && count_nodes(*stack_b) < 2)
		pb(stack_a, stack_b);
	while (count_nodes(*stack_a) > 3)
	{
		find_couple_byrr(stack_a, stack_b);
		node_to_push = find_cheapest(stack_a);
		i_of_final_dest_b = find_pair_stack_b(node_to_push, stack_b);
		rotate_and_push(stack_a, stack_b, node_to_push, i_of_final_dest_b);
	}
	sort_three(stack_a);
	sort_stack_b(stack_a, stack_b);
}

void	rotate_and_push(t_node **stack_a, t_node **stack_b,
			t_node *node_to_push, int i_of_final_dest_b)
{
	int	index_a;
	int	index_b;

	index_a = get_position_index(&node_to_push, stack_a);
	index_b = i_of_final_dest_b;
	if (((count_nodes(*stack_a) + count_nodes(*stack_b)) / 2) < (index_a + index_b)) // vymazal som (index_a + index_b) / 2)
		reverse_rotate_and_push(stack_a, stack_b, node_to_push, i_of_final_dest_b);
	else
		simultan_rr(stack_a, stack_b, node_to_push, i_of_final_dest_b);
	pb(stack_a, stack_b);
}

void	reverse_rotate_and_push(t_node **stack_a, t_node **stack_b,
			t_node *node_to_push, int i_of_final_dest_b)
{
	int	index_a;
	int	index_b;

	index_a = get_position_index(&node_to_push, stack_a);
	index_b = i_of_final_dest_b;
	while (index_a <= count_nodes(*stack_a) || index_b <= count_nodes(*stack_b))
	{
		if (index_a <= count_nodes(*stack_a) && index_b <= count_nodes(*stack_b))
		{
			index_a++;
			index_b++;
			rrr(stack_a, stack_b);
		}
		else if (index_a <= count_nodes(*stack_a))
		{
			index_a++;
			rra(stack_a);
		}
		else if (index_b <= count_nodes(*stack_b))
		{
			index_b++;
			rrb(stack_b);
		}
	}
}

void	simultan_rr(t_node **stack_a, t_node **stack_b,
			t_node *node_to_push, int i_of_final_dest_b)
{
	int	index_a;
	int	index_b;

	index_a = get_position_index(&node_to_push, stack_a);
	index_b = i_of_final_dest_b;
	while (index_a > 1 || index_b > 1)
	{
		if (index_a > 1 && index_b > 1)
		{
			index_a--;
			index_b--;
			rr(stack_a, stack_b);
		}
		else if (index_a > 1)
		{
			index_a--;
			ra(stack_a);
		}
		else if (index_b > 1)
		{
			index_b--;
			rb(stack_b);
		}
	}
}

void	sort_stack_b(t_node **stack_a, t_node **stack_b)
{
	int	biggest_index;
	int	count;

	biggest_index = find_biggest(stack_b);
	count = count_nodes(*stack_b);
	if (biggest_index >= (count / 2))
	{
		while (biggest_index != 1)
		{
			rrb(stack_b);
			biggest_index = find_biggest(stack_b);
		}
	}
	else
	{
		while (biggest_index != 1)
		{
			rb(stack_b);
			biggest_index = find_biggest(stack_b);
		}
	}
	push_back_to_a(stack_a, stack_b);
}