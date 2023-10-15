/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:50:01 by anthtorr          #+#    #+#             */
/*   Updated: 2023/10/03 15:17:48 by anthtorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main() {
    const char str1[] = "Hello, world!";
    const char str2[] = "Hello, folks!";
    size_t n = 9;

    int result = ft_strncmp(str1, str2, n);
    int original_result = strncmp(str1, str2, n);

    printf("Resultado de ft_strncmp: %d\n", result);
    printf("Resultado de strncmp: %d\n", original_result);

    return 0;
}
*/
