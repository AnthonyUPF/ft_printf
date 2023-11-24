/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:47:51 by anthtorr          #+#    #+#             */
/*   Updated: 2023/11/24 14:23:40 by anthtorr         ###   ########.fr       */
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
		count = (ft_putstr (va_arg(args, char *)));
	else if (*ptr == 'p')
	{
		if (ft_putstr("0x") == -1)
			return (-1);
		count = ft_puthex(va_arg(args, unsigned long), 0);
		count += 2;
	}
	else if (*ptr == 'i' || *ptr == 'd')
		count = (ft_putnbr (va_arg(args, int)));
	else if (*ptr == 'u')
		count = ft_putunbr(va_arg(args, unsigned int));
	else if (*ptr == 'x' || *ptr == 'X')
		count = ft_puthex(va_arg(args, unsigned int), (*ptr == 'X'));
	else if (*ptr == '%')
		count = ft_putchar('%');
	return (count);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		count;
	int		temp;

	va_start (args, str);
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
	va_end (args);
	return (count);
}
//
//#include <stdio.h>
//
//int main()
//{
//    int printf_chars, ft_printf_chars; 
//
//    // %c
//    char c = 'A';
//    ft_printf("Prueba de %%c:\n");
//    printf_chars = printf("printf: %c\n", c);
//    ft_printf_chars = ft_printf("ft_printf: %c\n", c);
//    ft_printf("printf chars: %d\n", printf_chars);
//    ft_printf("ft_printf chars: %d\n", ft_printf_chars - 3);
//
//    // %s
//    char *str = "Hello, world!";
//    ft_printf("\nPrueba de %%s:\n");
//    printf_chars = printf("printf: %s\n", str);
//    ft_printf_chars = ft_printf("ft_printf: %s\n", str);
//	ft_printf("printf chars: %d\n", printf_chars);
//    ft_printf("ft_printf chars: %d\n", ft_printf_chars - 3);
//
//
//    // %p
//    void *ptr = (void *)str;
//    ft_printf("\nPrueba de %%p:\n");
//    printf_chars = printf("printf: %p\n", ptr);
//    ft_printf_chars = ft_printf("ft_printf: %p\n", ptr);
//	ft_printf("printf chars: %d\n", printf_chars);
//    ft_printf("ft_printf chars: %d\n", ft_printf_chars - 3);
//
//    // %d
//    int num = -42;
//    ft_printf("\nPrueba de %%d:\n");
//    printf_chars = printf("printf: %d\n", num);
//    ft_printf_chars = ft_printf("ft_printf: %d\n", num);
//	ft_printf("printf chars: %d\n", printf_chars);
//    ft_printf("ft_printf chars: %d\n", ft_printf_chars - 3);
//
//    // %i
//    ft_printf("\nPrueba de %%i:\n");
//    printf_chars = printf("printf: %i\n", num);
//    ft_printf_chars = ft_printf("ft_printf: %i\n", num);
//	ft_printf("printf chars: %d\n", printf_chars);
//    ft_printf("ft_printf chars: %d\n", ft_printf_chars - 3);
//
//   // %u
//    unsigned int u_num = 4294967295;
//    ft_printf("\nPrueba de %%u:\n");
//    printf_chars = printf("printf: %u\n", u_num);
//    ft_printf_chars = ft_printf("ft_printf: %u\n", u_num);
//	ft_printf("printf chars: %d\n", printf_chars);
//    ft_printf("ft_printf chars: %d\n", ft_printf_chars - 3);
//
//    // %x
//    unsigned int hex_num = 155;
//    ft_printf("\nPrueba de %%x:\n");
//    printf_chars = printf("printf: %x\n", hex_num);
//    ft_printf_chars = ft_printf("ft_printf: %x\n", hex_num);
//	ft_printf("printf chars: %d\n", printf_chars);
//    ft_printf("ft_printf chars: %d\n", ft_printf_chars - 3);
//
//    // %X
//    ft_printf("\nPrueba de %%X:\n");
//    printf_chars = printf("printf: %X\n", hex_num);
//    ft_printf_chars = ft_printf("ft_printf: %X\n", hex_num);
//	ft_printf("printf chars: %d\n", printf_chars);
//    ft_printf("ft_printf chars: %d\n", ft_printf_chars - 3);
//
//    // %%
//    ft_printf("\nPrueba de %% (porcentaje):\n");
//    printf_chars = printf("printf: %%\n");
//    ft_printf_chars = ft_printf("ft_printf: %%\n");
//	ft_printf("printf chars: %d\n", printf_chars);
//    ft_printf("ft_printf chars: %d\n", ft_printf_chars - 3);
//
//    return 0;
//}
//
