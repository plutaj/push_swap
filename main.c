/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:45:03 by jozefpluta        #+#    #+#             */
/*   Updated: 2024/11/01 17:21:54 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" // UPRAVIT WILDCARD Z MAKEFILU !!!

void	print_stack_a(t_node *stack_a);

int	main(int argc, char **argv) // .. Main function >P
{
	t_node	*stack_a;
	int		i;

	stack_a = NULL;
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
	print_stack_a(stack_a);

	edge_cases(&stack_a);
	// sort(stack_a);
	// rra(&stack_a); // Priame volanie v pripade inputu 2 3 1 funguje ale cez edge_cases nefunguje
	// sort_three(&stack_a);

	print_stack_a(stack_a);
	if (check_if_sorted(&stack_a) == 0)
		printf("\nsorted");
	else
		printf("\nNOT sorted");
	free_list(stack_a);
	return (0);
}

void	print_error(void) // Print error
{
	write(1, "Error", 5);
	exit(1);
}

void	print_stack_a(t_node *stack_a)
{
	t_node	*temp;

	temp = stack_a;
	while (temp)
	{
		printf("\n%d (index %d), ", temp->data, temp->index);
		temp = temp->next;
	}
	printf("\n+++++++++++++++++++++++++++++++++++++++++++++");
}
