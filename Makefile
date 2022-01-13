# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 11:42:37 by btenzlin          #+#    #+#              #
#    Updated: 2022/01/12 13:32:23 by btenzlin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
AR = ar rc
RM = rm -f

SRCS = clist.c \
		main.c \
		check.c \
		operations.c

OBJS = ${SRCS:.c=.o}

main: $(OBJS)
	@cd libft && make bonus
	$(CC) $(FLAGS) $(SRCS) libft/libft.a -o push_swap

libft:
	@cd libft && make bonus

clean:
	@cd libft && make clean
	$(RM) $(OBJS);

fclean: clean
	@cd libft && make fclean
	$(RM) push_swap $(OBJS)
