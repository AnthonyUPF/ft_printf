#include "ft_printf.h"
#include <stdio.h>

int main()
{
    int printf_chars, ft_printf_chars;  // Variables para almacenar la cantidad de caracteres impresos

    // %c
    char c = 'A';
    ft_printf("Prueba de %%c:\n");
    printf_chars = printf("printf: %c\n", c);
    ft_printf_chars = ft_printf("ft_printf: %c\n", c);
    printf("printf chars: %d, ft_printf chars: %d\n", printf_chars, ft_printf_chars - 3);

    // %s
    char *str = "Hello, world!";
    ft_printf("\nPrueba de %%s:\n");
    printf_chars = printf("printf: %s\n", str);
    ft_printf_chars = ft_printf("ft_printf: %s\n", str);
    printf("printf chars: %d, ft_printf chars: %d\n", printf_chars, ft_printf_chars - 3);

    // %p
    void *ptr = (void *)str;
    ft_printf("\nPrueba de %%p:\n");
    printf_chars = printf("printf: %p\n", ptr);
    ft_printf_chars = ft_printf("ft_printf: %p\n", ptr);
    printf("printf chars: %d, ft_printf chars: %d\n", printf_chars, ft_printf_chars - 3);

    // %d
    int num = -42;
    ft_printf("\nPrueba de %%d:\n");
    printf_chars = printf("printf: %d\n", num);
    ft_printf_chars = ft_printf("ft_printf: %d\n", num);
    printf("printf chars: %d, ft_printf chars: %d\n", printf_chars, ft_printf_chars - 3);

    // %i
    ft_printf("\nPrueba de %%i:\n");
    printf_chars = printf("printf: %i\n", num);
    ft_printf_chars = ft_printf("ft_printf: %i\n", num);
    printf("printf chars: %d, ft_printf chars: %d\n", printf_chars, ft_printf_chars - 3);

    // %f
    double num_d = -42.5;
    ft_printf("\nPrueba de %%f:\n");
    printf_chars = printf("printf: %f\n", num_d);
    ft_printf_chars = ft_printf("ft_printf: %f\n", num_d);
    printf("printf chars: %d, ft_printf chars: %d\n", printf_chars, ft_printf_chars - 3);

    // %u
    unsigned int u_num = 4294967295;
    ft_printf("\nPrueba de %%u:\n");
    printf_chars = printf("printf: %u\n", u_num);
    ft_printf_chars = ft_printf("ft_printf: %u\n", u_num);
    printf("printf chars: %d, ft_printf chars: %d\n", printf_chars, ft_printf_chars - 3);

    // %x
    unsigned int hex_num = 155;
    ft_printf("\nPrueba de %%x:\n");
    printf_chars = printf("printf: %x\n", hex_num);
    ft_printf_chars = ft_printf("ft_printf: %x\n", hex_num);
    printf("printf chars: %d, ft_printf chars: %d\n", printf_chars, ft_printf_chars - 3);

    // %X
    ft_printf("\nPrueba de %%X:\n");
    printf_chars = printf("printf: %X\n", hex_num);
    ft_printf_chars = ft_printf("ft_printf: %X\n", hex_num);
    printf("printf chars: %d, ft_printf chars: %d\n", printf_chars, ft_printf_chars - 3);

    // %%
    ft_printf("\nPrueba de %% (porcentaje):\n");
    printf_chars = printf("printf: %%\n");
    ft_printf_chars = ft_printf("ft_printf: %%\n");
    printf("printf chars: %d, ft_printf chars: %d\n", printf_chars, ft_printf_chars - 3);

    return 0;
}
