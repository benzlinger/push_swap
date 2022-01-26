/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:28:01 by btenzlin          #+#    #+#             */
/*   Updated: 2022/01/26 13:11:42 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stcks *stacks, int print)
{
	t_clst	*tmp;
	int		value;

	if (stacks->size_a > 1)
	{
		tmp = stacks->stack_a->next;
		value = tmp->value;
		tmp->value = tmp->next->value;
		tmp->next->value = value;
	}
	if (print)
		ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_stcks *stacks, int print)
{
	t_clst	*tmp;
	int		value;

	if (stacks->size_b > 1)
	{
		tmp = stacks->stack_b->next;
		value = tmp->value;
		tmp->value = tmp->next->value;
		tmp->next->value = value;
	}
	if (print)
		ft_putstr_fd("sb\n", 1);
}

void	swap_both(t_stcks *stacks, int print)
{
	swap_a(stacks, 0);
	swap_b(stacks, 0);
	if (print)
		ft_putstr_fd("ss\n", 1);
}
