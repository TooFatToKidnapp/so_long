# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/08 14:36:35 by aabdou            #+#    #+#              #
#    Updated: 2022/03/19 16:56:45 by aabdou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = so_long

HEADER = so_long.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit 

MAKE = make -C

SRC = 	so_long.c\
		GNL/get_next_line.c\
		draw.c\
		GNL/get_next_line_utils.c\
		main.c\
		map.c\
		map2.c\
		map3.c\
		player.c\
		moves.c\
		
OBJ = $(SRC:.c=.o)

all: $(NAME) 

$(NAME) : ft_printf ft_libft $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ) libft/libft.a printf/ft_printf.a -o $(NAME)

ft_libft :
	$(MAKE) libft

ft_printf :
	$(MAKE) printf				
clean :
	rm -f *.o
	$(MAKE) libft clean && $(MAKE) printf clean

fclean : clean	
	@$(MAKE) libft fclean && $(MAKE) printf fclean
	@rm -f so_long

re : fclean all