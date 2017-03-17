# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wliu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/25 12:11:42 by wliu              #+#    #+#              #
#    Updated: 2017/02/15 12:47:57 by wliu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME0 = libft/libft.a

NAME1 = checker

NAME2 = push_swap

SRC1 = main1.c src/check_valid.c src/create_stack.c \
		src/free.c src/is_sort.c src/max_min.c \
		src/op1.c src/op2.c src/print.c \
		src/res.c src/solve.c \
		src/solve_large.c src/solve_large2.c \
		src/solve_large3.c src/solve_large4.c\




SRC2 = main2.c src/check_valid.c src/create_stack.c \
		src/free.c src/is_sort.c src/max_min.c \
		src/op1.c src/op2.c src/print.c \
		src/res.c src/solve.c \
		src/solve_large.c src/solve_large2.c \
		src/solve_large3.c src/solve_large4.c\

OBJ = $(SRC1:.c=.o) $(SRC2:.c=.o)

CC = gcc

FLAG = -Wall -Werror -Wextra -o

RM = /bin/rm -f

all: $(NAME0) $(NAME1) $(NAME2)

$(NAME0):
	@make -C libft/

$(NAME1):
	$(CC) $(FLAG) $(NAME1) $(SRC1) $(NAME0)

$(NAME2):
	$(CC) $(FLAG) $(NAME2) $(SRC2) $(NAME0)

clean:
	@make clean -C libft/
	$(RM) $(OBJ)

fclean: clean
	@make fclean -C libft/
	$(RM) $(NAME1) $(NAME2)

re: fclean all
	@make re -C libft/

.PHONY: all clean fclean re
