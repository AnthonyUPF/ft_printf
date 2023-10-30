/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prinft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:33:07 by anthtorr          #+#    #+#             */
/*   Updated: 2023/10/30 14:52:06 by anthtorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
/*
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_putnbr(int num)
{
	if (num == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
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

void	ft_putunbr(unsigned int num)
{
	unsigned int	temp;
	int				count;
	char			*digitos;
	int				indice;

	if (num == 0)
	{
		ft_putchar('0');
		return ;
	}
	temp = num;
	count = 0;
	while (temp > 0)
	{
		temp /= 10;
		count++;
	}
	digitos = (char *)malloc((count + 1) * sizeof(char));
	if (digitos == NULL)
	{
		return ;
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

void	ft_puthex(unsigned long long int num, char hex_base)
{
	int						count;
	unsigned long long int	temp;
	char					*digitos;
	int						indice;
	int						digit;

	count = 0;
	temp = num;
	if (temp == 0)
	{
		ft_putchar('0');
		return ;
	}
	while (temp > 0)
	{
		temp /= 16;
		count++;
	}
	digitos = (char *)malloc((count + 1) * sizeof(char));
	if (digitos == NULL)
	{
		return ;
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
*/

void	ft_putfloat(double num)
{
	int negativo;
    unsigned long long int parte_entera = (unsigned long long int)num;
	
    double parte_decimal = num - parte_entera;
	
    int *digitos_decimales = (int *)malloc(6 * sizeof(int));
	
    int i = 0;
	
    int j = 0;
	
	negativo = 0;
    if (num < 0)
    {
        negativo = 1;
        num = -num;
    }

    // Parte entera
    unsigned long long int parte_entera = (unsigned long long int)num;
    ft_putunbr(parte_entera);

    // Parte decimal
    ft_putchar('.');
    double parte_decimal = num - parte_entera;

    // Reservar memoria para almacenar los dígitos decimales
    int *digitos_decimales = (int *)malloc(6 * sizeof(int));

    if (digitos_decimales == NULL)
    {
        // Error de asignación de memoria
        return;
    }

    // Calcular los dígitos decimales
    int i = 0;
    while (i < 6)
    {
        parte_decimal *= 10;
        digitos_decimales[i] = (int)parte_decimal;
        parte_decimal -= digitos_decimales[i];
        i++;
    }

    // Imprimir los dígitos decimales
    int j = 0;
    while (j < 6)
    {
        ft_putchar(digitos_decimales[j] + '0');
        j++;
    }

    // Liberar la memoria asignada
    free(digitos_decimales);

    // Restaurar el signo si el número era negativo
    if (negativo)
    {
        ft_putchar('-');
    }
}

/*
int ft_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0;
    const char *ptr = format;

    while (*ptr)
    {
        if (*ptr == '%')
        {
            ptr++;
            if (*ptr == 'c')
            {
                char c = va_arg(args, int);
                ft_putchar(c);
                count++;
            }
            else if (*ptr == 's')
            {
                const char *str = va_arg(args, const char *);
                while (*str)
                {
                    ft_putchar(*str);
                    str++;
                    count++;
                }
            }
            else if (*ptr == 'p')
			{
				void *ptr_arg = va_arg(args, void *);
				unsigned long long int val = (unsigned long long int)ptr_arg;
				ft_putstr("0x");
				if (val >> 32)
					ft_puthex(val >> 32, 'a');
				ft_puthex(val & 0xFFFFFFFF, 'a'); 
				count += 18;
			}
            else if (*ptr == 'd' || *ptr == 'i')
            {
                int num = va_arg(args, int);
                ft_putnbr(num);
                count++;
            }
            else if (*ptr == 'u')
            {
                unsigned int num = va_arg(args, unsigned int);
                ft_putunbr(num);
                count++;
            }
            else if (*ptr == 'x' || *ptr == 'X')
            {
                unsigned int num = va_arg(args, unsigned int);
                char hex_base;
                if (*((char *)ptr) == 'x')
                    hex_base = 'a';
                else
                    hex_base = 'A';
                ft_puthex(num, hex_base);
                count++;
            }
			else if (*ptr == 'f')
            {
                double num = va_arg(args, double);
                ft_putfloat(num);
                count++;
            }
            else if (*ptr == '%')
            {
                ft_putchar('%');
                count++;
            }
            else
            {
                ft_putchar('%');
                count++;
                ft_putchar(*ptr);
                count++;
            }
        }
        else
        {
            ft_putchar(*ptr);
            count++;
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
*/
