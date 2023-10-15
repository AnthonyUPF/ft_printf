/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:39:30 by anthtorr          #+#    #+#             */
/*   Updated: 2023/09/30 15:11:00 by anthtorr         ###   ########.fr       */
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

static char	*ft_st_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

static void	ft_st_indices(char const *s1, char const *st, size_t *s, size_t *e)
{
	*s = 0;
	*e = ft_st_strlen(s1);
	while (ft_st_strchr(st, s1[*s]) != NULL)
		(*s)++;
	while (*e > *s && ft_st_strchr(st, s1[*e - 1]) != NULL)
		(*e)--;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	new_len;
	char	*result;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	ft_st_indices(s1, set, &start, &end);
	new_len = end - start;
	result = malloc((new_len + 1) * sizeof(char));
	if (result != NULL)
	{
		i = 0;
		while (i < new_len)
		{
			result[i] = s1[start + i];
			i++;
		}
		result[i] = '\0';
	}
	return (result);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const char *s1 = "   Hello, World!   ";
    const char *set = " ";

    char *trimmed = ft_strtrim(s1, set);

    if (trimmed) {
        printf("Resultado: %s\n", trimmed);
        free(trimmed);
    } else {
        printf("Error al recortar la string\n");
    }

    return 0;
}
*/
