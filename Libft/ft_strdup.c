/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:16:19 by anthtorr          #+#    #+#             */
/*   Updated: 2023/09/30 15:05:07 by anthtorr         ###   ########.fr       */
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

char	*ft_strdup(const char *s1)
{
	size_t		len;
	const char	*p;
	char		*new_str;
	char		*dst;

	p = s1;
	len = ft_st_strlen(p);
	new_str = malloc((len + 1) * sizeof(char));
	if (new_str != NULL)
	{
		dst = new_str;
		while (*p != '\0')
			*dst++ = *p++;
		*dst = '\0';
	}
	return (new_str);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    const char str[] = "Hello, world!";
    char *result = ft_strdup(str);

    if (result != NULL) {
        printf("ft_strdup: %s\n", result);
        free(result);
    } else {
        printf("La asignación de memoria con ft_strdup falló.\n");
    }

    char *original_result = strdup(str);

    if (original_result != NULL) {
        printf("strdup: %s\n", original_result);
        free(original_result);
    } else {
        printf("La asignación de memoria con strdup falló.\n");
    }

    return 0;
}
*/
