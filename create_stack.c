/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:42:15 by jpluta            #+#    #+#             */
/*   Updated: 2024/12/04 17:47:03 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Create stack from multiple arguments
t_node	*stack_from_args(int data, t_node **stack_a)
{
	t_node	*new;
	t_node	*temp;

	if (*stack_a == NULL)
	{
		new = malloc(sizeof(t_node));
		if (new == NULL)
			return (NULL);
		new->data = data;
		new->cost = 0;
		*stack_a = new;
		new->next = NULL;
	}
	else
	{
		new = malloc(sizeof(t_node));
		if (new == NULL)
			return (NULL);
		temp = find_last(stack_a);
		temp->next = new;
		new->data = data;
		new->cost = 0;
		new->next = NULL;
	}
	return (new);
}

// Create stack from one string argument
void	stack_from_string(char **argv, t_node **stack_a)
{
	char	**numbers;
	int		i;

	i = 0;
	numbers = ft_split(argv[1], ' ');
	if (!numbers)
		print_error(stack_a);
	while (numbers[i] != NULL)
	{
		if (is_arg_valid(numbers[i]) == -1)
		{
			free(numbers[i]);
			free(numbers);
			print_error(stack_a);
		}
		stack_from_args(ft_atoi(numbers[i]), &(*stack_a));
		free(numbers[i]);
		i++;
	}
	free(numbers);
}
