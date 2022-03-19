/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 07:52:15 by aabdou            #+#    #+#             */
/*   Updated: 2021/12/27 07:52:16 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int n)
{
	unsigned long	nb;
	int				len;

	len = 0;
	nb = n;
	if (nb <= 9)
		len += ft_putchar(nb + '0');
	else
	{
		len += ft_putnbr_u(nb / 10);
		len += ft_putnbr_u(nb % 10);
	}
	return (len);
}

int	ft_putnbr(int n)
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
	if (nb <= 9)
		len += ft_putchar(nb + '0');
	else
	{
		len += ft_putnbr(nb / 10);
		len += ft_putnbr(nb % 10);
	}
	return (len);
}
