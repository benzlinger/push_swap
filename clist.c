/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:22:55 by btenzlin          #+#    #+#             */
/*   Updated: 2022/01/11 17:09:40 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_clst	*insert_empty(t_clst *last, int value)
{
	t_clst	*new;

	if (last != NULL)
		return (last);
	new = malloc(sizeof(t_clst));
	new->value = value;
	last = new;
	last->next = last;
	return (last);
}

t_clst	*insert_last(t_clst *last, int value)
{
	t_clst	*new;

	if (!last)
		return (insert_empty(last, value));
	new = malloc(sizeof(t_clst));
	new->value = value;
	new->next = last->next;
	last->next = new;
	last = new;
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
	printf("end of list\n");
}

t_clst	*init_list(int argc, char **argv)
{
	t_clst	*last;
	int		count;

	last = NULL;
	count = 2;
	if (argc <= 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	last = insert_empty(last, ft_atoi(argv[1]));
	while (argv[count])
	{
		last = insert_last(last, ft_atoi(argv[count]));
		count++;
	}
	return (last);
}
