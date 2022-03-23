/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_BONUS.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:13:26 by aabdou            #+#    #+#             */
/*   Updated: 2022/03/23 17:38:36 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_BONUS.h"

int	animation(t_game *var)
{		
	if (get_position_for_enemy(&var) != 0)
	{	
		if (var->e_vars.sleep-- <= 0)
		{
			var->e_vars.x++;
			var->e_vars.sleep = 5;
		}
		if (var->e_vars.x == 3)
			var->e_vars.x = 0;
		is_over(var);
		if (var->e_vars.sleep_for_move-- <= 0)
		{	
			move_enemy(&var);
			var->e_vars.sleep_for_move = 30;
		}
		is_over(var);
		render_img(&var);
	}
	if (var->collectable <= 0)
		open_exit(&var);
	return (0);
}

void	init_var(t_game *var)
{
	var->collectable = 0;
	var->e_vars.sign = 1;
	var->e_vars.x = 0;
	var->e_vars.sleep = 5;
	var->e_vars.sleep_for_move = 60;
	var->e_vars.path_to_move = 0;
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
