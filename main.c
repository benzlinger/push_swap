/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:16:20 by btenzlin          #+#    #+#             */
/*   Updated: 2022/01/13 14:46:30 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_clst	*stack_a;
	t_clst	*stack_b;

	check_input(argc, argv);
	stack_a = init_list(argv);
	stack_b = NULL;
	//stack_b = insert_first(stack_b, 8);
	print_list(stack_a);
	print_list(stack_b);
	stack_a = push(stack_a, stack_b);
	print_list(stack_a);
	print_list(stack_b);
	//system("leaks push_swap");		//remove when finished
	return (0);
}
