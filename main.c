/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:14:56 by btenzlin          #+#    #+#             */
/*   Updated: 2022/01/26 18:09:33 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stcks	stacks;
	int		split;

	split = 0;
	if (argc == 2)
	{
		argv = ft_split_new(argv[1], ' ');
		split = 1;
	}
	argc = check_input(argc, argv);
	init_list(argc, argv, &stacks);
	if (split)
		free_strings(argv);
	if (stacks.size_a <= 3)
		small_alg(&stacks);
	else if (stacks.size_a <= 5)
		med_alg(&stacks);
	else if (stacks.size_a <= 200)
		big_alg(&stacks);
	else
		biggest_alg(&stacks);
	free_stack(&stacks);
	return (0);
}
