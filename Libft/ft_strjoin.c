/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:31:50 by anthtorr          #+#    #+#             */
/*   Updated: 2023/09/30 15:59:12 by anthtorr         ###   ########.fr       */
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

static char	*ft_st_strdup(const char *s1)
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

static char	*ft_st_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*ft_st_strcat(char *dest, const char *src)
{
	size_t	dest_len;
	size_t	i;

	dest_len = ft_st_strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_st_strdup(s2));
	else if (!s2)
		return (ft_st_strdup(s1));
	len1 = ft_st_strlen(s1);
	len2 = ft_st_strlen(s2);
	result = malloc((len1 + len2 + 1) * sizeof(char));
	if (result != NULL)
	{
		ft_st_strcpy(result, s1);
		ft_st_strcat(result + len1, s2);
	}
	return (result);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const char *s1 = "Hello, ";
    const char *s2 = "World!";
    
    char *concatenated = ft_strjoin(s1, s2);

    if (concatenated) {
        printf("Resultado: %s\n", concatenated);
        free(concatenated); // Liberamos la memoria asignada
    } else {
        printf("Error al concatenar strings\n");
    }

    return 0;
}
*/
