# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 11:42:37 by btenzlin          #+#    #+#              #
#    Updated: 2022/01/26 14:57:25 by btenzlin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS =	main.c \
		check.c \
		list.c \
		operations_swap.c \
		operations_push.c \
		operations_rotate.c \
		operations_rev_rotate.c \
		algorithm.c \
		new_split.c \
		algorithm_utils.c \
		algorithm_utils2.c \
		algorithm_utils3.c

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	@cd libft && make
	$(CC) $(FLAGS) $(OBJS) libft/libft.a -o $(NAME)

libft:
	@cd libft && make

re: fclean all

clean:
	@cd libft && make clean
	$(RM) $(OBJS);

fclean:
	@cd libft && make fclean
	$(RM) $(NAME) $(OBJS)

.PHONY: all clean fclean re libft
