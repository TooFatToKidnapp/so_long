/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3_BONUS.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:35:36 by aabdou            #+#    #+#             */
/*   Updated: 2022/03/22 20:50:05 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_BONUS.h"

void	ft_free(t_game ***var, char *err)
{
	int	x;

	x = 0;
	while ((**var)->map[x])
	{
		free((**var)->map[x]);
		x++;
	}
	free((**var)->map);
	ft_putendl_fd(err, 2);
	exit(1);
}

void	check_walls(t_game **var)
{
	int	i;

	i = 0;
	while (i < (*var)->img_width)
	{
		if ((*var)->map[0][i] != '1' ||
			(*var)->map[(*var)->img_height - 1][i] != '1')
			ft_free(&var, "Error: wrong wall structure");
		i++;
	}
	i = 0;
	while (i < (*var)->img_height)
	{
		if ((*var)->map[i][0] != '1' ||
			(*var)->map[i][(*var)->img_width - 1] != '1')
			ft_free(&var, "Error wrong wall structure");
		i++;
	}
}

void	check_if_rectangular(t_game **var)
{
	int	tmp;
	int	i;

	i = 0;
	(*var)->img_height = get_height((*var)->map);
	(*var)->img_width = ft_strlen_nl(*(*var)->map);
	tmp = (*var)->img_height;
	while (tmp > 0)
	{
		if ((*var)->img_width != ft_strlen_nl((*var)->map[i]))
			ft_free(&var, "ERROR: MAP NOT RECTANGULAR");
		i++;
		tmp--;
	}
}
