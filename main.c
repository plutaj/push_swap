/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:45:03 by jozefpluta        #+#    #+#             */
/*   Updated: 2024/10/20 18:56:59 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv) // .. Main function >P
{
	t_node	*stack_a;
	int		i;
	t_node	*current;

	stack_a = NULL;
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
	is_num_double(&stack_a);
	if (single_arg_case(&stack_a) == 1) // If only one INT (already sorted)
		return (0);

	// PRINT
	current = stack_a;
	while (current != NULL)
	{
		printf("%d, ", current->data);
		current = current->next;
	}
	// PRINT

	// PRINT
	printf("\n");
	current = stack_a;
	while (current != NULL)
	{
		printf("%d, ", current->data);
		current = current->next;
	}
	// PRINT

	free_list(stack_a);
	return (0);
}

void	print_error(void) // Print error
{
	write(1, "Error", 5);
	exit(1);
}
