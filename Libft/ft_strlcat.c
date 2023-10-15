/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:33:08 by anthtorr          #+#    #+#             */
/*   Updated: 2023/10/03 17:11:28 by anthtorr         ###   ########.fr       */
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

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsz)
{
	unsigned int	i;
	size_t			len_s;
	size_t			len_d;

	len_d = ft_st_strlen(dst);
	len_s = ft_st_strlen(src);
	if (len_d >= dstsz)
		return (len_s + dstsz);
	i = 0;
	while (src[i] && i < dstsz - len_d)
	{
		dst[i + len_d] = src[i];
		i++;
	}
	if (i + len_d < dstsz)
		dst[i + len_d] = '\0';
	else
		dst[i + len_d - 1] = '\0';
	return (len_d + len_s);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
    char dst1[10] = "Hello";
    char dst2[10] = "Hello";
    char src[5] = "World";
	size_t len1 = ft_strlcat(dst1, src, sizeof(dst1));
	size_t len2 = strlcat(dst2, src, sizeof(dst2));
    printf("ft_strlcat: %s, len: %zu\n", dst1, len1);
    printf("strlcat: %s, len: %zu\n",  dst2, len2);
    return 0;
}
*/
