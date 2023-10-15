/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:41:21 by anthtorr          #+#    #+#             */
/*   Updated: 2023/10/05 15:14:04 by anthtorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last_occurrence;

	last_occurrence = NULL;
	while (*s)
	{
		if (*s == (char) c)
			last_occurrence = s;
		s++;
	}
	if (*s == (char) c)
		return ((char *) s);
	return ((char *) last_occurrence);
}
/*
#include <stdio.h>
#include <string.h>

int main() {
    const char str[] = "Hello, world!";
    int c = 'o';
    char* result = ft_strrchr(str, c);
    char* original_result = strrchr(str, c);

    if (result != NULL) {
        printf("Resultado de ft_strrchr: %s\n", result);
    } else {
        printf("El caracter no se encontró en la cadena.\n");
    }

    if (original_result != NULL) {
        printf("Resultado de strrchr: %s\n", original_result);
    } else {
        printf("El caracter no se encontró en la cadena (original).\n");
    }

    return 0;
}
*/
