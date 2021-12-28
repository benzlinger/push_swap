/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cll.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 13:05:42 by btenzlin          #+#    #+#             */
/*   Updated: 2021/12/28 14:13:01 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
	int			value;
	struct node	*next;
};
typedef struct node	node_t;

bool	is_empty(node_t *head)
{
	return (head == NULL);
}

int	get_len(node_t *head)
{
	int		len;
	node_t	*tmp;

	len = 0;
	tmp = head;
	if (!tmp)
		return (0);
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

node_t	*new_node(int value)
{
	node_t	*result;

	result = malloc(sizeof(node_t));
	result->value = value;
	result->next = NULL;
	return (result);
}

node_t	*insert_at_head(node_t *head, node_t *insrt)
{
	insrt->next = head;
	head = insrt;
	return (insrt);
}

int	main(void)
{
	return (0);
}
