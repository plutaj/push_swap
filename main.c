/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:45:03 by jozefpluta        #+#    #+#             */
/*   Updated: 2024/10/27 17:46:39 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" // UPRAVIT WILDCARD Z MAKEFILU !!!

int	main(int argc, char **argv) // .. Main function >P
{
	t_node	*stack_a;
	int		i;
	t_node	*current;

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
	if (edge_cases(stack_a) == 1) // This function handles all edge cases
		return (0);
	// sort(stack_a);
	free_list(stack_a);
	return (0);
}

void	print_error(void) // Print error
{
	write(1, "Error", 5);
	exit(1);
}
