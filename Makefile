# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 16:53:56 by anthtorr          #+#    #+#              #
#    Updated: 2023/11/23 20:51:54 by anthtorr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

HEADER	= ft_printf.h

INCLUDE = -I./

SRCS	= ft_printf.c ft_putchar.c ft_putstr.c ft_puthex.c ft_putnbr.c ft_putunbr.c 

OBJS	= ${SRCS:.c=.o}

DEPS	= $(addsuffix .d, $(basename ${OBJS}))

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

%.o: %.c Makefile
	${CC} -MT $@ ${CFLAGS} -MMD -MP ${INCLUDE} -c $< -o $@

all:	${NAME}

${NAME}: ${OBJS}
	ar src ${NAME} ${OBJS}

-include	${DEPS}

clean: 
			rm -rf ${OBJS} ${DEPS}
			
fclean:		clean
			rm -rf ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
