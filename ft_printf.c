/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prinft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:33:07 by anthtorr          #+#    #+#             */
/*   Updated: 2023/11/17 11:43:22 by anthtorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(const char *str)
{
    while (*str)
    {
        ft_putchar(*str);
        str++;
    }
}

void ft_puthex(unsigned long long int num, char hex_base)
{
    unsigned long long int temp;
    char *digitos;
    int indice;
    int digit;

    temp = num;
    if (temp == 0)
    {
        ft_putchar('0');
        return;
    }
    int count = 0;
    while (temp > 0)
    {
        temp /= 16;
        count++;
    }
    digitos = (char *)malloc((count + 1) * sizeof(char));
    if (digitos == NULL)
    {
        return;
    }
    indice = count;
    while (num > 0)
    {
        digit = num % 16;
        if (digit < 10)
            digitos[indice - 1] = digit + '0';
        else
            digitos[indice - 1] = digit - 10 + hex_base;
        num /= 16;
        indice--;
    }
    digitos[count] = '\0';
    ft_putstr(digitos);
    free(digitos);
}

void ft_putnbr(int num)
{
    if (num == -2147483648)
    {
        ft_putstr("-2147483648");
        return;
    }
    if (num < 0)
    {
        ft_putchar('-');
        num = -num;
    }
    if (num >= 10)
    {
        ft_putnbr(num / 10);
    }
    ft_putchar(num % 10 + '0');
}

void ft_putunbr(unsigned int num)
{
    unsigned int temp;
    char *digitos;
    int indice;

    if (num == 0)
    {
        ft_putchar('0');
        return;
    }
    temp = num;
    int count = 0;
    while (temp > 0)
    {
        temp /= 10;
        count++;
    }
    digitos = (char *)malloc((count + 1) * sizeof(char));
    if (digitos == NULL)
    {
        return;
    }
    indice = count;
    while (num > 0)
    {
        digitos[indice - 1] = num % 10 + '0';
        num /= 10;
        indice--;
    }
    digitos[count] = '\0';
    ft_putstr(digitos);
    free(digitos);
}

void ft_putfloat(double num)
{
    int negativo;
    unsigned long long int parte_entera;
    double parte_decimal;
    int *digitos_decimales;
    int i;

    negativo = 0;
    if (num < 0)
    {
        negativo = 1;
        num = -num;
    }
    parte_entera = (unsigned long long int)num;
    ft_putunbr(parte_entera);
    ft_putchar('.');
    parte_decimal = num - parte_entera;
    digitos_decimales = (int *)malloc(6 * sizeof(int));
    if (digitos_decimales == NULL)
    {
        return;
    }
    i = 0;
    while (i < 6)
    {
        parte_decimal *= 10;
        digitos_decimales[i] = (int)parte_decimal;
        parte_decimal -= digitos_decimales[i];
        i++;
    }
    i = 0;
    while (i < 6)
    {
        ft_putchar(digitos_decimales[i] + '0');
        i++;
    }
    free(digitos_decimales);
    if (negativo)
    {
        ft_putchar('-');
    }
}

int ft_printf(char const *format, ...)
{
    va_list args;
    const char *ptr;
    unsigned long long int val;

    va_start(args, format);
    ptr = format;
    while (*ptr)
    {
        if (*ptr == '%')
        {
            ptr++;
            if (*ptr == 'c')
                ft_putchar(va_arg(args, int));
            else if (*ptr == 's')
                ft_putstr(va_arg(args, const char *));
            else if (*ptr == 'p')
            {
                val = (unsigned long long int)va_arg(args, void *);
                ft_putstr("0x");
                ft_puthex(val, 'a'); // Simplificado aquí
            }
            else if (*ptr == 'd' || *ptr == 'i')
            {
                ft_putnbr(va_arg(args, int));
            }
            else if (*ptr == 'u')
            {
                ft_putunbr(va_arg(args, unsigned int));
            }
            else if (*ptr == 'x' || *ptr == 'X')
            {
                ft_puthex(va_arg(args, unsigned int), (*ptr == 'x') ? 'a' : 'A');
            }
            else if (*ptr == 'f')
            {
                ft_putfloat(va_arg(args, double));
            }
            else if (*ptr == '%')
            {
                ft_putchar('%');
            }
        }
        else
        {
            ft_putchar(*ptr);
        }
        ptr++;
    }
    va_end(args);
    return 0;
}


#include <stdio.h>

int main() {
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
    void *ptr = (void*)str;
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

    // %f (nuevo caso)
    double num_d = 42.5;
    ft_printf("\nPrueba de %%f:\n");
    printf("printf: %f\n", num_d);
    ft_printf("ft_printf: %f\n", num_d);

    // %u
    unsigned int u_num = 4294967295;
    ft_printf("\nPrueba de %%u:\n");
    printf("printf: %u\n", u_num);
    ft_printf("ft_printf: %u\n", u_num);

    // %x
    unsigned int hex_num = 255;
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

