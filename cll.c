/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cll.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 13:05:42 by btenzlin          #+#    #+#             */
/*   Updated: 2021/12/28 15:29:59 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_empty(t_list *head)
{
	return (head == NULL);
}

int	get_len(t_list *head)
{
	int		len;
	t_list	*tmp;

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

// void	print_list(t_list *head)
// {
// 	t_list	*temp;

// 	temp = head;
// 	while (temp)
// 	{
// 		printf("%d - ", temp->content);
// 		temp = temp->next;
// 	}
// 	printf("end of list\n");
// }

// node_t	*new_node(int value)
// {
// 	node_t	*result;

// 	result = malloc(sizeof(node_t));
// 	result->value = value;
// 	result->next = NULL;
// 	return (result);
// }

// node_t	*insert_last(node_t *head, int num)
// {
// 	node_t	*new;
// 	node_t	*tmp;

// 	new = new_node(num);
// 	tmp = head;
// 	if (is_empty(tmp))
// 	{
// 		head = new;
// 		return (head);
// 	}
// 	else
// 	{
// 		while (tmp)
// 		{
// 			tmp = tmp->next;
// 		}
// 		tmp->next = new;
// 	}
// 	return (head);
// }

int	main(void)
{
	t_list	*head;
	void	*value;

	value = (void *)10;
	head = ft_lstnew(value);
	printf("%d", (int)head->content);
	return (0);
}
