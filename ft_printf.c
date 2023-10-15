/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prinft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:33:07 by anthtorr          #+#    #+#             */
/*   Updated: 2023/10/15 16:14:00 by anthtorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int ft_putchar(char c) {
    return write(1, &c, 1);
}

int ft_putstr(char *str) {
    int len = 0;
    while (str[len])
        len++;
    return write(1, str, len);
}

int ft_putnbr(int n) {
    if (n == -2147483648)
        return write(1, "-2147483648", 11);

    if (n < 0) {
        ft_putchar('-');
        n = -n;
    }

    if (n >= 10)
        ft_putnbr(n / 10);

    return ft_putchar(n % 10 + '0');
}

void ft_puthex(unsigned int n, int uppercase) {
    char base = (uppercase) ? 'A' : 'a';
    if (n >= 16)
        ft_puthex(n / 16, uppercase);

    char digit = (n % 16 > 9) ? n % 16 + base - 10 : n % 16 + '0';
    write(1, &digit, 1);
}

int ft_printf(const char *format, ...) {
    va_list args;
    int count = 0;
    const char *ptr = format;

    va_start(args, format);

    while (*ptr) {
        if (*ptr == '%') {
            ptr++;
            if (*ptr == 'c') {
                count += ft_putchar(va_arg(args, int));
            } else if (*ptr == 's') {
                count += ft_putstr(va_arg(args, char *));
            } else if (*ptr == 'p') {
                count += write(1, "0x", 2);
                ft_puthex((unsigned int)va_arg(args, void *), 1);
                count += 8; // Longitud de "0x" + 8 caracteres hexadecimales
            } else if (*ptr == 'd' || *ptr == 'i') {
                count += ft_putnbr(va_arg(args, int));
            } else if (*ptr == 'u') {
                count += ft_putnbr(va_arg(args, unsigned int));
            } else if (*ptr == 'x' || *ptr == 'X') {
                ft_puthex(va_arg(args, unsigned int), (*ptr == 'X') ? 1 : 0);
                count += 8; // Longitud de 8 caracteres hexadecimales
            } else if (*ptr == 'f') {
                // Manejo de %f (números de punto flotante)
                double num_f = va_arg(args, double);
                int int_part = (int)num_f;
                count += ft_putnbr(int_part);
                ft_putchar('.');
                // Extraemos hasta 6 decimales (como máximo)
                double decimal_part = num_f - int_part;
                for (int i = 0; i < 6; i++) {
                    decimal_part *= 10;
                    int digit = (int)decimal_part;
                    count += ft_putnbr(digit);
                    decimal_part -= digit;
                }
            } else if (*ptr == '%') {
                count += ft_putchar('%');
            }
        } else {
            count += ft_putchar(*ptr);
        }
        ptr++;
    }

    va_end(args);

    return count;
}

#include <stdio.h>

int main() {
    // %c
    char c = 'A';
    printf("Prueba de %%c:\n");
    printf("printf: %c\n", c);
    ft_printf("ft_printf: %c\n", c);

    // %s
    char *str = "Hello, world!";
    printf("\nPrueba de %%s:\n");
    printf("printf: %s\n", str);
    ft_printf("ft_printf: %s\n", str);

    // %p
    void *ptr = (void*)str;
    printf("\nPrueba de %%p:\n");
    printf("printf: %p\n", ptr);
    ft_printf("ft_printf: %p\n", ptr);

    // %d
    int num = 42;
    printf("\nPrueba de %%d:\n");
    printf("printf: %d\n", num);
    ft_printf("ft_printf: %d\n", num);

    // %i
    printf("\nPrueba de %%i:\n");
    printf("printf: %i\n", num);
    ft_printf("ft_printf: %i\n", num);

    // %f (nuevo caso)
    double num_d = 42.5;
    printf("\nPrueba de %%f:\n");
    printf("printf: %f\n", num_d);
    ft_printf("ft_printf: %f\n", num_d);

    // %u
    unsigned int u_num = 4294967295;
    printf("\nPrueba de %%u:\n");
    printf("printf: %u\n", u_num);
    ft_printf("ft_printf: %u\n", u_num);

    // %x
    unsigned int hex_num = 255;
    printf("\nPrueba de %%x:\n");
    printf("printf: %x\n", hex_num);
    ft_printf("ft_printf: %x\n", hex_num);

    // %X
    printf("\nPrueba de %%X:\n");
    printf("printf: %X\n", hex_num);
    ft_printf("ft_printf: %X\n", hex_num);

    // %%
    printf("\nPrueba de %% (porcentaje):\n");
    printf("printf: %%\n");
    ft_printf("ft_printf: %%\n");

    return 0;
}

