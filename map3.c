/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:35:36 by aabdou            #+#    #+#             */
/*   Updated: 2022/03/16 19:59:50 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void ft_free(t_game ***var, char *err)
{
	int x;

	x = 0;
	while((**var)->map[x])
	{
		free((**var)->map[x]);
		x++;
	}
	free((**var)->map);
	ft_putendl_fd(err, 2);
	exit(1);
}

void	check_walls(t_game **var) //check if walls are all one's
{
	int	i;

	i = 0;
	while (i < (*var)->img_width)
	{
		if((*var)->map[0][i] != '1' || (*var)->map[(*var)->img_height - 1][i] != '1')
		{
			ft_free(&var, "Error: wrong wall structure");
			// write(2,"Error\nwrong wall structure\n",27);
			// exit(1);
		}
		i++;
	}
	i = 0;
	while (i < (*var)->img_height)
	{
		if((*var)->map[i][0] != '1' || (*var)->map[i][(*var)->img_width - 1] != '1')
		{
			ft_free(&var, "Error wrong wall structure");
			// write(2,"Error\nwrong wall structure\n",27);
			// exit(1);
		}
		i++;
	}

}

void check_if_rectangular(t_game **var)
{
	int tmp;
	int i;

	i = 0;
	(*var)->img_height= get_height((*var)->map);
	(*var)->img_width = ft_strlen_nl(*(*var)->map);

	tmp = (*var)->img_height;
	while(tmp > 0)
	{
		if((*var)->img_width != ft_strlen_nl((*var)->map[i]))
		{
			ft_free(&var, "ERROR: MAP NOT RECTANGULAR");
			// write(2, "ERROR: MAP NOT RECTANGULAR\n", 28);
			// exit (1);
		}
		i++;
		tmp--;
	}
}
