/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:18:13 by aabdou            #+#    #+#             */
/*   Updated: 2022/03/18 22:31:10 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	animation(t_game *var)
{		
	if (var->collectable <= 0)
    {
		open_exit(&var);
    }
	return (0);
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
				mlx_put_image_to_window(
					(*var)->mlx_ptr, (*var)->mlx_win, (*var)->img, x * 64, y * 64);
			}
			x++;
		}
		y++;
	}
}
 