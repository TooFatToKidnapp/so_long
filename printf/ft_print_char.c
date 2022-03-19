/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 07:52:03 by aabdou            #+#    #+#             */
/*   Updated: 2021/12/27 13:56:49 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{	
		while (str[i])
		{
			len += write(1, &str[i], 1);
			i++;
		}
	}	
	return (len);
}
