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

void	ft_putfloat(double num)
{
	double			positive_num;
	unsigned int	integer_part;
	unsigned int	decimal_part;

	positive_num = num;
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		positive_num = -num;
	}
	integer_part = (unsigned int)positive_num;
	decimal_part = (unsigned int)((positive_num - integer_part) * 1000000);
	ft_putunbr(integer_part);
	ft_putchar_fd('.', 1);
	ft_putunbr(decimal_part);
}
