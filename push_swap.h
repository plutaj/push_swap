/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:54:57 by jpluta            #+#    #+#             */
/*   Updated: 2024/12/04 17:46:41 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_node
{
	int				data;
	int				index;
	int				cost;
	struct s_node	*next;
}					t_node;

t_node	*stack_from_args(int data, t_node **stack_a);
void	free_list(t_node *stack_a);
void	print_error(t_node **stack_a);
t_node	*find_last(t_node **stack_a);
void	stack_from_string(char **argv, t_node **stack_a);
int		is_arg_valid(char *argv);
void	is_num_double(t_node **stack_a);
int		single_arg_case(t_node **stack_a);
int		check_if_sorted(t_node **stack_a);
void	sort_three(t_node **stack_a);
t_node	*find_before_last(t_node **stack_a);
void	sort_two(t_node **stack_a);
void	add_indexes(t_node **stack_a);
void	sort(t_node **stack_a, t_node **stack_b);
void	edge_cases(t_node **stack_a);
int		count_nodes(t_node *stack);
void	find_couple_byrr(t_node **stack_a, t_node **stack_b);
int		get_position_index(t_node **elem, t_node **stack);
int		find_biggest(t_node **stack_b);
void	make_cost(t_node **temp_a, int index_of_a,
			t_node **stack_a, t_node **stack_b);
t_node	*find_cheapest(t_node **stack_a);
int		find_pair_stack_b(t_node *temp_a, t_node **stack_b);
void	rotate_and_push(t_node **stack_a, t_node **stack_b,
			t_node *node_to_push, int i_of_final_dest_b);
void	sort_stack_b(t_node **stack_a, t_node **stack_b);
void	push_on_lowest(t_node **stack_a, t_node **stack_b);
void	push_back_to_a(t_node **stack_a, t_node **stack_b);
void	push_on_highest(t_node **stack_a, t_node **stack_b);
t_node	*find_highest_index(t_node **stack_a, t_node **stack_b);
void	push_on_lowest(t_node **stack_a, t_node **stack_b);
t_node	*find_lowest_index(t_node **stack_a);
void	reverse_rotate_and_push(t_node **stack_a, t_node **stack_b,
			t_node *node_to_push, int i_of_final_dest_b);
void	simultan_rr(t_node **stack_a, t_node **stack_b,
			t_node *node_to_push, int i_of_final_dest_b);
void	sort_three_2(t_node **stack_a, t_node *temp);

// Stack moves
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	pa(t_node **stack_b, t_node **stack_a);
void	pb(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);

#endif
