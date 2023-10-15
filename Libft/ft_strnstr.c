/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:38:11 by anthtorr          #+#    #+#             */
/*   Updated: 2023/09/28 19:40:06 by anthtorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_st_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

static int	ft_st_memcmp(const void *s1, const void *s2, size_t n)
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

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	int		st_memcmp;		

	needle_len = ft_st_strlen(needle);
	if (needle_len == 0)
		return ((char *) haystack);
	while (*haystack && len >= needle_len)
	{
		st_memcmp = ft_st_memcmp(haystack, needle, needle_len);
		if (*haystack == *needle && st_memcmp == 0)
			return ((char *) haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int main() {
    const char haystack[] = "Hello, world!";
    const char needle[] = "world";
    size_t len = strlen(haystack);

    char* result = ft_strnstr(haystack, needle, len);
    char* original_result = strnstr(haystack, needle, len);

    if (result != NULL) {
        printf("Resultado de ft_strnstr: %s\n", result);
    } else {
        printf("La subcadena no se encontró en la cadena.\n");
    }

    if (original_result != NULL) {
        printf("Resultado de strnstr: %s\n", original_result);
    } else {
        printf("La subcadena no se encontró en la cadena (original).\n");
    }

    return 0;
}
*/
