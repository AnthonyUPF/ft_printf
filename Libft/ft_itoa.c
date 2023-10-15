/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:55:00 by anthtorr          #+#    #+#             */
/*   Updated: 2023/10/05 14:56:30 by anthtorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_st_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

static char	*ft_st_strdup(const char *s1)
{
	size_t		len;
	const char	*p;
	char		*new_str;
	char		*dst;

	p = s1;
	len = ft_st_strlen(p);
	new_str = malloc((len + 1) * sizeof(char));
	if (new_str != NULL)
	{
		dst = new_str;
		while (*p != '\0')
			*dst++ = *p++;
		*dst = '\0';
	}
	return (new_str);
}

static int	ft_st_num_len(int n)
{
	int	len;

	len = 1;
	if (n != 0)
	{
		len = 0;
		while (n != 0)
		{
			n /= 10;
			len++;
		}
	}
	return (len);
}

static void	ft_st_fill_str(char *str, int n, int len, int sign)
{
	str[len--] = '\0';
	if (n == 0)
		str[len--] = '0';
	while (n != 0)
	{
		str[len--] = (n % 10) + '0';
		n = n / 10;
	}
	if (sign)
		str[0] = '-';
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;

	if (n == -2147483648)
		return (ft_st_strdup("-2147483648"));
	len = ft_st_num_len(n);
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n = -n;
		len++;
	}
	str = malloc((len + 1) * sizeof(char));
	if (str != NULL)
	{
		ft_st_fill_str(str, n, len, sign);
	}
	return (str);
}
/*
#include <stdio.h>

int main(void) {
    int n = -214748364;

    char *str = ft_itoa(n);

    if (str) {
        printf("Resultado: %s\n", str);
        free(str);
    }

    return 0;
}
*/
