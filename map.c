/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:16:14 by aabdou            #+#    #+#             */
/*   Updated: 2022/03/22 18:29:57 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_content(t_game *var)
{
	int	j;
	int	i;
	int	e;

	e = var->img_height;
	i = 0;
	j = 0;
	while (i < var->img_width)
	{
		while (j < var->img_height)
		{
			if (map_content(var, var->map[j][i]))
				i++;
			if (var->map[j][i] == '\0' && e > 0)
			{
				e--;
				i = 0;
				break ;
			}
		}	
		j++;
		if (e == 0)
			break ;
	}
	error(var);
}

int	map_content(t_game *var, char c)
{	
	if (c != 'E' && c != '0' && c != '1' && c != 'P' && c != 'C')
	{
		write(2, "Error\nunknown character\n", 24);
		exit(1);
	}
	else if (c == 'C')
		var->collectable++;
	else if (c == 'P')
		var->player++;
	else if (c == 'E')
		var->exit++;
	return (1);
}

void	error(t_game *var)
{	
	if (var->collectable == 0)
	{
		write(2, "Error\nmissing collectable\n", 26);
		exit(1);
	}
	else if (var->player == 0)
	{
		write(2, "Error\nmissing player\n", 21);
		exit(1);
	}
	else if (var->exit == 0)
	{
		write(2, "Error\nmissing exit\n", 19);
		exit(1);
	}
}

void	check_map(t_game *var)
{
	check_if_rectangular(&var);
	check_walls(&var);
	check_content(var);
}
