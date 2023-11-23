/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:01:20 by anthtorr          #+#    #+#             */
/*   Updated: 2023/11/23 20:22:23 by anthtorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putnbr(int num)
{
	int	count;
	int	temp;
	
	count = 0;
	if (num == -2147483648)
    {
        if (write(1, "-2147483648", 11) != 11)
            return (-1);
        return (11);
    }
    else if (num < 0)
    {
        if (write(1, "-", 1) == -1)
            return (-1);
        num = -num;
        count++;
    }
	if (num > 9)
	{
		temp = ft_putnbr(num / 10);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	if (ft_putchar((num % 10) + '0') != 1)
		return (-1);
	return (++count);
}
