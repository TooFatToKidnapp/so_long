/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 07:52:23 by aabdou            #+#    #+#             */
/*   Updated: 2021/12/27 07:52:24 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char arg)
{
	long	nb;
	int		len;

	len = 0;
	nb = n;
	if (nb < 0)
	{
		len += ft_putchar('-');
		nb *= -1;
	}
	if (nb < 16)
	{
		if (nb <= 9)
			len += ft_putchar(nb + 48);
		else if (nb >= 10 && arg == 'X')
			len += ft_putchar((nb % 10) + 'A');
		else if (nb >= 10 && arg == 'x')
			len += ft_putchar((nb % 10) + 'a');
	}
	else
	{
		len += ft_puthex(nb / 16, arg);
		len += ft_puthex(nb % 16, arg);
	}
	return (len);
}

int	ft_putp(unsigned long long nb)
{
	int	len;

	len = 0;
	if (nb < 16)
	{
		if (nb <= 9)
			len += ft_putchar(nb + '0');
		else if (nb >= 10)
			len += ft_putchar((nb % 10) + 'a');
	}
	else
	{
		len += ft_putp(nb / 16);
		len += ft_putp(nb % 16);
	}
	return (len);
}

int	ft_pointer(unsigned long *ptr)
{
	unsigned long	a;
	int				len;

	len = 0;
	a = (unsigned long)ptr;
	len += ft_putstr("0x");
	len += ft_putp(a);
	return (len);
}
