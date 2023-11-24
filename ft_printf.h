/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:48:51 by anthtorr          #+#    #+#             */
/*   Updated: 2023/11/24 13:54:32 by anthtorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(char const *str, ...);
int	ft_putchar(const char c);
int	ft_putstr(const char *str);
int	ft_putnbr(int num);
int	ft_putunbr(unsigned int num);
int	ft_puthex(unsigned long num, int uppercase);

#endif
