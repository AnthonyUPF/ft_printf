# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 14:58:01 by anthtorr          #+#    #+#              #
#    Updated: 2023/11/18 19:44:41 by anthtorr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre de programa
NAME = libftprintf.a

# Fuentes de tu proyecto
SRCS = ft_puthex.c ft_putunbr.c ft_putfloat.c ft_printf.c

# Archivos objetos generados a partir de los fuentes
OBJS = $(SRCS:.c=.o)

# Opciones de compilación
CC = gcc
CFLAGS = -Wall -Werror -Wextra

# Directorios donde se encuentran los archivos de encabezado
INCLUDES = -I includes -I Libft/

# Librerías necesarias
LIBFT = libft.a
LIBFT_PATH = Libft

# Regla por defecto
all: libft $(NAME)

# Compila la librería libft
libft:
	$(MAKE) -C $(LIBFT_PATH)

# Compila los objetos a partir de los fuentes
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compila la librería libftprintf.a y el programa final
$(NAME): libft $(OBJS)
	cp $(LIBFT_PATH)/$(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

# Limpia los archivos objetos y la librería
clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean

# Limpia los archivos objetos, la librería y el programa final
fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

# Limpia y recompila desde cero
re: fclean all

# Indica que "all", "clean", "fclean", "re" y "libft" no son nombres de archivos
.PHONY: all clean fclean re libft

