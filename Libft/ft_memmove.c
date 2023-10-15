/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:31:25 by anthtorr          #+#    #+#             */
/*   Updated: 2023/10/03 15:06:58 by anthtorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_st_memcpy(void *restrict d, const void *restrict s, size_t n)
{
	char		*tmp_dst;
	const char	*tmp_src;

	tmp_dst = d;
	tmp_src = s;
	while (n--)
		*tmp_dst++ = *tmp_src++;
	return (d);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*tmp_dst;
	const unsigned char	*tmp_src;

	tmp_dst = dst;
	tmp_src = src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst <= src || tmp_dst >= (tmp_src + len))
	{
		return (ft_st_memcpy(dst, src, len));
	}
	else
	{
		tmp_dst += len;
		tmp_src += len;
		while (len--)
			*(--tmp_dst) = *(--tmp_src);
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
    const char str[15] = "Hello World!";
	char dest1[15];
	char dest2[15];
    ft_memmove(dest1, str, sizeof(str));
   	printf("ft_memmove: %s\n", dest1); 
    memmove(dest2, str, sizeof(str));
    printf("memmove: %s\n", dest1);
   	return 0;
}
*/
