/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:38:27 by jpluta            #+#    #+#             */
/*   Updated: 2024/12/01 13:43:23 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Check if argument is valid (not a char etc)
void	is_arg_valid(char *argv)
{
	int			i;
	long long	a;

	i = 0;
	while (argv[i])
	{
		if ((argv[i] == '-' || argv[i] == '+')
			&& (ft_isdigit(argv[i + 1]) == 1))
			i++;
		else if (argv[i] == ' ')
			i++;
		else if (ft_isdigit(argv[i]) == 0)
			print_error();
		i++;
	}
	a = ft_atol(argv);
	if (a > INT_MAX || a < INT_MIN)
		print_error();
}

// Check for each num 1x in stack
void	is_num_double(t_node **stack_a)
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
			{
				free_list(*stack_a);
				print_error();
			}
			temp = temp->next;
		}
		temp = NULL;
		current = current->next;
	}
}

// Search for last node
t_node	*find_last(t_node **stack_a)
{
	t_node	*temp;

	temp = *stack_a;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

t_node	*find_before_last(t_node **stack_a)
{
	t_node	*temp;

	temp = *stack_a;
	while (temp->next->next)
		temp = temp->next;
	return (temp);
}

int	single_arg_case(t_node **stack_a)
{
	if ((*stack_a)->next == NULL)
	{
		free_list(&(**stack_a));
		return (1);
	}
	return (0);
}
