# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/08 14:36:35 by aabdou            #+#    #+#              #
#    Updated: 2022/03/22 20:28:05 by aabdou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

B_NAME = so_long_bonus

NAME = so_long

HEADER = so_long.h

B_HEADER = so_long_BONUS.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit 

MAKE = make -C

B_SRC = bonus/so_long_BONUS.c\
		bonus/draw_BONUS.c\
		bonus/main_BONUS.c\
		bonus/map_BONUS.c\
		bonus/map2_BONUS.c\
		bonus/map3_BONUS.c\
		bonus/player_BONUS.c\
		bonus/moves_BONUS.c\
		bonus/enemy_BONUS.c \
		GNL/get_next_line_utils.c\
		GNL/get_next_line.c\

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
	
B_OBJ = $(B_SRC:.c=.o)
OBJ = $(SRC:.c=.o)

all: $(NAME) 

$(NAME) : ft_printf ft_libft $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ) libft/libft.a printf/ft_printf.a -o $(NAME)

bonus : $(B_NAME)

$(B_NAME) : ft_printf ft_libft $(B_OBJ) 
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(B_OBJ) libft/libft.a printf/ft_printf.a -o $(B_NAME)

ft_libft :
	@$(MAKE) libft

ft_printf :
	@$(MAKE) printf	

	
clean :
	@rm -f *.o && rm -f bonus/*.o
	@rm -f GNL/*.o && rm -f bonus/GNL/*.o
	@$(MAKE) libft clean && $(MAKE) printf clean

fclean : clean	
	@$(MAKE) libft fclean && $(MAKE) printf fclean
	@rm -f so_long so_long_bonus

re : fclean all

re_bonus : fclean bonus