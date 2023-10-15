/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:35:56 by anthtorr          #+#    #+#             */
/*   Updated: 2023/10/05 14:56:15 by anthtorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_st_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	sub_len;
	char	*substr;
	size_t	i;

	s_len = ft_st_strlen(s);
	if (start >= s_len)
		return (ft_st_strdup(""));
	if (len < (s_len - start))
		sub_len = len;
	else
		sub_len = s_len - start;
	substr = malloc((sub_len + 1) * sizeof(char));
	if (substr != NULL)
	{
		i = 0;
		while (i < sub_len)
		{
			substr[i] = s[start + i];
			i++;
		}
		substr[i] = '\0';
	}
	return (substr);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main(void){
    const char *s = "Hello, World!";
    unsigned int start = 7;
    size_t len = 3;

    char *substr = ft_substr(s, start, len);

    printf("Resultado: %s\n", substr);

    free(substr); 

    return 0;
}
*/
