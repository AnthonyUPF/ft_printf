/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prinft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:33:07 by anthtorr          #+#    #+#             */
/*   Updated: 2023/11/20 21:56:22 by anthtorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digits(unsigned int num)
{
	int count;

	count = 1;
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

static void	handle_format(const char *ptr, va_list args, int *count)
{
	if (*ptr == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		(*count)++;
	}
	else if (*ptr == 's')
	{
		const char *str = va_arg(args, const char *);
		if (str)
		{
			ft_putstr_fd(str, 1);
			(*count) += ft_strlen(str);
		}
		else
		{
			ft_putstr_fd("(null)", 1);
			(*count) += 6;
		}
	}	
	else if (*ptr == 'p')
	{
		ft_putstr_fd("0x", 1);
		ft_puthex(va_arg(args, unsigned long), 0, count);
	}
	else if (*ptr == 'd' || *ptr == 'i')
	{
		int num = va_arg(args, int);
		ft_putnbr_fd(num, 1);
		(*count) += count_digits(num);
	}	
	else if (*ptr == 'u')
		ft_putunbr(va_arg(args, unsigned int), count);
	else if (*ptr == 'x' || *ptr == 'X')
		ft_puthex(va_arg(args, unsigned int), *ptr == 'X', count);
	else if (*ptr == 'f')
		ft_putfloat(va_arg(args, double), count);
	else if (*ptr == '%')
	{
		ft_putchar_fd('%', 1);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	const char	*ptr;
	int		count;

	va_start(args, format);
	ptr = format;
	count = 0;
	while (*ptr)
	{
		if (*ptr == '%')
		{
			ptr++;
			handle_format(ptr, args, &count);
		}
		else
		{
			ft_putchar_fd(*ptr, 1);
			count++;
		}
		ptr++;
	}
	va_end(args);
	return (count);
}

#include <stdio.h>

int main()
{
    int printf_chars, ft_printf_chars; 

    // %c
    char c = 'A';
    ft_printf("Prueba de %%c:\n");
    printf_chars = printf("printf: %c\n", c);
    ft_printf_chars = ft_printf("ft_printf: %c\n", c);
    printf("printf chars: %d, ft_printf chars: %d\n", printf_chars, ft_printf_chars);

    // %s
    char *str = "Hello, world!";
    ft_printf("\nPrueba de %%s:\n");
    printf_chars = printf("printf: %s\n", str);
    ft_printf_chars = ft_printf("ft_printf: %s\n", str);
    printf("printf chars: %d, ft_printf chars: %d\n", printf_chars, ft_printf_chars);

    // %p
    void *ptr = (void *)str;
    ft_printf("\nPrueba de %%p:\n");
    printf_chars = printf("printf: %p\n", ptr);
    ft_printf_chars = ft_printf("ft_printf: %p\n", ptr);
    printf("printf chars: %d, ft_printf chars: %d\n", printf_chars, ft_printf_chars);

    // %d
    int num = 42;
    ft_printf("\nPrueba de %%d:\n");
    printf_chars = printf("printf: %d\n", num);
    ft_printf_chars = ft_printf("ft_printf: %d\n", num);
    printf("printf chars: %d, ft_printf chars: %d\n", printf_chars, ft_printf_chars);

    // %i
    ft_printf("\nPrueba de %%i:\n");
    printf_chars = printf("printf: %i\n", num);
    ft_printf_chars = ft_printf("ft_printf: %i\n", num);
    printf("printf chars: %d, ft_printf chars: %d\n", printf_chars, ft_printf_chars);

    // %f
    double num_d = -42.5;
    ft_printf("\nPrueba de %%f:\n");
    printf_chars = printf("printf: %f\n", num_d);
    ft_printf_chars = ft_printf("ft_printf: %f\n", num_d);
    printf("printf chars: %d, ft_printf chars: %d\n", printf_chars, ft_printf_chars);

    // %u
    unsigned int u_num = 4294967295;
    ft_printf("\nPrueba de %%u:\n");
    printf_chars = printf("printf: %u\n", u_num);
    ft_printf_chars = ft_printf("ft_printf: %u\n", u_num);
    printf("printf chars: %d, ft_printf chars: %d\n", printf_chars, ft_printf_chars);

    // %x
    unsigned int hex_num = 155;
    ft_printf("\nPrueba de %%x:\n");
    printf_chars = printf("printf: %x\n", hex_num);
    ft_printf_chars = ft_printf("ft_printf: %x\n", hex_num);
    printf("printf chars: %d, ft_printf chars: %d\n", printf_chars, ft_printf_chars);

    // %X
    ft_printf("\nPrueba de %%X:\n");
    printf_chars = printf("printf: %X\n", hex_num);
    ft_printf_chars = ft_printf("ft_printf: %X\n", hex_num);
    printf("printf chars: %d, ft_printf chars: %d\n", printf_chars, ft_printf_chars);

    // %%
    ft_printf("\nPrueba de %% (porcentaje):\n");
    printf_chars = printf("printf: %%\n");
    ft_printf_chars = ft_printf("ft_printf: %%\n");
    printf("printf chars: %d, ft_printf chars: %d\n", printf_chars, ft_printf_chars);

    return 0;
}
