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

#include <stdarg.h>
#include "Libft/libft.h"

void	ft_puthex(unsigned long num, int uppercase)
{
	char	*hex_digits;
	char	hex_char;

	if (num == 0)
	{
		ft_putchar_fd('0', 1);
		return ;
	}
	if (num / 16 != 0)
		ft_puthex(num / 16, uppercase);
	hex_digits = "0123456789abcdef";
	hex_char = hex_digits[num % 16];
	if (uppercase)
		hex_char = ft_toupper(hex_char);
	ft_putchar_fd(hex_char, 1);
}

void	ft_putunbr(unsigned int num)
{
	if (num == 0)
	{
		ft_putchar_fd('0', 1);
		return ;
	}
	if (num / 10 != 0)
		ft_putunbr(num / 10);
	ft_putchar_fd((num % 10) + '0', 1);
}

void	ft_putfloat(double num)
{
	double			positive_num;
	unsigned int	integer_part;
	unsigned int	decimal_part;

	positive_num = num;
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		positive_num = -num;
	}
	integer_part = (unsigned int)positive_num;
	decimal_part = (unsigned int)((positive_num - integer_part) * 1000000);
	ft_putunbr(integer_part);
	ft_putchar_fd('.', 1);
	ft_putunbr(decimal_part);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	const char	*ptr;

	va_start(args, format);
	ptr = format;
	while (*ptr)
	{
		if (*ptr == '%')
		{
			ptr++;
			if (*ptr == 'c')
				ft_putchar_fd(va_arg(args, int), 1);
			else if (*ptr == 's')
				ft_putstr_fd(va_arg(args, const char *), 1);
			else if (*ptr == 'p')
			{
				ft_putstr_fd("0x", 1);
				ft_puthex(va_arg(args, unsigned long), 0);
			}
			else if (*ptr == 'd' || *ptr == 'i')
				ft_putnbr_fd(va_arg(args, int), 1);
			else if (*ptr == 'u')
				ft_putunbr(va_arg(args, unsigned int));
			else if (*ptr == 'x')
				ft_puthex(va_arg(args, unsigned int), 0);
			else if (*ptr == 'X')
				ft_puthex(va_arg(args, unsigned int), 1);
			else if (*ptr == 'f')
				ft_putfloat(va_arg(args, double));
			else if (*ptr == '%')
				ft_putchar_fd('%', 1);
		}
		else
		{
			ft_putchar_fd(*ptr, 1);
		}
		ptr++;
	}
	va_end(args);
	return (0);
}


#include <stdio.h>

int main()
{
    // %c
    char c = 'A';
    ft_printf("Prueba de %%c:\n");
    printf("printf: %c\n", c);
    ft_printf("ft_printf: %c\n", c);

    // %s
    char *str = "Hello, world!";
    ft_printf("\nPrueba de %%s:\n");
    printf("printf: %s\n", str);
    ft_printf("ft_printf: %s\n", str);

    // %p
    void *ptr = (void *)str;
    ft_printf("\nPrueba de %%p:\n");
    printf("printf: %p\n", ptr);
    ft_printf("ft_printf: %p\n", ptr);

    // %d
    int num = 42;
    ft_printf("\nPrueba de %%d:\n");
    printf("printf: %d\n", num);
    ft_printf("ft_printf: %d\n", num);

    // %i
    ft_printf("\nPrueba de %%i:\n");
    printf("printf: %i\n", num);
    ft_printf("ft_printf: %i\n", num);

    // %f
    double num_d = -42.5;
    ft_printf("\nPrueba de %%f:\n");
    printf("printf: %f\n", num_d);
    ft_printf("ft_printf: %f\n", num_d);

    // %u
    unsigned int u_num = 4294967295;
    ft_printf("\nPrueba de %%u:\n");
    printf("printf: %u\n", u_num);
    ft_printf("ft_printf: %u\n", u_num);

    // %x
    unsigned int hex_num = 155;
    ft_printf("\nPrueba de %%x:\n");
    printf("printf: %x\n", hex_num);
    ft_printf("ft_printf: %x\n", hex_num);

    // %X
    ft_printf("\nPrueba de %%X:\n");
    printf("printf: %X\n", hex_num);
    ft_printf("ft_printf: %X\n", hex_num);

    // %%
    ft_printf("\nPrueba de %% (porcentaje):\n");
    printf("printf: %%\n");
    ft_printf("ft_printf: %%\n");

    return 0;
}

