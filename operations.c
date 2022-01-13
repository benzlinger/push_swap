/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:15:01 by btenzlin          #+#    #+#             */
/*   Updated: 2022/01/13 14:48:12 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_clst *last)
{
	t_clst	*tmp;
	int		first;
	int		second;

	tmp = last->next;
	first = tmp->value;
	second = tmp->next->value;
	tmp->value = second;
	tmp->next->value = first;
}

t_clst	*push(t_clst *from, t_clst *to)
{
	if (!from)
		return (NULL);
	else
	{
		to = insert_first(to, from->next->value);
		from = del_first(from);
	}
	return (from);
}
