/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:17:48 by aabdou            #+#    #+#             */
/*   Updated: 2022/03/23 20:32:07 by aabdou           ###   ########.fr       */
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
	mlx_destroy_window((**v)->mlx_ptr, (**v)->mlx_win);
	exit(1);
}

void	put_text(t_game ***v)
{
	char	*number;

	number = ft_itoa(++(**v)->moves);
	ft_printf("STEPS :%s\n", number);
	free(number);
}
