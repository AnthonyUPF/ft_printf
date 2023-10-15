/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:19:50 by anthtorr          #+#    #+#             */
/*   Updated: 2023/10/01 12:27:26 by anthtorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node != NULL)
	{
		new_node->content = content;
		new_node->next = NULL;
	}
	return (new_node);
}
/*
#include <stdio.h>

int main(void)
{
    char *content = "Hola, mundo!";
    t_list *new_node = ft_lstnew(content);
	printf("Contenido del nodo: %s\n", (char *)new_node->content);
    free(new_node);

    return 0;
}
*/
