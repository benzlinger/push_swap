/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:16:20 by btenzlin          #+#    #+#             */
/*   Updated: 2022/01/11 17:45:26 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_input(t_clst **argv)
{
	return (0);
}

int	main(int argc, char **argv)
{
	t_clst	*stack_a;
	t_clst	*stack_b;

	stack_a = init_list(argc, argv);
	stack_b = NULL;
	print_list(stack_a);
	// system("leaks push_swap");
	return (0);
}
