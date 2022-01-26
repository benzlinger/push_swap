/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:46:23 by btenzlin          #+#    #+#             */
/*   Updated: 2022/01/25 11:24:56 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_clst	*new_node(int	value)
{
	t_clst		*new;

	new = malloc(sizeof(t_clst));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

t_stcks	*init_list(int argc, char **argv, t_stcks *stacks)
{
	int		count;
	t_clst	*tmp;

	stacks->stack_b = NULL;
	stacks->size_b = 0;
	stacks->size_a = argc - 1;
	count = 1;
	stacks->stack_a = new_node(ft_atoi_ps(argv[count]));
	tmp = stacks->stack_a;
	while (argv[++count])
	{
		tmp->next = new_node(ft_atoi_ps(argv[count]));
		tmp = tmp->next;
	}
	tmp->next = stacks->stack_a;
	stacks->stack_a = tmp;
	return (stacks);
}

void	free_stack(t_stcks *stacks)
{
	int		count;
	t_clst	*tmp;

	count = 0;
	while (count < stacks->size_a)
	{
		tmp = stacks->stack_a->next;
		free(stacks->stack_a);
		stacks->stack_a = tmp;
		count++;
	}
}
