/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:41:37 by anthtorr          #+#    #+#             */
/*   Updated: 2023/11/18 19:40:23 by anthtorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(const char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}
/*
int main(void)
{
    char *s = "Hello, World!\n";
    int fd = 1; 

    ft_putstr_fd(s, fd);

    return 0;
}
*/
