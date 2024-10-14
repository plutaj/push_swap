#ifndef UTILS_H
#define UTILS_H

typedef struct Node{
    int     data;
    int     i;
    struct Node    *next;
} Node;

int         ft_atoi(const char *str);
Node        *add_node(int data);
void        free_list(Node *head);
int	        find_int(const char *pstr, int i);

#endif // UTILS_H
