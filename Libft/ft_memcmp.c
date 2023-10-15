/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:17:42 by anthtorr          #+#    #+#             */
/*   Updated: 2023/09/28 19:20:16 by anthtorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = s1;
	p2 = s2;
	while (n--)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main() {
    const char str1[] = "Hello, world!";
    const char str2[] = "Hello, folks!";
    size_t num = 9;

    int result = ft_memcmp(str1, str2, num);
    int original_result = memcmp(str1, str2, num);

    printf("Resultado de ft_memcmp: %d\n", result);
    printf("Resultado de memcmp: %d\n", original_result);

    return 0;
}
*/
