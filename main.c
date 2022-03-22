/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:58:18 by aabdou            #+#    #+#             */
/*   Updated: 2022/03/22 18:30:46 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		mlx_loop_hook(var.mlx_ptr, animation, &var);
		mlx_loop(var.mlx_ptr);
	}
}
