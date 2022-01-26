/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:29:47 by btenzlin          #+#    #+#             */
/*   Updated: 2022/01/20 13:40:45 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_a(t_stcks *stacks, int print)
{
	t_clst	*tmp;

	if (stacks->size_a > 1)
	{
		tmp = stacks->stack_a->next;
		stacks->stack_a = tmp;
		if (print)
			ft_putstr_fd("ra\n", 1);
	}
}

void	rot_b(t_stcks *stacks, int print)
{
	t_clst	*tmp;

	if (stacks->size_b > 1)
	{
		tmp = stacks->stack_b->next;
		stacks->stack_b = tmp;
		if (print)
			ft_putstr_fd("rb\n", 1);
	}
}

void	rr(t_stcks *stacks, int print)
{
	rot_a(stacks, 0);
	rot_b(stacks, 0);
	if (print)
		ft_putstr_fd("rr\n", 1);
}
