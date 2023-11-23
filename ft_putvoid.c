/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:52:54 by anthtorr          #+#    #+#             */
/*   Updated: 2023/11/23 16:52:56 by anthtorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putvoid(unsigned long v)
{
	int	i;

	i = 0;
	if (v >= 16)
		i += ft_putvoid (v / 16);
	if (write(1, &"0123456789abcdef"[v % 16], 1) == -1)
		return (-1);
	i++;
	return (i);
}
