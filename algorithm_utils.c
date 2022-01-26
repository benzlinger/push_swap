/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:10:06 by btenzlin          #+#    #+#             */
/*   Updated: 2022/01/24 14:20:38 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stcks *stacks)
{
	t_clst	*tmp;

	if (stacks->size_a <= 0)
		return (0);
	tmp = stacks->stack_a->next;
	while (tmp != stacks->stack_a)
	{
		if (tmp->value < tmp->next->value)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

int	find_min(t_clst *stack)
{
	t_clst	*tmp;
	t_clst	*min;
	int		count;
	int		pos;

	tmp = stack->next;
	min = tmp;
	count = 0;
	pos = 0;
	while (tmp != stack)
	{
		if (min->value > tmp->value)
		{
			pos = count;
			min = tmp;
		}
		tmp = tmp->next;
		count++;
	}
	if (min->value > stack->value)
	{
		pos = count;
		min = stack;
	}
	return (pos);
}

int	find_max(t_clst *stack)
{
	t_clst	*tmp;
	t_clst	*max;
	int		count;
	int		pos;

	tmp = stack->next;
	max = tmp;
	count = 0;
	pos = 0;
	while (tmp != stack)
	{
		if (max->value < tmp->value)
		{
			pos = count;
			max = tmp;
		}
		tmp = tmp->next;
		count++;
	}
	if (max->value < stack->value)
	{
		pos = count;
		max = stack;
	}
	return (pos);
}

static int	*median_helper(int *ints, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	temp = 0;
	while (i < size - 1)
	{
		while (j < (size - i - 1))
		{
			if (ints[j] < ints[j + 1])
			{
				temp = ints[j];
				ints[j] = ints[j + 1];
				ints[j + 1] = temp;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (ints);
}

void	median(t_stcks *stacks)
{
	int		i;
	int		*ints;
	t_clst	*tmp;

	ints = malloc(sizeof(int) * stacks->size_a);
	tmp = stacks->stack_a->next;
	i = 0;
	while (i < stacks->size_a)
	{
		ints[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	ints = median_helper(ints, stacks->size_a);
	if (stacks->size_a % 2 == 0)
		stacks->median_a = (ints[(stacks->size_a / 2) - 1]
				+ ints[(stacks->size_a / 2)]) / 2;
	else
		stacks->median_a = ints[(stacks->size_a / 2)];
	free(ints);
}
