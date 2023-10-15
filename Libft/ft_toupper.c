/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:21:27 by anthtorr          #+#    #+#             */
/*   Updated: 2023/09/28 12:29:07 by anthtorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 'A');
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>

int main() {
    char c = 'a';
    char result = ft_toupper(c);
    char original_result = toupper(c);
    
    printf("Resultado de ft_toupper: %c\n", result);
    printf("Resultado de toupper: %c\n", original_result);

    return 0;
}
*/
