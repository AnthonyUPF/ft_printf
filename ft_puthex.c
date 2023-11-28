/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:50:55 by anthtorr          #+#    #+#             */
/*   Updated: 2023/11/24 13:58:36 by anthtorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 'A');
	return (c);
}

int	ft_puthex(unsigned long num, int uppercase)
{
	char	hex_char;
	int		count;
	int		temp;

	count = 0;
	if (num > 15)
	{
		temp = ft_puthex(num / 16, uppercase);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	hex_char = "0123456789abcdef"[num % 16];
	if (uppercase)
		hex_char = ft_toupper(hex_char);
	if (ft_putchar(hex_char) == -1)
		return (-1);
	return (++count);
}
