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

static void	handle_format(const char *ptr, va_list args)
{
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
	else if (*ptr == 'x' || *ptr == 'X')
		ft_puthex(va_arg(args, unsigned int), *ptr == 'X');
	else if (*ptr == 'f')
		ft_putfloat(va_arg(args, double));
	else if (*ptr == '%')
		ft_putchar_fd('%', 1);
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
			handle_format(ptr, args);
		}
		else
			ft_putchar_fd(*ptr, 1);
		ptr++;
	}
	va_end(args);
	return (0);
}
/*
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
*/
