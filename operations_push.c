/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:08:03 by btenzlin          #+#    #+#             */
/*   Updated: 2022/01/24 14:42:29 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_clst	*push_helper(t_clst *ab_tmp, t_clst *tmp)
{
	if (!ab_tmp)
	{
		ab_tmp = tmp;
		ab_tmp->next = ab_tmp;
	}
	else
	{
		tmp->next = ab_tmp->next;
		ab_tmp->next = tmp;
	}
	return (ab_tmp);
}

void	push_a(t_stcks *stacks, int print)
{
	t_clst	*a_tmp;
	t_clst	*b_tmp;
	t_clst	*tmp;

	a_tmp = stacks->stack_a;
	b_tmp = stacks->stack_b;
	if (stacks->size_b == 1)
	{
		tmp = stacks->stack_b;
		tmp->next = tmp;
		stacks->stack_b = NULL;
	}
	else
	{
		tmp = b_tmp->next;
		b_tmp->next = tmp->next;
		tmp->next = tmp;
		stacks->stack_b = b_tmp;
	}
	stacks->stack_a = push_helper(a_tmp, tmp);
	stacks->size_a++;
	stacks->size_b--;
	if (print)
		ft_putstr_fd("pa\n", 1);
}

void	push_b(t_stcks *stacks, int print)
{
	t_clst	*a_tmp;
	t_clst	*b_tmp;
	t_clst	*tmp;

	a_tmp = stacks->stack_a;
	b_tmp = stacks->stack_b;
	if (stacks->size_a == 1)
	{
		tmp = stacks->stack_a;
		tmp->next = tmp;
		stacks->stack_a = NULL;
	}
	else
	{
		tmp = a_tmp->next;
		a_tmp->next = tmp->next;
		tmp->next = tmp;
		stacks->stack_a = a_tmp;
	}
	stacks->stack_b = push_helper(b_tmp, tmp);
	stacks->size_a--;
	stacks->size_b++;
	if (print)
		ft_putstr_fd("pb\n", 1);
}
