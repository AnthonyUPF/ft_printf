/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:01:20 by anthtorr          #+#    #+#             */
/*   Updated: 2023/11/24 14:50:54 by anthtorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int num)
{
	int	count;
	int	temp;

	count = 0;
	if (num < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		num = -num;
		count++;
	}
	temp = ft_putunbr(num);
	if (temp == -1)
		return (-1);
	count += temp;
	return (count);
}
