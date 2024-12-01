/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:45:03 by jozefpluta        #+#    #+#             */
/*   Updated: 2024/12/01 13:31:36 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" // UPRAVIT WILDCARD Z MAKEFILU !!!

int	main(int argc, char **argv) // .. Main function >P
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	if (argc == 1) // No argument case
		print_error();
	else if (argc == 2) // String argument or one argument case
		stack_from_string(argv, &stack_a);
	else
	{
		while (i < argc) // More arguments case
		{
			is_arg_valid(argv[i]);
			stack_from_args(ft_atoi(argv[i]), &stack_a);
			i++;
		}
	}

	add_indexes(&stack_a);

	// // TESTING
	// printf("\nBEFORE_______________________");
	// print_stack(stack_a);
	// print_stack(stack_b);
	// // TESTING

	sort(&stack_a, &stack_b);

	// // TESTING
	// printf("\nAFTER_________________________");
	// print_stack(stack_a);
	// print_stack(stack_b);
	// // TESTING

	free_list(stack_a);
	return (0);
}

void	print_error(void) // Print error
{
	write(1, "Error", 5);
	exit(1);
}

void	print_stack(t_node *stack)
{
	t_node	*temp;

	temp = stack;
	while (temp)
	{
		printf("\ndata:%d  index:%d  cost:%d", temp->data, temp->index, temp->cost);
		temp = temp->next;
	}
	printf("\n+++++++++++++++++++++++++++++++++++++++++++++");
}
