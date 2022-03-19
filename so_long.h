/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:59:12 by aabdou            #+#    #+#             */
/*   Updated: 2022/03/19 16:49:19 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include<mlx.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include"GNL/get_next_line.h"
#include"libft/libft.h"
#include"printf/ft_printf.h"

typedef struct s_game
{
    int     y_p;
    int     x_p;
    void	*mlx_ptr;
    void	*mlx_win;
    void    *img;
    int     wall;
    int     enemy;
    int     empty;
    char	**map;
    int		img_width;
    int		img_height;
    int		p_x;
    int		p_y;
    int		moves;
    int     player;    
    int     exit;
    int     collectable; 
    int     count; 
}			t_game;

int check_file_type(char *str, char *type);
void check_file(char *str);
char **stor_map(char *map);
void check_if_rectangular(t_game **var);
void check_walls(t_game **var);
void    check_content(t_game *var);
int	ft_strlen_nl(char *str);
int	get_height(char **map);
void check_map(t_game *var);
int map_content(t_game *var,char c);
void error(t_game *var);
void	put_image_to_map(char p, int x1, int y1, t_game **v);
void	put_image(t_game ***v, int x, int y, char *img);
void	render_map(t_game *vars);
int	quit(t_game *v);
int	key_hook(int keycode, t_game *vars);
void	to_right(t_game **v);
void	to_left(t_game **v);
void	to_down(t_game **v);
void	to_up(t_game **v);
void	collected(t_game ***v);
void ft_free(t_game ***var, char *err);
void	exit_door(t_game ***v);
void	put_text(t_game ***v);
int	animation(t_game *var);
void	open_exit(t_game **var);


#endif