/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jozefpluta <jozefpluta@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:09:52 by jpluta            #+#    #+#             */
/*   Updated: 2024/11/23 20:50:36 by jozefpluta       ###   ########.fr       */
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
	t_node	*temp;
	if (check_if_sorted(stack_a) == 0)
		return ;
	edge_cases(stack_a);
	while (count_nodes(*stack_a) > 3 && count_nodes(*stack_b) < 2)
		pb(stack_a, stack_b);

	// test purposes
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	// test purposes
	

	// test purposes
	find_couple_byrr(stack_a, stack_b); // This function add costs to each node
	temp = find_cheapest(stack_a); // This function find the cheapest move
	printf("\ncheapest is %d, cuz cost is %d", temp->index, temp->cost);
	// test purposes

	//orig code below
	// while (count_nodes(*stack_a) > 3)
	// {
	// 	temp = NULL;
	// 	find_couple_byrr(stack_a, stack_b); // This function add costs to each node
	// 	temp = find_cheapest(stack_a); // This function find the cheapest move
	// }
	// sort_three(stack_a);
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
	int		highest_lower_i;

	temp_a = *stack_a;
	index_of_b = 0;
	index_of_a = 0;
	while (temp_a)
	{
		temp_b = *stack_b;
		index_of_b = -1;
		highest_lower_i = -1;
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
		if (!temp_b && index_of_b == -1) // If there is none finding biggest
			index_of_b = find_biggest(stack_b);
		make_cost(&temp_a, index_of_a, index_of_b); // At this point all nodes in stack A have rr costs
		calculate_cost_byrrr(&temp_a, stack_b, index_of_b); // At this point we compare rr cost against rrr costs and which is lower that is saved
		temp_a = temp_a->next;
		index_of_a++;
	}
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
	while (temp_stack && temp_elem->data != temp_stack->data)
	{
		if (temp_elem->index == temp_stack->index)  // Compare indexes, not data
			return index;
		temp_stack = temp_stack->next;
		index++;
	}
	return (index);
}
