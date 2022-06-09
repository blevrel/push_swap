# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blevrel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 08:50:48 by blevrel           #+#    #+#              #
#    Updated: 2022/06/08 17:59:44 by blevrel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =	srcs/push_swap.c srcs/check_errors.c srcs/init_stack.c srcs/sorting_functions.c \
		srcs/stack_manipulation.c srcs/sorting_functions_2.c srcs/sorting_functions_3.c \
		srcs/sort_list.c srcs/is_sorted.c srcs/print_list_manipulation.c \
		srcs/sort_big_list.c

OBJS = ${SRCS:.c=.o}

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIB = -L libft -lft

HEAD = -I libft -I includes

RM = rm -f

all: ${NAME}

clean:
	make clean -C libft
	${RM} ${OBJS}

fclean: clean
	make fclean -C libft
	${RM} ${NAME}

re: fclean all

.c.o:
	${CC} ${FLAGS} -c ${HEAD} $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	make -C libft
	${CC} ${FLAGS} ${OBJS} ${HEAD} ${LIB} -o ${NAME} -g
