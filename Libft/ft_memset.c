/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:00:41 by anthtorr          #+#    #+#             */
/*   Updated: 2023/09/21 16:53:15 by anthtorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp;

	temp = (unsigned char *) b;
	while (len--)
		*temp++ = (unsigned char) c;
	return (b);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
    char str[10];
    ft_memset(str, 'A', 5);
    printf("ft_memset: %s\n", str);
    memset(str, 'B', 5);
    printf("memset: %s\n", str);
    return (0);
}
*/
