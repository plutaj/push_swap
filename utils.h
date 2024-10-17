#ifndef UTILS_H
# define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_node
{
	int			data;
	int			i;
	struct s_node	*next;
}				t_node;

int		ft_atoi(const char *str);
t_node	*add_node(int data);
void	free_list(t_node *head);
int		find_int(const char *pstr, int i);
void	print_error();

#endif // UTILS_H
