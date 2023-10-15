/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:22:52 by anthtorr          #+#    #+#             */
/*   Updated: 2023/10/05 14:47:11 by anthtorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsz)
{
	size_t	len;

	len = 0;
	while (src[len] && len + 1 < dstsz)
	{
		dst[len] = src[len];
		len++;
	}
	if (dstsz > 0)
		dst[len] = '\0';
	while (src[len])
		len++;
	return (len);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
    char src[10] = "Hello";
    char dst1[5];
    char dst2[5];
    printf("ft_strlcpy: %zu\n", ft_strlcpy(dst1,src,sizeof(dst1)));
    printf("strlcpy: %zu\n", strlcpy(dst2,src,sizeof(dst2)));
    return 0;
}
*/
