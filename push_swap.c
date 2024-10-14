/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jozefpluta <jozefpluta@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:45:03 by jozefpluta        #+#    #+#             */
/*   Updated: 2024/10/14 20:16:24 by jozefpluta       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

Node *head = NULL;

Node *add_node(int data)
{
    Node *new;
    if (head == NULL)
    {
        new = malloc(sizeof(Node));
        if (new == NULL)
            return (NULL);
        new->data = data;
        new->i = 0;
        head = new;
        new->next = NULL;
    }
    else
    {
        new = malloc(sizeof(Node));
        if (new == NULL)
            return (NULL);
        new->i = 0;
        new->data = data;
        head->i++;
        new->next = head;
        head = new;
    }
    return (new);
}

void free_list(Node *head)
{
    Node *current = head;
    Node *next_node;

    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
}

int main(int argc, char **argv)
{
    int i = 1;
    if (argc == 1)
        return (0);
    else 
        while (i < argc)
        {
           add_node(ft_atoi(argv[i])); 
        }
    Node *current = head;
    while (current != NULL)
    {
        printf("%d, ", current->data);
        current = current->next;
    }
    free_list(head);
    return (0);
}