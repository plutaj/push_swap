/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jozefpluta <jozefpluta@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:45:03 by jozefpluta        #+#    #+#             */
/*   Updated: 2024/12/02 19:04:03 by jozefpluta       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// check no argument situation!!! before finishing priject
// vagrind checks, maybe after error, print previous allocated nodes
// split frees

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	if (argc == 1)
		print_error();
	else if (argc == 2)
		stack_from_string(argv, &stack_a);
	else
	{
		while (i < argc)
		{
			is_arg_valid(argv[i]);
			stack_from_args(ft_atoi(argv[i]), &stack_a);
			i++;
		}
	}
	add_indexes(&stack_a);
	sort(&stack_a, &stack_b);
	free_list(stack_a);
	return (0);
}

// Print error
void	print_error(void)
{
	write(1, "Error", 5);
	exit(1);
}

// Free stack
void	free_list(t_node *stack_a)
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
