/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:05:19 by anthtorr          #+#    #+#             */
/*   Updated: 2023/09/30 15:13:45 by anthtorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_st_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*copy;

	copy = malloc((n + 1) * sizeof(char));
	if (copy != NULL)
	{
		i = 0;
		while (i < n)
		{
			copy[i] = s[i];
			i++;
		}
		copy[n] = '\0';
	}
	return (copy);
}

static int	ft_st_count_substr(const char *s, char c)
{
	int	count;
	int	in_substring;

	count = 0;
	in_substring = 0;
	while (*s)
	{
		if (*s == c)
			in_substring = 0;
		else if (!in_substring)
		{
			in_substring = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static void	ft_st_fill_result(char **r, const char *s, char c, int num_substr)
{
	int			i;
	const char	*start;
	size_t		len;

	i = 0;
	while (i < num_substr)
	{
		while (*s == c)
			s++;
		start = s;
		while (*s && *s != c)
			s++;
		len = s - start;
		r[i] = ft_st_strndup(start, len);
		i++;
	}
	r[num_substr] = NULL;
}

char	**ft_split(char const *s, char c)
{
	int			num_substr;
	char		**result;

	num_substr = ft_st_count_substr(s, c);
	result = malloc((num_substr + 1) * sizeof(char *));
	if (result != NULL)
	{
		ft_st_fill_result(result, s, c, num_substr);
	}
	return (result);
}
/*
#include <stdio.h>

int main(void) {
    const char *s = "Hello,World,How,Are,You";
    char c = ',';

    char **result = ft_split(s, c);

    if (result) {
        int i = 0;
        while (result[i]) {
            printf("%s\n", result[i]);
            free(result[i]);
            i++;
        }
        free(result);
    }

    return 0;
}
*/
