/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:39:09 by btenzlin          #+#    #+#             */
/*   Updated: 2022/01/13 14:37:56 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_clst
{
	int				value;
	struct s_clst	*next;
}					t_clst;

t_clst	*insert_empty(t_clst *last, int value);
t_clst	*insert_first(t_clst *last, int value);
t_clst	*insert_last(t_clst *last, int value);
void	print_list(t_clst *last);
t_clst	*del_first(t_clst *last);
t_clst	*init_list(char **argv);
void	check_input(int argc, char **argv);
void	swap(t_clst *last);
t_clst	*push(t_clst *from, t_clst *to);

#endif
