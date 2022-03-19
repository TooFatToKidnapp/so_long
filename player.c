/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:17:48 by aabdou            #+#    #+#             */
/*   Updated: 2022/03/18 19:44:43 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_game *vars)
{
	int	x;
	if (keycode == 2 || keycode == 124)
		to_right(&vars);
	else if (keycode == 0 || keycode == 123)
		to_left(&vars);
	else if (keycode == 13 || keycode == 126)
		to_up(&vars);
	else if (keycode == 1 || keycode == 125)
		to_down(&vars);
	else if (keycode == 53)
	{
		x = 0;
		while (vars->map[x])
		{
			free(vars->map[x]);
			x++;
		}
		free(vars->map);
		ft_printf("END\n");
		mlx_destroy_window(vars->mlx_ptr, vars->mlx_win);
		exit(1);
	}
	return (0);
}

int	quit(t_game *v)
{
	int	x;

	x = 0;
	while (v->map[x])
	{
		free(v->map[x]);
		x++;
	}
	free(v->map);
	ft_printf("END\n");
	mlx_destroy_window(v->mlx_ptr, v->mlx_win);
	exit(1);
	return (0);
}


void	exit_door(t_game ***v)
{
	int	x;

	x = 0;
	while ((**v)->map[x])
	{
		free((**v)->map[x]);
		x++;
	}
	free((**v)->map);
	ft_printf("\033[1;32m== Success!! ==\033[0m\n");
	ft_printf("END\n");
	mlx_destroy_window((**v)->mlx_ptr, (**v)->mlx_win);
	exit(1);
}

void	put_text(t_game ***v)
{
	int		img_w;
	int		img_h;
	char	*text;
	char	*number;
	static int 	i;
	
	i = 0;
	number = ft_itoa(++(**v)->moves);
	text = ft_strjoin("Move:", number);
	(**v)->img = mlx_xpm_file_to_image(
			(**v)->mlx_ptr, "./img/tile1.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(**v)->mlx_ptr, (**v)->mlx_win, (**v)->img, 0, 0);
	mlx_put_image_to_window(
		(**v)->mlx_ptr, (**v)->mlx_win, (**v)->img, 64, 0);
	mlx_put_image_to_window(
		(**v)->mlx_ptr, (**v)->mlx_win, (**v)->img, 64 * 2, 0);
	mlx_string_put((**v)->mlx_ptr, (**v)->mlx_win, 10, 0, 0x180036, text);
	ft_printf("STEPS :%s\n", number);
	free(text);
	free(number);
}

