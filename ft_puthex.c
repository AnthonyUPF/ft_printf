/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:50:55 by anthtorr          #+#    #+#             */
/*   Updated: 2023/11/23 18:43:33 by anthtorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int num, char *base)
{
	int	count;
	int	temp;

	count = 0;
	if (num >= 16)
	{
		temp = ft_puthex(num / 16, base);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	if (ft_putchar(base[num % 16]) != 1)
		return (-1);
	return (++count);
}
