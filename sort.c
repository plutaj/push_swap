/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:09:52 by jpluta            #+#    #+#             */
/*   Updated: 2024/11/28 17:24:10 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// If cost is negative means RRR is cheaper else RR is
// Handle edge cases - same value occurs twice, and 1-3 arg cases
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

void	sort(t_node **stack_a, t_node **stack_b)
{
	t_node	*node_to_push;
	int		i_of_final_dest_b;
	t_node	*temp_b;

	i_of_final_dest_b = 0;
	temp_b = *stack_b;
	if (check_if_sorted(stack_a) == 0)
		return ;
	edge_cases(stack_a);
	while (count_nodes(*stack_a) > 3 && count_nodes(*stack_b) < 2)
		pb(stack_a, stack_b);
	while (count_nodes(*stack_a) > 3)
	{
		find_couple_byrr(stack_a, stack_b); // This function add costs to each node
		node_to_push = find_cheapest(stack_a); // This function find the cheapest move
		i_of_final_dest_b = find_pair_stack_b(node_to_push, temp_b, stack_b);
		rotate_and_push(stack_a, stack_b, node_to_push, i_of_final_dest_b);
		// printf("\nindex %d has final dest is %d", node_to_push->index, i_of_final_dest_b);
	}
	sort_three(stack_a);
	sort_stack_b(stack_a, stack_b);
}

// void	reverse_rotate_and_push(t_node **stack_a, t_node **stack_b,
// 			t_node *node_to_push, int i_of_final_dest_b)
// {
// 	int	index_a;
// 	int	index_b;

// 	index_a = get_position_index(&node_to_push, stack_a);
// 	index_b = i_of_final_dest_b;
// }

void	push_back_to_a(t_node **stack_a, t_node **stack_b)
{
	while (count_nodes(*stack_b) != 0)
	{
		if (!find_highest_index(stack_a, stack_b))
			push_on_lowest(stack_a, stack_b);
		else
			push_on_highest(stack_a, stack_b);
	}
}

t_node	*find_lowest_index(t_node **stack_a)
{
	t_node	*temp_a;
	t_node	*lowest_index;

	temp_a = *stack_a;
	lowest_index = *stack_a;
	while (temp_a)
	{
		if (temp_a->index < lowest_index->index)
			lowest_index = temp_a;
		temp_a = temp_a->next;
	}
	return (lowest_index);
}

// Calculate if its cheaper to ra or rra stack_a and push from B to A to its place
void	push_on_lowest(t_node **stack_a, t_node **stack_b)
{
	t_node	*lowest_index;
	int		count;

	lowest_index = find_lowest_index(stack_a);
	count = count_nodes(*stack_a);
	if (get_position_index(&lowest_index, stack_a) <= (count / 2))
	{
		while (*stack_a != lowest_index)
			ra(stack_a);
	}
	else
	{
		while (*stack_a != lowest_index)
			rra(stack_a);
	}
	pa(stack_b, stack_a);
}

t_node	*find_highest_index(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp_a;
	t_node	*highest_index;

	temp_a = *stack_a;
	highest_index = *stack_a;
	while (temp_a)
	{
		if (temp_a->index > (*stack_b)->index)
		{
			if (temp_a->index < highest_index->index)
				highest_index = temp_a;
		}
		temp_a = temp_a->next;
	}
	if (!temp_a && (highest_index->index < (*stack_b)->index))
		highest_index = NULL;
	return (highest_index);
}

void	push_on_highest(t_node **stack_a, t_node **stack_b)
{
	t_node	*highest_index;
	int		count;

	highest_index = find_highest_index(stack_a, stack_b);
	count = count_nodes(*stack_a);
	if (get_position_index(&highest_index, stack_a) <= (count / 2))
	{
		while ((*stack_a) != highest_index)
			ra(stack_a);
	}
	else
	{
		while ((*stack_a) != highest_index)
			rra(stack_a);
	}
	pa(stack_b, stack_a);
}

// void	find_closest_higher(t_node **stack_a, t_node **stack_b)
// {
// 	t_node	*temp_a;
// 	t_node	*closest_higher;

// 	temp_a = *stack_a;
// 	while (temp_a && (temp_a->index != ((*stack_b)->index - 1)))
// 		temp_a = temp_a->next;
// 	if (!temp_a)
// 		push_on_lowest(stack_a, stack_b);
// 	else
// 		push_on_highest(stack_a, stack_b);
// }

void	rotate_and_push(t_node **stack_a, t_node **stack_b,
			t_node *node_to_push, int i_of_final_dest_b)
{
	int	index_a;
	int	index_b;

	index_a = get_position_index(&node_to_push, stack_a);
	index_b = i_of_final_dest_b;
	// if (node_to_push->cost < 0)
	// 	reverse_rotate_and_push(); // vytvorit funkciu
	printf("\ncheapes node to push %d, A position %d, B final dest posit. %d, cost %d", node_to_push->index, index_a, index_b, node_to_push->cost);
	while (index_a > 0 || index_b > 0)
	{
		if (index_a == 0 && index_b > 0)
		{
			rb(stack_b);
			index_b--;
		}
		else if (index_b == 0 && index_a > 0)
		{
			ra(stack_a);
			index_a--;
		}
		else if (index_a > 0 && index_b > 0)
		{
			rr(stack_a, stack_b);
			index_a--;
			index_b--;
		}
	}
	printf("\ncheapes node to push %d, A position %d, B final dest posit. %d", node_to_push->index, index_a, index_b);
	printf("\n____________________________________________________");
	pb(stack_a, stack_b);
}

// t_node	*find_lowest_index(t_node **stack_b)
// {
// 	t_node	*temp_b;
// 	t_node	*temp;

// 	temp_b = *stack_b;
// 	temp = *stack_b;
// 	while (temp_b)
// 	{
// 		if (temp_b->index < temp->index)
// 			temp = temp_b;
// 		temp_b = temp_b->next;
// 	}
// 	return (temp);
// }

void	sort_stack_b(t_node **stack_a, t_node **stack_b)
{
	int	biggest_index;
	int	count;

	biggest_index = find_biggest(stack_b);
	count = count_nodes(*stack_b);
	if (biggest_index >= (count / 2))
	{
		while (biggest_index != 0)
		{
			rrb(stack_b);
			biggest_index--;
		}
	}
	else
	{
		while (biggest_index != 0)
		{
			rb(stack_b);
			biggest_index--;
		}
	}
	push_back_to_a(stack_a, stack_b);
}

// Bool shows it actuall cheapest is pozit or negat num
t_node	*find_cheapest(t_node **stack_a)
{
	t_node	*temp;
	t_node	*cheapest;
	bool	pozit_cheap_num;

	temp = *stack_a;
	cheapest = temp;
	pozit_cheap_num = true; // Shows it actuall cheapest is pozit or negat num
	while (temp)
	{
		if (temp->cost == 0)
			return (temp);
		else if (temp->cost < 0)
		{
			if (((temp->cost * (-1)) < cheapest->cost) && pozit_cheap_num)
			{
				pozit_cheap_num = false;
				cheapest = temp;
			}
			else if (((temp->cost * (-1)) < (cheapest->cost * (-1))) && !pozit_cheap_num)
			{
				pozit_cheap_num = true;
				cheapest = temp;
			}
		}
		else if (temp->cost < cheapest->cost)
			cheapest = temp;
		temp = temp->next;
	}
	return (cheapest);
}

// Add costs to every element in a stack
void	find_couple_byrr(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp_a;
	t_node	*temp_b;
	int		index_of_b;
	int		index_of_a;

	temp_a = *stack_a;
	index_of_b = 0;
	index_of_a = 0;
	while (temp_a)
	{
		temp_b = *stack_b;
		index_of_b = -1;
		index_of_b = find_pair_stack_b(temp_a, temp_b, stack_b);
		make_cost(&temp_a, index_of_a, index_of_b); // At this point all nodes in stack A have rr costs
		calculate_cost_byrrr(&temp_a, stack_b, index_of_b); // At this point we compare rr cost against rrr costs and which is lower that is saved
		temp_a = temp_a->next;
		index_of_a++;
	}
}
int	find_pair_stack_b(t_node *temp_a, t_node *temp_b, t_node **stack_b)
{
	int		highest_lower_i;
	int		index_of_b;

	highest_lower_i = -1;
	index_of_b = -1;
	temp_b = *stack_b;
	while (temp_b) // Looking for smallest closest number in stack_b
	{
		if (temp_a->index > temp_b->index)
		{
			if (temp_b->index > highest_lower_i)
			{
				highest_lower_i = temp_b->index;
				index_of_b = get_position_index(&temp_b, stack_b);
			}
		}
		temp_b = temp_b->next;
	}
	if (highest_lower_i == -1 && index_of_b == -1) // If there is none finding biggest
		index_of_b = find_biggest(stack_b);
	return (index_of_b);
}

// rrr COST calculation
void	calculate_cost_byrrr(t_node **stack_a, t_node **stack_b, int index_b)
{
	int	cost;
	int	index;
	t_node	*temp_a;
	t_node	*temp_b;

	cost = 0;
	index = 0;
	temp_a = *stack_a;
	temp_b = *stack_b;
	while (index != index_b && temp_b)
	{
		index++;
		temp_b = temp_b->next;
	}
	while (temp_a || temp_b)
	{
		if (temp_a)
			temp_a = temp_a->next;
		if (temp_b)
			temp_b = temp_b->next;
		cost++;
	}
	if ((*stack_a)->cost > cost)
		(*stack_a)->cost = (cost * (-1));
}

// rr COST calculation
void	make_cost(t_node **temp_a, int index_of_a, int index_of_b)
{
	int	cost;

	cost = 0;
	if (index_of_a > index_of_b)
		cost = index_of_a;
	else if (index_of_a <= index_of_b)
		cost = index_of_b;
	(*temp_a)->cost = cost;
}

int	find_biggest(t_node **stack_b)
{
	t_node	*temp_b;
	int		i;
	int		position_i;

	temp_b = *stack_b;
	i = temp_b->index;
	position_i = 0;
	while (temp_b)
	{
		if (temp_b->index > i)
			i = temp_b->index;
		temp_b = temp_b->next;
	}
	temp_b = *stack_b;
	while (temp_b->index != i)
	{
		temp_b = temp_b->next;
		position_i++;
	}
	return (position_i);
}

// Return index of actuall position in stack
int	get_position_index(t_node **elem, t_node **stack)
{
	int		index;
	t_node	*temp_elem;
	t_node	*temp_stack;

	index = 0;
	temp_stack = *stack;
	temp_elem = *elem;
	while (temp_stack && (temp_elem->data != temp_stack->data))
	{
		if (temp_elem->index == temp_stack->index)  // Compare indexes, not data
			return index;
		temp_stack = temp_stack->next;
		index++;
	}
	return (index);
}
