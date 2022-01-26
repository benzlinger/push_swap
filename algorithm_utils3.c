/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:13:59 by btenzlin          #+#    #+#             */
/*   Updated: 2022/01/24 16:31:59 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_value(t_stcks *stacks)
{
	t_clst	*tmp;
	t_clst	*min;

	tmp = stacks->stack_a->next;
	min = tmp;
	while (tmp != stacks->stack_a)
	{
		if (min->value > tmp->value)
			min = tmp;
		tmp = tmp->next;
	}
	if (min->value > tmp->value)
		min = tmp;
	return (min->value);
}

int	find_max_value(t_stcks *stacks)
{
	t_clst	*tmp;
	t_clst	*max;

	tmp = stacks->stack_a->next;
	max = tmp;
	while (tmp != stacks->stack_a)
	{
		if (max->value < tmp->value)
			max = tmp;
		tmp = tmp->next;
	}
	if (max->value < tmp->value)
		max = tmp;
	return (max->value);
}

void	push_between_median(t_stcks *stacks, int from, int to)
{
	int		count;
	int		size;
	t_clst	*tmp;

	count = 0;
	size = stacks->size_a;
	tmp = stacks->stack_a->next;
	while (count <= size)
	{
		if (tmp->value >= from && tmp->value <= to)
		{
			move_to_value(stacks, tmp->value);
			push_b(stacks, 1);
			tmp = stacks->stack_a->next;
		}
		else
			tmp = tmp->next;
		count++;
	}
}

void	move_to_value(t_stcks *stacks, int value)
{
	t_clst	*tmp;

	tmp = stacks->stack_a->next;
	while (tmp->value != value)
	{
		tmp = tmp->next;
		rot_a(stacks, 1);
	}
}

void	get_block(t_stcks *stacks, long min, long max)
{
	int	from;
	int	to;
	int	num;

	num = 7;
	from = min + (num * ((max - min) / 8));
	to = max;
	while (num > 0)
	{
		push_between_median(stacks, from, to);
		while (stacks->size_b)
			find_min_max(stacks);
		num--;
		to = from;
		from = min + (num *((max - min) / 8));
	}
	from = min;
	to = min + ((max - min) / 8);
	push_between_median(stacks, from, to);
	while (stacks->size_b)
		find_min_max(stacks);
}
