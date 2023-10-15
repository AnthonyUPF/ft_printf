/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:24:05 by anthtorr          #+#    #+#             */
/*   Updated: 2023/09/28 12:27:22 by anthtorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 'a');
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>

int main() {
    char c = 'A';
    char result = ft_tolower(c);
    char original_result = tolower(c);
    
    printf("Resultado de ft_tolower: %c\n", result);
    printf("Resultado de tolower: %c\n", original_result);

    return 0;
}
*/
