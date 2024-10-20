#ifndef UTILS_H
# define UTILS_H

#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_node
{
	int				data;
	int				i;
	struct s_node	*next;
}					t_node;

t_node			*stack_from_args(int data, t_node **stack_a);
void			free_list(t_node *head);
void			print_error();
t_node			*find_last(t_node ***stack_a);
void			stack_from_string(char **argv, t_node **stack_a);
void			is_arg_valid(char *argv);
void			is_num_double(t_node **stack_a);

#endif
