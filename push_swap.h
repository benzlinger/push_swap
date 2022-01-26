/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:39:09 by btenzlin          #+#    #+#             */
/*   Updated: 2022/01/26 16:47:00 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_clst
{
	int				value;
	struct s_clst	*next;
}					t_clst;

typedef struct s_stcks
{
	t_clst	*stack_a;
	t_clst	*stack_b;
	int		size_a;
	int		size_b;
	int		median_a;
	int		pos_max;
	int		pos_min;
	int		last_max;
}			t_stcks;

/* checker */
int		check_input(int argc, char **argv);
long	ft_atoi_ps(const char *str);

/* initialize list */
t_stcks	*init_list(int argc, char **argv, t_stcks *stacks);
t_clst	*new_node(int	value);

/* list utils */
void	print_list_a(t_stcks *stacks);
void	print_list_b(t_stcks *stacks);
void	free_stack(t_stcks *stacks);

/* swap */
void	swap_a(t_stcks *stacks, int print);
void	swap_b(t_stcks *stacks, int print);
void	swap_both(t_stcks *stacks, int print);

/* push */
void	push_a(t_stcks *stacks, int print);
void	push_b(t_stcks *stacks, int print);

/* rotate */
void	rot_a(t_stcks *stacks, int print);
void	rot_b(t_stcks *stacks, int print);
void	rr(t_stcks *stacks, int print);

/* reverse rotate */
void	rev_rot_a(t_stcks *stacks, int print);
void	rev_rot_b(t_stcks *stacks, int print);
void	rrr(t_stcks *stacks, int print);

/* algorithm */
void	small_alg(t_stcks *stacks);
void	med_alg(t_stcks *stacks);
void	big_alg(t_stcks *stacks);
void	biggest_alg(t_stcks *stacks);

/* algorithm utils */
int		is_sorted(t_stcks *stacks);
int		find_min(t_clst *stack);
int		find_max(t_clst *stack);
void	median(t_stcks *stacks);

/* algorithm utils 2 */
void	push_below_median(t_stcks *stacks, int median);
void	push_above_median(t_stcks *stacks, int median);
void	move_to_min(t_stcks *stacks);
void	find_min_max(t_stcks *stacks);
void	push_min_max(t_stcks *stacks, int pos);

/* algorithm utils 3 */
int		find_min_value(t_stcks *stacks);
int		find_max_value(t_stcks *stacks);
void	push_between_median(t_stcks *stacks, int from, int to);
void	move_to_value(t_stcks *stacks, int value);
void	get_block(t_stcks *stacks, long min, long max);

/* new split */
char	**ft_split_new(char const *s, char c);
char	**free_strings(char **arr);

#endif
