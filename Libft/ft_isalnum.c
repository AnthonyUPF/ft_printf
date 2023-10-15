/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:38:39 by anthtorr          #+#    #+#             */
/*   Updated: 2023/09/28 11:09:15 by anthtorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_st_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

static int	ft_st_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isalnum(int c)
{
	return (ft_st_isalpha(c) || ft_st_isdigit(c));
}
/*
#include <stdio.h>
#include <ctype.h>

int main()
{
    char c = '7';
    printf("ft_isalnum: %d\n", ft_isalnum(c));
    printf("isalnum: %d\n", isalnum(c));
    return 0;
}
*/
