# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wliu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/29 14:26:26 by wliu              #+#    #+#              #
#    Updated: 2017/02/15 11:42:47 by wliu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_is.c \
		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_itoa.c ft_itoa_j.c \
		ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
		ft_lstadd.c ft_lstiter.c ft_lstmap.c \
		ft_memset.c  ft_memcpy.c ft_memccpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_memalloc.c ft_memdel.c\
		ft_printf.c \
		ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_strlen.c ft_strdup.c ft_strcpy.c \
	  	ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
	  	ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
		ft_strnew.c ft_strdel.c ft_strclr.c \
		ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
		ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
		ft_toupper.c ft_tolower.c \
		ft_uns_int.c store_str.c store1.c store2.c \
		str_char_wchar.c str_sig_int.c str_sp_zero.c \
		str_str_wstr.c str_uns_int.c  num_in_arr.c math.c \
		arr_max_min.c ft_realloc.c get_next_line.c

O_FILES = $(SRC:.c=.o)


FLAGS = -c -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
		gcc $(FLAGS) $(SRC)
		ar rc $(NAME) $(O_FILES)
		ranlib $(NAME)

clean:
		/bin/rm -f $(O_FILES)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
