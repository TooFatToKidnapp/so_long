/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_BONUS.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:16:47 by aabdou            #+#    #+#             */
/*   Updated: 2022/03/22 19:08:25 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_BONUS.h"

void	to_left(t_game **v)
{
	int		img_w;
	int		img_h;

	(*v)->img = mlx_xpm_file_to_image(
			(*v)->mlx_ptr, "./img/tile0.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*v)->mlx_ptr, (*v)->mlx_win, (*v)->img, (*v)->x_p, (*v)->y_p);
	if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64) - 1] == 'E')
	{
		if ((*v)->collectable <= 0)
			exit_door(&v);
	}
	else if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64) - 1] != '1')
	{
		(*v)->x_p -= 64;
		put_text(&v);
	}
	if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64)] == 'C')
		collected(&v);
	(*v)->img = mlx_xpm_file_to_image(
			(*v)->mlx_ptr, "./img/pg1.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*v)->mlx_ptr, (*v)->mlx_win, (*v)->img, (*v)->x_p, (*v)->y_p);
}

void	to_down(t_game **v)
{
	int		img_w;
	int		img_h;

	(*v)->img = mlx_xpm_file_to_image(
			(*v)->mlx_ptr, "./img/tile0.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*v)->mlx_ptr, (*v)->mlx_win, (*v)->img, (*v)->x_p, (*v)->y_p);
	if ((*v)->map[((*v)->y_p / 64) + 1][((*v)->x_p / 64)] == 'E')
	{
		if ((*v)->collectable <= 0)
			exit_door(&v);
	}
	else if ((*v)->map[((*v)->y_p / 64) + 1][((*v)->x_p / 64)] != '1')
	{
		(*v)->y_p += 64;
		put_text(&v);
	}
	if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64)] == 'C')
		collected(&v);
		(*v)->img = mlx_xpm_file_to_image(
			(*v)->mlx_ptr, "./img/pg1.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*v)->mlx_ptr, (*v)->mlx_win, (*v)->img, (*v)->x_p, (*v)->y_p);
}

void	to_up(t_game **v)
{
	int		img_w;
	int		img_h;

	(*v)->img = mlx_xpm_file_to_image(
			(*v)->mlx_ptr, "./img/tile0.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*v)->mlx_ptr, (*v)->mlx_win, (*v)->img, (*v)->x_p, (*v)->y_p);
	if ((*v)->map[((*v)->y_p / 64) - 1][((*v)->x_p / 64)] == 'E')
	{
		if ((*v)->collectable <= 0)
			exit_door(&v);
	}
	else if ((*v)->map[((*v)->y_p / 64) - 1][((*v)->x_p / 64)] != '1')
	{
		(*v)->y_p -= 64;
		put_text(&v);
	}
	if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64)] == 'C')
		collected(&v);
	(*v)->img = mlx_xpm_file_to_image(
			(*v)->mlx_ptr, "./img/pg1.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*v)->mlx_ptr, (*v)->mlx_win, (*v)->img, (*v)->x_p, (*v)->y_p);
}

void	to_right(t_game **v)
{
	int		img_w;
	int		img_h;

	(*v)->img = mlx_xpm_file_to_image(
			(*v)->mlx_ptr, "./img/tile0.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*v)->mlx_ptr, (*v)->mlx_win, (*v)->img, (*v)->x_p, (*v)->y_p);
	if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64) + 1] == 'E')
	{
		if ((*v)->collectable <= 0)
			exit_door(&v);
	}
	else if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64) + 1] != '1')
	{
		(*v)->x_p += 64;
		put_text(&v);
	}
	if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64)] == 'C')
		collected(&v);
	(*v)->img = mlx_xpm_file_to_image(
			(*v)->mlx_ptr, "./img/pg1.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*v)->mlx_ptr, (*v)->mlx_win, (*v)->img, (*v)->x_p, (*v)->y_p);
}

void	collected(t_game ***v)
{
	int		img_w;
	int		img_h;

	(**v)->collectable--;
	(**v)->map[((**v)->y_p / 64)][((**v)->x_p / 64)] = '0';
	(**v)->img = mlx_xpm_file_to_image(
			(**v)->mlx_ptr, "./img/tile0.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(**v)->mlx_ptr, (**v)->mlx_win, (**v)->img, (**v)->x_p, (**v)->y_p);
}
