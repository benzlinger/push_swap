/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:43:56 by btenzlin          #+#    #+#             */
/*   Updated: 2022/01/25 12:37:50 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_alg(t_stcks *stacks)
{
	t_clst	*tmp;

	if (stacks->size_a == 1 || is_sorted(stacks))
		return ;
	if (stacks->size_a == 2)
		swap_a(stacks, 1);
	if (stacks->size_a == 3)
	{
		tmp = stacks->stack_a->next;
		if (tmp->value == find_max_value(stacks))
			rot_a(stacks, 1);
		while (!is_sorted(stacks))
		{
			tmp = stacks->stack_a->next;
			if (tmp->value < tmp->next->value)
				rev_rot_a(stacks, 1);
			else
				swap_a(stacks, 1);
		}
	}
}

void	med_alg(t_stcks *stacks)
{
	if (is_sorted(stacks))
		return ;
	move_to_min(stacks);
	push_b(stacks, 1);
	if (stacks->size_a == 4)
	{
		move_to_min(stacks);
		push_b(stacks, 1);
	}
	small_alg(stacks);
	push_a(stacks, 1);
	if (stacks->size_b)
		push_a(stacks, 1);
}

void	big_alg(t_stcks *stacks)
{
	if (is_sorted(stacks))
		return ;
	median(stacks);
	push_below_median(stacks, stacks->median_a);
	while (stacks->size_b)
		find_min_max(stacks);
	push_above_median(stacks, stacks->median_a);
	while (stacks->size_b)
		find_min_max(stacks);
	move_to_min(stacks);
}

void	biggest_alg(t_stcks *stacks)
{
	int	min;
	int	max;

	if (is_sorted(stacks))
		return ;
	min = find_min_value(stacks);
	max = find_max_value(stacks);
	get_block(stacks, min, max);
	move_to_min(stacks);
	if (!is_sorted(stacks))
		big_alg(stacks);
}
