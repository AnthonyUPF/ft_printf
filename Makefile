# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 16:53:56 by anthtorr          #+#    #+#              #
#    Updated: 2023/11/24 13:44:30 by anthtorr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre del archivo de salida
NAME = libftprintf.a

# Lista de archivos fuente obligatorios
SRCS = ft_printf.c ft_putchar.c ft_putstr.c ft_puthex.c ft_putnbr.c ft_putunbr.c

# Genera una lista de objetos a partir de los archivos fuente
OBJS = $(SRCS:.c=.o)

# Opciones de compilación
CC = gcc
CFLAGS = -Wall -Werror -Wextra

# Regla para construir la biblioteca
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Regla por defecto
all: $(NAME)

# Regla para limpiar los archivos objeto
clean:
	rm -f $(OBJS)

# Regla para limpiar los archivos objeto y la biblioteca
fclean: clean
	rm -f $(NAME)

# Regla para recompilar todo desde cero
re:	fclean all

# Indica que "all", "clean", "fclean", "re" no son nombres de archivos
.PHONY: all clean fclean re
