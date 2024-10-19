/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:45:03 by jozefpluta        #+#    #+#             */
/*   Updated: 2024/10/19 17:45:35 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*stack_a = NULL; // CANNOT BE GLOBAL VARIABLE

t_node	*stack_from_args(int data) // Create stack from multiple arguments
{
	t_node	*new;
	t_node	*temp;

	if (stack_a == NULL)
	{
		new = malloc(sizeof(t_node));
		if (new == NULL)
			return (NULL);
		new->data = data;
		new->i = 0;
		stack_a = new;
		new->next = NULL;
	}
	else
	{
		new = malloc(sizeof(t_node));
		if (new == NULL)
			return (NULL);
		temp = find_last();
		temp->next = new;
		new->data = data;
		new->next = NULL;
	}
	return (new);
}

t_node	*find_last() // Search for last node and returns a pointer to it
{
	t_node	*temp;

	temp = stack_a;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	free_list(t_node *stack_a) // Free stack after program ends
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

void stack_from_string(char **argv) // Create stack from one string argument
{
	char	**numbers;
	int		i;

	i = 0;
	numbers = ft_split(argv[1], ' ');
	if (!numbers)
		print_error();
	while (numbers[i] != NULL)
	{
		is_arg_valid(numbers[i]);
		stack_from_args(ft_atoi(numbers[i]));
		i++;
	}
}

int	main(int argc, char **argv) // .. Main function >P
{
	int i = 1;
	if (argc == 1)
		print_error();
	else if (argc == 2)
		stack_from_string(argv);
	else
	{
		while (i < argc)
		{
			is_arg_valid(argv[i]);
			stack_from_args(ft_atoi(argv[i]));
			i++;
		}
	}
	is_num_double();
	t_node *current = stack_a;
	while (current != NULL)
	{
		printf("%d, ", current->data);
		current = current->next;
	}
	free_list(stack_a);
	return (0);
}

void	is_arg_valid(char *argv) // Check if argument is valid (not a char etc)
{
	int	i;
	long long a;

	i = 0;
	while (argv[i])
	{
		if ((argv[i] == '-' || argv[i] == '+') && (ft_isdigit(argv[i+1]) == 1)) // MAY CAUSE PROBLEMS
			i++;
		else if (ft_isdigit(argv[i]) == 0)
			print_error();
		i++;
	}
	a = ft_atol(argv);
	if (a > INT_MAX || a < INT_MIN)
		print_error();
}

void	is_num_double() // Check for number if its not more than 1x in stack
{
	t_node	*current;
	t_node	*temp;

	current = stack_a;
	temp = NULL;
	while (current != NULL)
	{
		temp = current->next;
		while (temp != NULL)
		{
			if (temp->data == current->data)
				print_error();
			temp = temp->next;
		}
		temp = NULL;
		current = current->next;
	}
}

void	print_error() // Print error
{
	write(1, "Error", 5);
	exit(1);
}