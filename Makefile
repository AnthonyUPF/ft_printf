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

# Output file name
NAME = libftprintf.a

# Header file
HEADERS = ft_printf.h

# List of mandatory source files
SRCS = ft_printf.c ft_putchar.c ft_putstr.c ft_puthex.c ft_putnbr.c ft_putunbr.c

# Generate a list of objects from source files
OBJS = $(SRCS:.c=.o)

# Compilation options
CC = gcc
CFLAGS = -Wall -Werror -Wextra

# Rule to build the library
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Rule to build object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Default rule
all: $(NAME)

# Rule to clean object files
clean:
	rm -f $(OBJS)

# Rule to clean object files and the library
fclean: clean
	rm -f $(NAME)

# Rule to recompile everything from scratch
re:	fclean all

# Indicates that "all", "clean", "fclean", "re" are not file names
.PHONY: all clean fclean re
