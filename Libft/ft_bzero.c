/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:24:18 by anthtorr          #+#    #+#             */
/*   Updated: 2023/09/28 11:11:51 by anthtorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_st_memset(void *b, int c, size_t len)
{
	unsigned char	*temp;

	temp = (unsigned char *) b;
	while (len--)
		*temp++ = (unsigned char) c;
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_st_memset(s, 0, n);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
    char str[10];
    ft_bzero(str, sizeof(str));
    
	printf("ft_bzero: ");
	for (int i = 0; i < 10; i++) {
        printf("%d ", str[i]);
    }
    printf("\n");

    bzero(str, sizeof(str));

    printf("bzero: ");
	for (int i = 0; i < 10; i++) {
        printf("%d ", str[i]);
    }
    printf("\n");

    return 0;
}
*/
