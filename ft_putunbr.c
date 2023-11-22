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

void	ft_putunbr(unsigned int num, int *count)
{
	if (num == 0)
	{
		ft_putchar_fd('0', 1);
		*count += 1;
		return ;
	}
	if (num / 10 != 0)
		ft_putunbr(num / 10, count);
	ft_putchar_fd((num % 10) + '0', 1);
	*count += 1;
}
