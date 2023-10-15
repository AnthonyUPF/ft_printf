/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:51:29 by anthtorr          #+#    #+#             */
/*   Updated: 2023/09/30 19:29:47 by anthtorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_st_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_str;

	if (s == NULL || f == NULL)
		return (NULL);
	new_str = malloc((ft_st_strlen(s) + 1) * sizeof(char));
	if (new_str != NULL)
	{
		i = 0;
		while (s[i] != '\0')
		{
			new_str[i] = f(i, s[i]);
			i++;
		}
		new_str[i] = '\0';
	}
	return (new_str);
}
/*
#include <stdio.h>
#include <ctype.h>

char modify_char(unsigned int i, char c)
{
	if (i % 2 == 0)
		return c;
	return toupper(c);
}

int main(void)
{
	const char *s = "hello, world!";
	
	char *result = ft_strmapi(s, modify_char);

	if (result)
	{
		printf("Resultado: %s\n", result);
		free(result);
	}

	return 0;
}
*/
