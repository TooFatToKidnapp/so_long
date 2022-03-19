/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:01:33 by aabdou            #+#    #+#             */
/*   Updated: 2022/03/16 18:22:29 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

size_t	ft_strlen2(char *str);
char	*ft_strchr2(char *s, int c);
char	*ft_strjoin2(char *s1, char *s2);
char	*get_next_line(int fd);
char	*get_line(char *save);
char	*save_char(char *save);
char	*read_and_save(int fd, char *save);

#endif
