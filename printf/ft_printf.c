/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 22:51:05 by aabdou            #+#    #+#             */
/*   Updated: 2021/12/27 13:59:24 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_fla(char arg, va_list ap)
{
	int	len;

	len = 0;
	if (arg == 'c')
		len += ft_putchar(va_arg(ap, int));
	else if (arg == '%')
		len += ft_putchar('%');
	else if (arg == 's')
		len += ft_putstr(va_arg(ap, char *));
	else if (arg == 'i' || arg == 'd')
		len += ft_putnbr(va_arg(ap, int));
	else if (arg == 'x' || arg == 'X')
		len += ft_puthex(va_arg(ap, unsigned int), arg);
	else if (arg == 'u')
		len += ft_putnbr_u(va_arg(ap, unsigned int));
	else if (arg == 'p')
		len += ft_pointer(va_arg(ap, unsigned long *));
	return (len);
}

int	ft_printf(const char *fp, ...)
{
	va_list	ap;
	int		i;
	int		len;

	va_start(ap, fp);
	i = 0;
	len = 0;
	while (fp[i])
	{
		if (fp[i] == '%')
		{
			i++;
			len += ft_check_fla(fp[i], ap);
		}
		else
			len += ft_putchar(fp[i]);
		i++;
	}
	va_end(ap);
	return (len);
}
