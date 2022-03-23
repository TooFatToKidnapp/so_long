/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_BONUS.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 20:27:46 by aabdou            #+#    #+#             */
/*   Updated: 2022/03/23 17:30:13 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_BONUS.h"

int	check(t_game ***vars, int x, int y)
{
	if ((**vars)->map[y][x] == '0' && (**vars)->map[y][x + 2] == '0'
		&& (**vars)->map[y][x + 2] == '0')
	{
		(**vars)->e_vars.sign = 0;
		(**vars)->e_vars.x_e = x;
		(**vars)->e_vars.y_e = y;
		return (1);
	}
	return (0);
}

int	get_position_for_enemy(t_game **vars)
{
	int			y;
	int			x;
	int			height;

	y = 0;
	height = get_height((*vars)->map);
	if ((*vars)->e_vars.sign)
	{
		while (y != height)
		{
			x = 0;
			while ((*vars)->map[y][x] != '\0')
			{
				if (check(&vars, x, y))
					return (1);
				x++;
			}
			y++;
		}
		return (0);
	}
	return (1);
}

void	ft_lose(t_game **v, char *err)
{
	int	x;

	x = 0;
	while ((*v)->map[x])
	{
		free((*v)->map[x]);
		x++;
	}
	free((*v)->map);
	ft_printf("%s", err);
	exit(0);
}

void	render_img(t_game **vars)
{
	int			img_w;
	int			img_h;

	(*vars)->e_vars.imgs[0] = "./img/bearR.xpm";
	(*vars)->e_vars.imgs[1] = "./img/bear1R.xpm";
	(*vars)->e_vars.imgs[2] = "./img/bearR.xpm";
	(*vars)->img = mlx_xpm_file_to_image(
			(*vars)->mlx_ptr, "./img/tile0.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*vars)->mlx_ptr, (*vars)->mlx_win, (*vars)->img,
		(*vars)->e_vars.x_e * 64, (*vars)->e_vars.y_e * 64);
	(*vars)->img = mlx_xpm_file_to_image(
			(*vars)->mlx_ptr, (*vars)->e_vars.imgs[(*vars)->e_vars.x],
			&img_w, &img_h);
	mlx_put_image_to_window(
		(*vars)->mlx_ptr, (*vars)->mlx_win, (*vars)->img,
		(*vars)->e_vars.x_e * 64, (*vars)->e_vars.y_e * 64);
}

void	move_enemy(t_game **vars)
{
	int			img_w;
	int			img_h;

	(*vars)->img = mlx_xpm_file_to_image(
			(*vars)->mlx_ptr, "./img/tile0.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*vars)->mlx_ptr, (*vars)->mlx_win, (*vars)->img,
		(*vars)->e_vars.x_e * 64, (*vars)->e_vars.y_e * 64);
	if ((*vars)->map[(*vars)->e_vars.y_e][(*vars)->e_vars.x_e + 1] != '1' &&
		(*vars)->map[(*vars)->e_vars.y_e][(*vars)->e_vars.x_e + 1] != 'C' &&
		(*vars)->map[(*vars)->e_vars.y_e][(*vars)->e_vars.x_e + 1] != 'E' &&
		(*vars)->e_vars.path_to_move == 0)
		(*vars)->e_vars.x_e++;
	else
		(*vars)->e_vars.path_to_move = 1;
	if ((*vars)->map[(*vars)->e_vars.y_e][(*vars)->e_vars.x_e - 1] != '1' &&
		(*vars)->map[(*vars)->e_vars.y_e][(*vars)->e_vars.x_e - 1] != 'C' &&
		(*vars)->map[(*vars)->e_vars.y_e][(*vars)->e_vars.x_e - 1] != 'E' &&
		(*vars)->e_vars.path_to_move == 1)
		(*vars)->e_vars.x_e--;
	else
		(*vars)->e_vars.path_to_move = 0;
}
