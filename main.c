/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:45:03 by jozefpluta        #+#    #+#             */
/*   Updated: 2024/12/04 18:04:18 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	if (argc == 1)
		return (0);
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
void	print_error(t_node **stack_a)
{
	if (stack_a)
		free_list(*stack_a);
	write(2, "Error\n", 6);
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
