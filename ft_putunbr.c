/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:00:04 by anthtorr          #+#    #+#             */
/*   Updated: 2023/11/23 18:53:22 by anthtorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int num)
{
	int	count;
	int	temp;

	count = 0;
	if (num > 9)
	{
		temp = ft_putunbr(num / 10);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	if (ft_putchar((num % 10) + '0') == -1)
		return (-1);
	return (++count);
}
