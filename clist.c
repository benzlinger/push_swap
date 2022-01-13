/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:22:55 by btenzlin          #+#    #+#             */
/*   Updated: 2022/01/13 14:45:30 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_clst	*insert_empty(t_clst *last, int value)
{
	t_clst	*new;

	if (last)
		return (last);
	new = malloc(sizeof(t_clst));
	if (!new)
		return (NULL);
	new->value = value;
	last = new;
	last->next = last;
	return (last);
}

t_clst	*insert_first(t_clst *last, int value)
{
	t_clst	*new;

	if (last == NULL)
		return (insert_empty(last, value));
	new = malloc(sizeof(t_clst));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = last->next;
	last->next = new;
	return (last);
}

t_clst	*insert_last(t_clst *last, int value)
{
	t_clst	*new;

	if (last == NULL)
		return (insert_empty(last, value));
	new = malloc(sizeof(t_clst));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = last->next;
	last->next = new;
	last = new;
	return (last);
}

t_clst	*del_first(t_clst *last)
{
	t_clst	*tmp;

	if (!last)
		return (last);
	if (last->next == last)
	{
		free(last);
		last = NULL;
		return (last);
	}
	tmp = last->next;
	last->next = tmp->next;
	free(tmp);
	tmp = NULL;
	return (last);
}

void	print_list(t_clst *last)
{
	t_clst	*tmp;

	if (!last)
	{
		printf("Empty list.\n");
		return ;
	}
	tmp = last->next;
	while (tmp != last)
	{
		printf("%d - ", tmp->value);
		tmp = tmp->next;
	}
	printf("%d - ", tmp->value);
	if (tmp == last)
		printf("end of list\n");
}

t_clst	*init_list(char **argv)
{
	t_clst	*last;
	int		count;

	last = NULL;
	count = 2;
	last = insert_empty(last, ft_atoi(argv[1]));
	while (argv[count])
	{
		last = insert_last(last, ft_atoi(argv[count]));
		count++;
	}
	return (last);
}
