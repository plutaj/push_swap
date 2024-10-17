/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:45:03 by jozefpluta        #+#    #+#             */
/*   Updated: 2024/10/17 19:16:50 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_node	*stack_a = NULL;

t_node	*add_node(int data)
{
	t_node	*new;

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
		new->i = 0;
		new->data = data;
		stack_a->i++;
		new->next = stack_a;
		stack_a = new;
	}
	return (new);
}

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

int	main(int argc, char **argv)
{
	int i = 1;
	if (argc == 1)
		print_error();
	else
		while (i < argc)
		{
			add_node(ft_atoi(argv[i]));
		}
	t_node *current = stack_a;
	while (current != NULL)
	{
		printf("%d, ", current->data);
		current = current->next;
	}
	free_list(stack_a);
	return (0);
}

void print_error()
{
	write(1, "Error", 5);
	exit(1);
}