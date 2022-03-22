/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:13:26 by aabdou            #+#    #+#             */
/*   Updated: 2022/03/22 18:33:49 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	animation(t_game *var)
{		
	if (var->collectable <= 0)
		open_exit(&var);
	return (0);
}

void	init_var(t_game *var)
{
	var->count = 0;
	var->collectable = 0;
	var->player = 0;
	var->exit = 0;
}

void	open_exit(t_game **var)
{
	int			y;
	int			x;
	int			height;
	int			img_w;
	int			img_h;

	y = 0;
	height = get_height((*var)->map);
	while (y != height)
	{
		x = 0;
		while ((*var)->map[y][x] != '\0')
		{
			if ((*var)->map[y][x] == 'E')
			{
				(*var)->img = mlx_xpm_file_to_image(
						(*var)->mlx_ptr, "./img/exit.xpm", &img_w, &img_h);
				mlx_put_image_to_window((*var)->mlx_ptr,
					(*var)->mlx_win, (*var)->img, x * 64, y * 64);
			}
			x++;
		}
		y++;
	}
}
