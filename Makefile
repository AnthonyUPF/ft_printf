# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 14:58:01 by anthtorr          #+#    #+#              #
#    Updated: 2023/10/11 15:01:35 by anthtorr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre de programa
NAME = libftprintf.a

# Fuentes de tu proyecto
SRCS = ft_printf.c \
       conv_c.c conv_s.c conv_p.c conv_d.c conv_u.c conv_x.c conv_percent.c

# Archivos objetos generados a partir de los fuentes
OBJS = $(SRCS:.c=.o)

# Opciones de compilación
CC = gcc
CFLAGS = -Wall -Werror -Wextra

# Directorios donde se encuentran los archivos de encabezado
INCLUDES = -I includes -I libft/includes

# Librerías necesarias
LIBFT = libft.a
LIBFT_PATH = libft

# Regla por defecto
all: libft $(NAME)

# Compila la librería
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Compila los objetos a partir de los fuentes
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Regla para compilar la librería libft
libft:
	$(MAKE) -C $(LIBFT_PATH)

# Limpia los archivos objetos
clean:
	rm -f $(OBJS)

# Limpia los archivos objetos y la librería
fclean: clean
	rm -f $(NAME)

# Limpia y recompila desde cero
re: fclean all

# Indica que "all", "clean", "fclean", "re" y "libft" no son nombres de archivos
.PHONY: all clean fclean re libft
