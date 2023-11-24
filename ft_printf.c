/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:47:51 by anthtorr          #+#    #+#             */
/*   Updated: 2023/11/23 17:05:00 by anthtorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_format(const char *ptr, va_list args)
{
	int	count;

	count = 0;
	if (*ptr == 'c')
		count = ft_putchar (va_arg(args, int));
	else if (*ptr == 's')
		count = ft_putstr (va_arg(args, char *));
	else if (*ptr == 'i' || *ptr == 'd')
		count = ft_putnbr (va_arg(args, int));
	else if (*ptr == 'u')
		count = ft_putunbr(va_arg(args, unsigned int));
	else if (*ptr == 'p' || *ptr == 'x' || *ptr == 'X')
	{
		if (*ptr == 'p')
		{
			if (ft_putstr("0x") == -1)
				return (-1);
		}
		count = ft_puthex(va_arg(args, unsigned long), (*ptr == 'X'));
		if (*ptr == 'p' && count != -1)
			count += 2;
	}
	else if (*ptr == '%')
		count = ft_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		temp;

	va_start(args, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			temp = handle_format(++str, args);
			if (temp == -1)
				return (-1);
			count += temp;
		}
		else
		{
			if (ft_putchar(*str) == -1)
				return (-1);
			count++;
		}
		str++;
	}
	va_end(args);
	return (count);
}
