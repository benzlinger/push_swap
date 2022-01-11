/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:16:20 by btenzlin          #+#    #+#             */
/*   Updated: 2022/01/11 17:11:44 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_clst	*last;

	last = init_list(argc, argv);
	print_list(last);
	// last = last->next;
	// print_list(last);
	return (0);
}
