/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:30:09 by anthtorr          #+#    #+#             */
/*   Updated: 2023/09/30 19:32:43 by anthtorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
#include <stdio.h>
#include <ctype.h>

void modify_char(unsigned int i, char *c)
{
    if (i % 2 == 0)
        *c = toupper(*c);
}

int main(void)
{
    char s[] = "hello, world!";

    ft_striteri(s, modify_char);

    printf("Resultado: %s\n", s);

    return 0;
}
*/
