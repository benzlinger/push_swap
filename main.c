/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:40:39 by btenzlin          #+#    #+#             */
/*   Updated: 2021/12/28 11:24:01 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct node {
	int			value;
	struct node	*next;
};
typedef struct node node_t;

void	print_list(node_t *head)
{
	node_t *temp;

	temp = head;
	while (temp)
	{
		printf("%d - ", temp->value);
		temp = temp->next;
	}
	printf("end of list\n");
}

node_t	*new_node(int value)
{
	node_t *result;

	result = malloc(sizeof(node_t));
	result->value = value;
	result->next = NULL;
	return (result);
}

node_t	*insert_at_head(node_t **head, node_t *insrt)
{
	insrt->next = *head;
	*head = insrt;
	return (insrt);
}

node_t	*insert_at_end(node_t *head, node_t *insrt)
{
	while(head)
	{
		head = head->next;
	}
	head->next = insrt;
	insrt->next = NULL;
	return (0);
}

void insert_after(node_t *before_node, node_t *new_node)
{
	new_node->next = before_node->next;
	before_node->next = new_node;
}

node_t *find_node(node_t *head, int value)
{
	node_t	*temp;

	temp = head;
	while (temp)
	{
		if (temp->value == value)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

int	main(void)
{
	node_t	*head;
	node_t	*temp;
	int 	count;

	head = NULL;
	count = 0;
	while (count <= 20)
	{
		temp = new_node(count);
		insert_at_head(&head, temp);
		count++;
	}
	temp = find_node(head, 4);
	//printf("%d\n", temp->value);
	insert_after(temp, new_node(99));
	print_list(head);
	//system("leaks a.out");
	return (0);
}
