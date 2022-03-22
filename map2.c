/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 19:31:46 by aabdou            #+#    #+#             */
/*   Updated: 2022/03/22 18:24:35 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

char	**stor_map(char *map)
{
	int		fd;
	char	*line;
	char	*all_lines;
	char	**res;

	line = "";
	all_lines = ft_strdup("");
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (write(2, "Error: invalid file descriptor\n", 31), exit(1), NULL);
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		all_lines = ft_strjoin2(all_lines, line);
		free(line);
	}
	free(line);
	close(fd);
	if (all_lines[0] == '\0')
		return (write(2, "Error: didnt read map\n", 22), exit(1), NULL);
	res = ft_split(all_lines, '\n');
	return (res);
}

int	check_file_type(char *str, char *type)
{
	int	i;

	i = 0;
	while (type[i])
	{
		if (type[i] != str[i])
			return (0);
	i++;
	}
	if (str[i] == '\0')
		return (1);
	return (0);
}

void	check_file(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{	
			if (check_file_type(str + i, ".ber"))
				return ;
		}
		i++;
	}
	write(2, "ERROR: invalid file type\n", 26);
	exit(1);
}

int	get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

int	ft_strlen_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}
