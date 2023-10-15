/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:57:45 by anthtorr          #+#    #+#             */
/*   Updated: 2023/09/30 15:45:28 by anthtorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
    char *str = "Hello world!";
    printf("ft_strlen: %lu\n", ft_strlen(str));
    printf("strlen: %lu\n", strlen(str));
    return 0;
}
*/
