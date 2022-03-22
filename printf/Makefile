# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/26 05:14:59 by aabdou            #+#    #+#              #
#    Updated: 2022/03/21 23:41:50 by aabdou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a

SRC = ft_print_char.c\
	ft_print_digit.c\
	ft_print_hex.c\
	ft_printf.c\

OBJ = $(SRC:.c=o)

HEADER = ft_printf.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME) $(HEADER)

$(NAME): $(SRC) $(HEADER)
	$(CC) $(CFLAGS) -c $(SRC)
	ar rc $(NAME) *.o

clean: 
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME) *.a

re: fclean all

.PHONY: all re clean fclean
