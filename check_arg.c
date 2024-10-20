/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:38:27 by jpluta            #+#    #+#             */
/*   Updated: 2024/10/20 15:52:57 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_arg_valid(char *argv) // Check if argument is valid (not a char etc)
{
	int			i;
	long long	a;

	i = 0;
	while (argv[i])
	{
		if ((argv[i] == '-' || argv[i] == '+')
			&& (ft_isdigit(argv[i + 1]) == 1))
			i++;
		else if (ft_isdigit(argv[i]) == 0)
			print_error();
		i++;
	}
	a = ft_atol(argv);
	if (a > INT_MAX || a < INT_MIN)
		print_error();
}

void	is_num_double(t_node **stack_a) // Check for each num 1x in stack
{
	t_node	*current;
	t_node	*temp;

	current = *stack_a;
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

t_node	*find_last(t_node ***stack_a) // Search for last node
{
	t_node	*temp;

	temp = **stack_a;
	while (temp->next)
		temp = temp->next;
	return (temp);
}
