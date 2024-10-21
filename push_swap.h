/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:54:57 by jpluta            #+#    #+#             */
/*   Updated: 2024/10/21 17:20:20 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				data;
	int				i;
	struct s_node	*next;
}					t_node;

t_node		*stack_from_args(int data, t_node **stack_a);
void		free_list(t_node *stack_a);
void		print_error(void);
t_node		*find_last(t_node ***stack_a);
void		stack_from_string(char **argv, t_node **stack_a);
void		is_arg_valid(char *argv);
void		is_num_double(t_node **stack_a);
void		sa(t_node **stack_a);
int			single_arg_case(t_node **stack_a);
int			check_if_sorted(t_node **stack_a);
void		sort_three(t_node **stack_a);
void		ra(t_node **stack_a);
void		rra(t_node **stack_a);
t_node		*find_before_last(t_node ***stack_a);
void		sort_two(t_node **stack_a);

#endif
