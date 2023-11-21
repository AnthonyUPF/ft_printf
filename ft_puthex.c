/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prinft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:33:07 by anthtorr          #+#    #+#             */
/*   Updated: 2023/11/20 21:56:22 by anthtorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned long num, int uppercase)
{
	char	*hex_digits;
	char	hex_char;

	if (num == 0)
	{
		ft_putchar_fd('0', 1);
		return ;
	}
	if (num / 16 != 0)
		ft_puthex(num / 16, uppercase);
	hex_digits = "0123456789abcdef";
	hex_char = hex_digits[num % 16];
	if (uppercase)
		hex_char = ft_toupper(hex_char);
	ft_putchar_fd(hex_char, 1);
}
