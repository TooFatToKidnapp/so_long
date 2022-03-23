/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_BONUS.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:58:18 by aabdou            #+#    #+#             */
/*   Updated: 2022/03/23 17:33:01 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_BONUS.h"

void	is_over(t_game *var)
{
	if ((var->e_vars.y_e == var->y_p / 64)
		&& (var->e_vars.x_e == var->x_p / 64))
		ft_lose(&var, "\033[1;31m== FAIL!! ==\033[0m\n");
}

int	main(int ac, char **av)
{
	t_game	var;

	if (ac != 2)
	{
		write(2, "ERROR : wrong use of executable\n", 32);
		exit(1);
	}
	check_file(av[1]);
	init_var(&var);
	var.map = stor_map(av[1]);
	if (var.map != NULL)
	{
		check_map(&var);
		var.mlx_ptr = mlx_init();
		var.mlx_win = mlx_new_window(var.mlx_ptr, var.img_width * 64,
				var.img_height * 64, "So_Long");
		render_map(&var);
		ft_printf("\033[1;33m== Start Game ==\033[0m\n");
		mlx_hook(var.mlx_win, 2, 0, key_hook, &var);
		mlx_hook(var.mlx_win, 17, 0, quit, &var);
		mlx_string_put(var.mlx_ptr, var.mlx_win, 10, 0, 0x180036, "Move:0");
		mlx_loop_hook(var.mlx_ptr, animation, &var);
		mlx_loop(var.mlx_ptr);
	}
}
