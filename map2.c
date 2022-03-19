/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 19:31:46 by aabdou            #+#    #+#             */
/*   Updated: 2022/03/18 16:37:38 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

char **stor_map(char *map)
{
	int fd;
	int i;
	char *line;
	char *all_lines;
	char	**res;

	i = 0;
	line = "";
	all_lines = ft_strdup("");
	fd = open(map , O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error: invalid file descriptor\n", 31);
		exit (1);
	}
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break;
		all_lines = ft_strjoin2(all_lines, line);
		free(line);
		i++;
	}
	free(line);
	close(fd);
	if (all_lines[0] == '\0')
	{
		write(2, "Error: didnt read map\n", 22);
		exit(1);
	}	
	res = ft_split(all_lines, '\n');
	//free(all_lines);
	return (res);	
}

// void	fill_field(t_game *var, char *av, int fd, int i)
// {
// 	var->map = (char **)malloc(sizeof(char *) * (var->img_height + 1));
// 	if (!var->map)
// 		exit(EXIT_FAILURE);
// 	fd = open (av, O_RDONLY);
// 	while (i < var->img_height)
// 		var->map[i++] = get_next_line(fd);
// 	close (fd);
// 	i = 0;
// 	while (i < var->map[0][i])
// 		i++;
// 	var->img_width = i;
// 	var->map[var->img_height] = 0;
// }


int check_file_type(char *str, char *type)
{
	int i;

	i = 0;
	while(type[i])
	{
		if(type[i] != str[i])
			return (0);
	i++;
	}
	if (str[i] == '\0')
		return (1);
	return (0);
}

void check_file(char *str)
{
    int i;
    
    i = 0;
    while(str[i])
    {
        if(str[i] == '.')
        {	
			if (check_file_type(str + i , ".ber"))
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
