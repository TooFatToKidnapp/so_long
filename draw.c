/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:18:36 by aabdou            #+#    #+#             */
/*   Updated: 2022/03/21 23:32:58 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_game *vars)
{
	int	y1;
	int	y_map;
	int	backup_w;
	int	x1;
	int	x_map;

	y1 = 0;
	y_map = 0;
	backup_w = vars->img_width;
	while (vars->img_height > 0)
	{
		x1 = 0;
		x_map = 0;
		while (vars->img_width > 0)
		{
			put_image_to_map(vars->map[y_map][x_map], x1, y1, &vars);
			x_map++;
			x1 += 64;
			vars->img_width--;
		}
		vars->img_width = backup_w;
		y_map++;
		y1 += 64;
		vars->img_height--;
	}
}

void	put_image_to_map(char p, int x1, int y1, t_game **v)
{
	if (p == '1')
		put_image(&v, x1, y1, "./img/tile1.xpm");
	else if (p == 'C')
	{
		put_image(&v, x1, y1, "./img/tile0.xpm");
		put_image(&v, x1, y1, "./img/fishL.xpm");
	}
	else if (p == 'E')
		put_image(&v, x1, y1, "./img/end.xpm");
	else if (p == 'P')
	{
		(*v)->y_p = y1;
		(*v)->x_p = x1;
		put_image(&v, x1, y1, "./img/tile0.xpm");
		put_image(&v, x1, y1, "./img/pg1.xpm");
	}
	else
		put_image(&v, x1, y1, "./img/tile0.xpm");
}

void	put_image(t_game ***v, int x, int y, char *img)
{
	int		img_w;
	int		img_h;

	(**v)->img = mlx_xpm_file_to_image((**v)->mlx_ptr, img, &img_w, &img_h);
	mlx_put_image_to_window((**v)->mlx_ptr, (**v)->mlx_win, (**v)->img, x, y);
}
