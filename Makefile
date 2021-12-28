# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 11:42:37 by btenzlin          #+#    #+#              #
#    Updated: 2021/12/28 14:58:12 by btenzlin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
AR = ar rc
RM = rm -f

main: cll.c
	@cd libft && make bonus
	$(CC) $(FLAGS) cll.c libft/libft.a -o push_swap

libft:
	@cd libft && make bonus

clean:
	@cd libft && make clean

fclean: clean
	@cd libft && make fclean
	$(RM) push_swap
