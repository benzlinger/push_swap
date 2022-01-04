/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cll.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 13:05:42 by btenzlin          #+#    #+#             */
/*   Updated: 2022/01/04 15:57:27 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_empty(t_lst *head)
{
	return (head == NULL);
}

int	get_len(t_lst *head)
{
	int		len;
	t_lst	*tmp;

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

void	print_list(t_lst *head)
{
	t_lst	*temp;

	temp = head;
	while (temp)
	{
		printf("%d - ", temp->value);
		temp = temp->next;
	}
	printf("end of list\n");
}

t_lst	*new_node(int value)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst));
	new->value = value;
	new->next = NULL;
	return (new);
}

t_lst	*insert_last(t_lst *head, int value)
{
	t_lst	*new;
	t_lst	*tmp;

	new = new_node(value);
	tmp = head;
	new->value = value;
	new->next = NULL;
	if (!head)
	{
		head = new;
		return (head);
	}
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
	return (head);
}

// int	free_list(t_lst *head)
// {
// 	return (0);
// }

int	main(int argc, char **argv)
{
	int		count;
	t_lst	*head;

	count = 2;
	if (argc < 1)
		return (0);
	head = new_node(ft_atoi(argv[1]));
	while (argv[count])
	{
		insert_last(head, ft_atoi(argv[count]));
		count++;
	}
	print_list(head);
	// free_list(head);
	return (0);
}
